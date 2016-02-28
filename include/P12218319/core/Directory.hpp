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
#ifndef P12218319_CORE_DIRECTORY_HPP
#define P12218319_CORE_DIRECTORY_HPP

#include <vector>
#include "P12218319\core\Core.hpp"

namespace P12218319 {

	class File;
	
	class P12218319_EXPORT_API Directory {
	private:
		std::string mPath;
		bool mExists;
	public:
		P12218319_CALL Directory(const std::string&);
		P12218319_CALL ~Directory();

		Directory P12218319_CALL GetParentDirectory() const;

		std::vector<File> P12218319_CALL GetChildFiles() const;
		std::vector<Directory> P12218319_CALL GetChildDirectories() const;

		bool P12218319_CALL Exists() const throw();
		bool P12218319_CALL Create() throw();
		bool P12218319_CALL Delete() throw();

		P12218319_CALL operator bool() const throw();
	};
}
#endif