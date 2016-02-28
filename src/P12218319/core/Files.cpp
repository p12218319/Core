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

#include "P12218319\core\Files.hpp"


#if P12218319_OS == P12218319_WINDOWS
	#include <Windows.h>
	#undef CreateFile
	#undef CreateDirectory
	#undef DeleteFile
	#undef GetCurrentDirectory
	#undef GetFileAttributes

	namespace P12218319 { namespace files {
		uint32_t P12218319_CALL GetFileSize(const std::string& aPath) throw() {
			const HANDLE handle = CreateFileA(
				aPath.c_str(),
				0,
				0,
				NULL,
				OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL,
				NULL
			);

			if(handle == INVALID_HANDLE_VALUE) return 0;
			const DWORD size = ::GetFileSize(handle, NULL);
			CloseHandle(handle);
			return size;
		}

		uint32_t P12218319_CALL GetFileAttributes(const std::string& aPath) throw() {
			const DWORD winAttributes = GetFileAttributesA(aPath.c_str());
			if(winAttributes == INVALID_FILE_ATTRIBUTES) return 0;
			
			if(winAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				return 
					EXISTS | 
					IS_DIRECTORY;
			}else {
				return
					EXISTS |
					IS_DIRECTORY |
					(winAttributes & FILE_ATTRIBUTE_READONLY ? IS_READABLE : IS_READ_WRITEABLE);
			}
		}

		bool P12218319_CALL CreateFile(const std::string& aPath, const uint32_t aAttributes) throw() {
			const HANDLE handle = CreateFileA(
				aPath.c_str(),
				(aAttributes & IS_READABLE ? GENERIC_READ : 0) | (aAttributes & IS_READABLE ? GENERIC_WRITE : 0),
				0,
				NULL,
				CREATE_NEW,
				FILE_ATTRIBUTE_NORMAL,
				NULL
			);

			if(handle == INVALID_HANDLE_VALUE) return false;
			CloseHandle(handle);
			return true;
		}

		bool P12218319_CALL CreateDirectory(const std::string& aPath) throw() {
			const HANDLE handle = CreateFileA(
				aPath.c_str(),
				GENERIC_READ | GENERIC_WRITE,
				0,
				NULL,
				CREATE_NEW,
				FILE_ATTRIBUTE_NORMAL,
				NULL
			);

			if(handle == INVALID_HANDLE_VALUE) return false;
			CloseHandle(handle);
			return true;
		}

		bool P12218319_CALL DeleteFile(const std::string& aPath) throw() {
			return DeleteFileA(aPath.c_str()) != 0;
		}

		bool P12218319_CALL DeleteDirectory(const std::string& aPath) throw() {
			return RemoveDirectoryA(aPath.c_str()) != 0;
		}

		bool P12218319_CALL DeleteDirectoryRecursive(const std::string& aPath) throw() {
			const std::vector<std::string> children = ListChildren(aPath);
			for(const std::string& i : children) {
				const uint32_t attributes = GetFileAttributes(i);
				if(attributes & IS_FILE) {
					if(! DeleteFile(i)) return false;
				}else if (attributes & IS_DIRECTORY) {
					if(! DeleteDirectoryRecursive(i)) return false;
				}else {
					return false;
				}
			}
			return DeleteDirectory(aPath);
		}

		void P12218319_CALL Move(const std::string& aOldPath, const std::string& aNewPath) {
			if(MoveFileA(aOldPath.c_str(), aNewPath.c_str()) == 0) throw std::runtime_error(std::string("Could not move file ") + aOldPath + std::string(" to ") + aNewPath);
		}

		void P12218319_CALL Copy(const std::string& aOldPath, const std::string& aNewPath) {
			if(CopyFileA(aOldPath.c_str(), aNewPath.c_str(), TRUE) == 0) throw std::runtime_error(std::string("Could not copy file ") + aOldPath + std::string(" to ") + aNewPath);
		}

		void P12218319_CALL Rename(const std::string& aOldPath, const std::string& aNewPath) {
			Copy(aOldPath, aNewPath);
			DeleteFile(aOldPath);
		}

		std::vector<std::string> P12218319_CALL ListChildren(const std::string&aPath) {
			std::vector<std::string> children;

			WIN32_FIND_DATAA findData;
			char pathBufffer[MAX_PATH];
			HANDLE handle = INVALID_HANDLE_VALUE;

			handle = FindFirstFileA(pathBufffer, &findData);
			if(INVALID_HANDLE_VALUE == handle) return children;
			do{
				children.push_back(std::string(findData.cFileName));
			}while(FindNextFileA(handle, &findData) != 0);
			FindClose(handle);

			return children;
		}

		std::string P12218319_CALL GetCurrentDirectory() throw() {
			char pathBufffer[MAX_PATH];
			GetCurrentDirectoryA(MAX_PATH, pathBufffer);
			return std::string(pathBufffer);
		}

		std::string P12218319_CALL GetTemporaryDirectory() throw() {
			char pathBufffer[MAX_PATH];
			GetTempPathA(MAX_PATH, pathBufffer);
			return std::string(pathBufffer);
		}

		std::string P12218319_CALL GetFileExtension(const std::string& aPath) throw() {
			return aPath.substr(aPath.find_last_of('.'));
		}

		std::string P12218319_CALL GetFileName(const std::string& aPath) throw() {
			const size_t begin = aPath.find_last_of('\\');
			return aPath.substr(begin == std::string::npos ? 0 : begin, aPath.find_last_of('.'));
		}

		std::string P12218319_CALL GetDirectoryName(const std::string& aPath) throw() {
			std::string tmp;
			const size_t end = aPath.find_last_of('\\');
			for(size_t i = end - 1; end != 0; --i) {
				const char c = aPath[i];
				if(c == '\\') break;
				tmp += c;
			}
			std::reverse(tmp.begin(), tmp.end());
			return tmp;
		}

		std::string P12218319_CALL GetParentDirectory(const std::string& aPath) throw() {
			size_t i = 0;
			size_t j = i;
			size_t k = j;

			while(true) {
				i = aPath.find_first_of('\\', i + 1);
				if(i == std::string::npos) break;
				k = j;
				j = i;
			}

			return aPath.substr(0, k +1);
		}

	}}
#endif