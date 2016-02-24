/*
	Copyright 2016 Adam Smith - P12218319

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
   email : p12218319@myemail.dmu.ac.uk
*/
#include "P12218319/core/Executable.hpp"
#include <string>
#include <windows.h>

namespace P12218319 {
	//Executable
		
	P12218319_CALL Executable::Executable() :
		mStdIn(&std::cin),
		mStdOut(&std::cout),
		mStdErr(&std::cerr),
		mPath(),
		mParams()
	{}
	
	P12218319_CALL Executable::Executable(const std::string& aPath) :
		mStdIn(&std::cin),
		mStdOut(&std::cout),
		mStdErr(&std::cerr),
		mPath(aPath),
		mParams()
	{}
	
	P12218319_CALL Executable::Executable(const std::string& aPath, const std::initializer_list<std::string> aParams) :
		mStdIn(&std::cin),
		mStdOut(&std::cout),
		mStdErr(&std::cerr),
		mPath(aPath),
		mParams()
	{
		for(const std::string& param : aParams) AddParameter(param);
	}
	
	P12218319_CALL Executable::Executable(const std::string& aPath, const std::initializer_list<std::string> aParams, std::istream& aStdIn, std::ostream& aStdOut, std::ostream& aStdErr) :
		mStdIn(&aStdIn),
		mStdOut(&aStdOut),
		mStdErr(&aStdErr),
		mPath(aPath),
		mParams()
	{
		for(const std::string& param : aParams) AddParameter(param);
	}
	
	P12218319_CALL Executable::~Executable() {
		
	}
	
	void P12218319_CALL Executable::SetPath(const std::string& aPath) throw() {
		mPath = aPath;
	}
	
	void P12218319_CALL Executable::AddParameter(const std::string& aParam) throw() {
		if(mParams.size() != 0) mParams += ' ';
		mParams += aParam;
	}
	
	void P12218319_CALL Executable::SetStandardIn(std::istream& aStream) throw() {
		mStdIn = &aStream;
	}
	
	void P12218319_CALL Executable::SetStandardOut(std::ostream& aStream) throw() {
		mStdOut = &aStream;
	}
	
	void P12218319_CALL Executable::SetStandardError(std::ostream& aStream) throw() {
		mStdErr = &aStream;
	}
	
	int P12218319_CALL Executable::operator()() {
		#if P12218319_OS == P12218319_WINDOWS
			//! \todo Implement Executable i/o streams
			
			// Initialise
			enum {BUFFER_SIZE = 1024};
			uint8_t buffer[BUFFER_SIZE];
			HANDLE stdInRead = NULL;
			HANDLE stdInWrite = NULL;
			HANDLE stdOutRead = NULL;
			HANDLE stdOutWrite = NULL;
			HANDLE stdErrRead = NULL;
			HANDLE stdErrWrite = NULL;
			SECURITY_ATTRIBUTES attributes;
			STARTUPINFOA startupInfo;
			PROCESS_INFORMATION processInfo;

			ZeroMemory(&startupInfo, sizeof(STARTUPINFOA));
			startupInfo.cb = sizeof(STARTUPINFOA);
			startupInfo.hStdError = stdErrWrite;
			startupInfo.hStdOutput = stdOutWrite;
			startupInfo.hStdInput = stdInRead;
			startupInfo.dwFlags |= STARTF_USESTDHANDLES;
			ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));
			ZeroMemory(&attributes, sizeof(SECURITY_ATTRIBUTES));
			attributes.nLength = sizeof(SECURITY_ATTRIBUTES);
			attributes.bInheritHandle = TRUE;
			attributes.lpSecurityDescriptor = NULL;

			// Redirect i/o
			
			if(! CreatePipe(&stdErrRead, &stdErrWrite, &attributes, 0)) throw std::runtime_error("P12218319::Executable : Failed to create pipe stderr");
			//if(! SetHandleInformation(&stdErrRead, HANDLE_FLAG_INHERIT, 0)) throw std::runtime_error("P12218319::Executable : Failed to pipe stderr");

			if(! CreatePipe(&stdOutRead, &stdOutWrite, &attributes, 0)) throw std::runtime_error("P12218319::Executable : Failed to create pipe stdout");
			//if(! SetHandleInformation(&stdOutRead, HANDLE_FLAG_INHERIT, 0)) throw std::runtime_error("P12218319::Executable : Failed to pipe stdout");

			if(! CreatePipe(&stdInRead, &stdInWrite, &attributes, 0)) throw std::runtime_error("P12218319::Executable : Failed to create pipe stdin");
			//if(! SetHandleInformation(&stdInWrite, HANDLE_FLAG_INHERIT, 0)) throw std::runtime_error("P12218319::Executable : Failed to pipe stdin");

			// Write data to stdin
			/*{
				DWORD bytestoWrite = 0;
				DWORD bytesWritten = 0;
				while(! mStdIn->eof()) {
					*mStdIn >> buffer[bytestoWrite++];
					if(bytestoWrite == BUFFER_SIZE) {
						bytestoWrite = 0;
						if(! WriteFile(stdInWrite, buffer, BUFFER_SIZE, &bytesWritten, NULL)) throw std::runtime_error("P12218319::Executable : Failed to write to stdin");
					}
				}
				if(bytestoWrite > 0) {
					if (!WriteFile(stdInWrite, buffer, bytestoWrite, &bytesWritten, NULL)) throw std::runtime_error("P12218319::Executable : Failed to write to stdin");
				}
			}*/
			
			DWORD exitCode;
			std::string cmd = mPath + ' ' + mParams;

			// Start process
			{
				const bool started = CreateProcessA( 
					NULL,
					const_cast<char*>(cmd.c_str()),
					NULL,
					NULL,
					FALSE,
					0,
					NULL, 
					NULL,
					&startupInfo,
					&processInfo 
				);
				
				P12218319_RUNTIME_ASSERT(started, (std::string("P12218319::Executable : Failed to start process") + cmd).c_str());
			}
			
			// Wait for process to end
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			GetExitCodeProcess(processInfo.hProcess, &exitCode);

			/*{
				// Read data from stdout
				DWORD bytesRead = 0;
				do {
					if(! ReadFile(stdOutRead, buffer, BUFFER_SIZE, &bytesRead, NULL)) std::runtime_error("P12218319::Executable : Failed to read stdout");
					mStdOut->write(reinterpret_cast<char*>(buffer), bytesRead);
				} while(bytesRead != 0);
				mStdOut->write(reinterpret_cast<char*>(buffer), bytesRead);
			}
			{
				// Read data from stderr
				DWORD bytesRead = 0;
				do {
					if(! ReadFile(stdErrRead, buffer, BUFFER_SIZE, &bytesRead, NULL)) std::runtime_error("P12218319::Executable : Failed to read stderr");
					mStdOut->write(reinterpret_cast<char*>(buffer), bytesRead);
				} while (bytesRead != 0);
				mStdOut->write(reinterpret_cast<char*>(buffer), bytesRead);
			}*/

			// Clean up

			CloseHandle(stdInRead);
			CloseHandle(stdInWrite);
			CloseHandle(stdOutRead);
			CloseHandle(stdOutWrite);
			CloseHandle(stdErrRead);
			CloseHandle(stdErrWrite);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
			
			return exitCode;
		#else 
			#error P12218319::Core::Executable : Not implemented for this OS
			return 0;
		#endif
	}
	
}