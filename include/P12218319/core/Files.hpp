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
#ifndef P12218319_CORE_FILES_HPP
#define P12218319_CORE_FILES_HPP

#include <vector>
#include "P12218319\core\Core.hpp"

namespace P12218319 { namespace files {
	
	enum {
		EXISTS				= 1,
		IS_READABLE			= 1 << 1,
		IS_WRITEABLE		= 1 << 2,
		IS_FILE				= 1 << 3,
		IS_DIRECTORY		= 1 << 4,

		IS_READ_WRITEABLE		= IS_READABLE | IS_WRITEABLE
	};

	P12218319_EXPORT_API uint32_t P12218319_CALL GetFileSize(const std::string&) throw();
	P12218319_EXPORT_API uint32_t P12218319_CALL GetFileAttributes(const std::string&) throw();
	P12218319_EXPORT_API bool P12218319_CALL CreateFile(const std::string&, const uint32_t) throw();
	P12218319_EXPORT_API bool P12218319_CALL CreateDirectory(const std::string&) throw();
	P12218319_EXPORT_API bool P12218319_CALL DeleteFile(const std::string&) throw();
	P12218319_EXPORT_API bool P12218319_CALL DeleteDirectory(const std::string&) throw();
	P12218319_EXPORT_API bool P12218319_CALL DeleteDirectoryRecursive(const std::string&) throw();
	P12218319_EXPORT_API void P12218319_CALL Move(const std::string&, const std::string&);
	P12218319_EXPORT_API void P12218319_CALL Copy(const std::string&, const std::string&);
	P12218319_EXPORT_API void P12218319_CALL Rename(const std::string&, const std::string&);
	P12218319_EXPORT_API std::vector<std::string> P12218319_CALL ListChildren(const std::string&);

	P12218319_EXPORT_API std::string P12218319_CALL GetCurrentDirectory() throw();
	P12218319_EXPORT_API std::string P12218319_CALL GetTemporaryDirectory() throw();

	P12218319_EXPORT_API std::string P12218319_CALL GetFileExtension(const std::string&) throw();
	P12218319_EXPORT_API std::string P12218319_CALL GetFileName(const std::string&) throw();
	P12218319_EXPORT_API std::string P12218319_CALL GetDirectoryName(const std::string&) throw();
	P12218319_EXPORT_API std::string P12218319_CALL GetParentDirectory(const std::string&) throw();
}}
#endif