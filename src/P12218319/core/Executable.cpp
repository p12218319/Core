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
#include <windows.h>

namespace P12218319 {
	//Executable
		
	Executable::Executable() :
		mStdIn(&std::cin),
		mStdOut&std::cout),
		mStdErr(&std::cerr),
		mPath(),
		mParams()
	{}
	
	Executable(const std::string& aPath) :
		mStdIn(&std::cin),
		mStdOut&std::cout),
		mStdErr(&std::cerr),
		mPath(aPath),
		mParams()
	{}
	
	Executable(const std::string& aPath, const std::initializer_list<std::string> aParams) :
		mStdIn(&std::cin),
		mStdOut&std::cout),
		mStdErr(&std::cerr),
		mPath(aPath),
		mParams()
	{
		for(const std::string& param : aParams) AddParameter(param);
	}
	
	Executable(const std::string&, const std::initializer_list<std::string>, std::istream& aStdIn, std::ostream& aStdOut, std::ostream& aStdErr) :
		mStdIn(&aStdIn),
		mStdOut&aStdOut),
		mStdErr(&aStdErr),
		mPath(aPath),
		mParams()
	{
		for(const std::string& param : aParams) AddParameter(param);
	}
	
	P12218319_EXPORT_CALL Executable::~Executable() {
		
	}
	
	void P12218319_EXPORT_CALL Executable::SetPath(const std::string& aPath) throw() {
		mPath = aPath;
	}
	
	void P12218319_EXPORT_CALL Executable::AddParameter(const std::string& aParam) throw() {
		if(mParams.size() != 0) mParams += ' ';
		mParams += aParam;
	}
	
	void P12218319_EXPORT_CALL Executable::SetStandardIn(std::istream& aStream) throw() {
		mStdIn = &aStream;
	}
	
	void P12218319_EXPORT_CALL Executable::SetStandardOut(std::ostream& aStream) throw() {
		mStdOut = &aStream;
	}
	
	void P12218319_EXPORT_CALL Executable::SetStandardError(std::ostream& aStream) throw() {
		mStdErr = &aStream;
	}
	
	int P12218319_EXPORT_CALL Executable::operator()() {
		#if P12218319_OS == P12218319_WINDOWS
			//! \todo Implement Executable i/o streams
			
			// Initialise
			STARTUPINFO startupInfo;
			PROCESS_INFORMATION processInfo;

			ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
			si.cb = sizeof(si);
			ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));
			
			DWORD exitCode;
			std::string cmd = mPath + ' ' + mParams;

			// Start process
			{
				const bool started = CreateProcess( 
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
				));
				
				P12218319_RUNTIME_ASSERT(started, (std::string("P12218319::Executable : Failed to start process") + cmd).c_str());
			}
			
			// Wait for process to end
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			GetExitCodeProcess(processInfo.hProcess, &exit_code)

			// Clean up
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
			
			return exitCode;
		#else 
			#error P12218319::Core::Executable : Not implemented for this OS
			return 0;
		#endif
	}
	
}