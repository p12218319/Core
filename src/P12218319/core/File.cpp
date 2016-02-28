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

#include "P12218319\core\File.hpp"
#include "P12218319\core\Files.hpp"
#include "P12218319\core\Directory.hpp"

namespace P12218319 {
	// File

	P12218319_CALL File::File(const std::string& aPath) :
		mPath(aPath),
		mAttributes(files::GetFileAttributes(aPath))
	{}

	P12218319_CALL File::~File() {

	}

	Directory P12218319_CALL File::GetParentDirectory() const throw() {
		return Directory(files::GetParentDirectory(mPath));
	}

	bool P12218319_CALL File::IsReadable() const throw() {
		return mAttributes & files::IS_READABLE;
	}

	bool P12218319_CALL File::IsWriteable() const throw() {
		return mAttributes & files::IS_WRITEABLE;
	}

	bool P12218319_CALL File::Exists() const throw() {
		return mAttributes & files::EXISTS;
	}

	bool P12218319_CALL File::IsReadOnly() const throw() {
		return IsReadable() && ! IsWriteable();
	}

	bool P12218319_CALL File::IsWriteOnly() const throw() {
		return IsWriteable() && ! IsReadable();
	}

	bool P12218319_CALL File::IsReadWrite() const throw() {
		return mAttributes & files::IS_READ_WRITEABLE;
	}

	uint32_t P12218319_CALL File::Size() const throw() {
		return files::GetFileSize(mPath);
	}

	File P12218319_CALL File::Copy(const std::string& aPath) const {
		if(! Exists()) return false;
		try {
			files::Copy(mPath, aPath);
		}catch (...) {

		}
		return File(aPath);
	}

	bool P12218319_CALL File::Move(const std::string& aPath) {
		if(! Exists()) return false;
		try {
			files::Move(mPath, aPath);
			mPath = aPath;
			return true;
		}catch (...) {
			return false;
		}
	}

	bool P12218319_CALL File::Rename(const std::string& aPath) {
		if(! Exists()) return false;
		try {
			files::Rename(mPath, aPath);
			mPath = aPath;
			return true;
		}catch (...) {
			return false;
		}
	}

	bool P12218319_CALL File::Create(const uint32_t aAttributes) throw() {
		if(Exists()) return false;
		if(! files::CreateFile(mPath, aAttributes)) return false;
		mAttributes |= files::EXISTS;
		return true;
	}

	bool P12218319_CALL File::Delete() throw() {
		if(! Exists()) return false;
		if(! files::DeleteFile(mPath)) return false;
		mAttributes &= ~files::EXISTS;
		return true;
	}

	P12218319_CALL File::operator bool() const throw() {
		return mAttributes & files::EXISTS;
	}

}