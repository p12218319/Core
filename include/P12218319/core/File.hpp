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
#ifndef P12218319_CORE_FILE_HPP
#define P12218319_CORE_FILE_HPP

#include <string>
#include "P12218319\core\Core.hpp"

namespace P12218319 {
	class Directory;

	class P12218319_EXPORT_API File {
	private:
		std::string mPath;
		uint32_t mAttributes;
	public:
		P12218319_CALL File(const std::string&);
		P12218319_CALL ~File();

		Directory P12218319_CALL GetParentDirectory() const throw();

		bool P12218319_CALL IsReadable() const throw();
		bool P12218319_CALL IsWriteable() const throw();
		bool P12218319_CALL IsReadOnly() const throw();
		bool P12218319_CALL IsWriteOnly() const throw();
		bool P12218319_CALL IsReadWrite() const throw();
		bool P12218319_CALL Exists() const throw();
		uint32_t P12218319_CALL Size() const throw();

		File P12218319_CALL Copy(const std::string&) const;
		bool P12218319_CALL Move(const std::string&);
		bool P12218319_CALL Rename(const std::string&);

		bool P12218319_CALL Create(const uint32_t) throw();
		bool P12218319_CALL Delete() throw();

		P12218319_CALL operator bool() const throw();
	};
}
#endif