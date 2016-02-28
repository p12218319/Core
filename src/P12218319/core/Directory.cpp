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

#include "P12218319\core\Directory.hpp"
#include "P12218319\core\Files.hpp"
#include "P12218319\core\File.hpp"

namespace P12218319 {
	// Directory 

	P12218319_CALL Directory::Directory(const std::string& aPath) :
		mPath(aPath),
		mExists(files::GetFileAttributes(aPath) & files::EXISTS)
	{}

	P12218319_CALL Directory::~Directory() {

	}

	Directory P12218319_CALL Directory::GetParentDirectory() const {
		if(mPath.find_first_of('\\') == mPath.find_last_of('\\')) throw std::runtime_error("P12218319::Directory : Directory is the root directory");
		return Directory(files::GetParentDirectory(mPath));
	}

	std::vector<File> Directory::GetChildFiles() const {
		return std::vector<File>();
	}

	std::vector<Directory> Directory::GetChildDirectories() const {
		return std::vector<Directory>();
	}

	bool P12218319_CALL Directory::Exists() const throw() {
		return mExists;
	}

	bool P12218319_CALL Directory::Create() throw() {
		if(mExists) return false;
		if(! files::CreateDirectory(mPath)) return false;
		mExists = true;
		return true;
	}

	bool P12218319_CALL Directory::Delete() throw() {
		if(! mExists) return false;
		if(! files::DeleteDirectoryRecursive(mPath)) return false;
		mExists = false;
	}

	P12218319_CALL Directory::operator bool() const throw() {
		return mExists;
	}

}