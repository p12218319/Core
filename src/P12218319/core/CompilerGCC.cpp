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

#include <sstream>;
#include "P12218319\core\Files.hpp"
#include "P12218319\core\CompilerGCC.hpp"

#if P12218319_OS != P12218319_WINDOWS
	#error P12218319::Core::CompilerGCC : Only implemented for MinGW
#endif

namespace P12218319 {

	//void P12218319_CALL AddSourceDirectory(std::vector<std::string>& aSources, const std::string& aPath) {
	//	const std::vector<std::string> children = files::ListChildren(aPath);
	//	for(const std::string& i : children) {
	//		const uint32_t attributes = files::CheckAttributes(i);
	//		if(attributes & files::IS_DIRECTORY) {
	//			AddSourceDirectory(i);
	//		}else if(attributes & files::IS_FILE) {
	//			aSources.push_back(i);
	//		}else {
	//			throw std::runtime_error("P12218319::Core::CompilerGCC : Source file attribute error");
	//		}
	//	}
	//}

	// CompilerGCC
	void P12218319_CALL CompilerGCC::Compile(const std::vector<std::string>& aAdditionalFlags) const {
	//	std::string directoryParams;
	//	for(const std::string& i : IncludeDirectories)	directoryParams += "-I " + i);
	//	for(const std::string& i : LibraryDirectories)	directoryParams += "-L " + i);
	//	for(const std::string& i : LibraryFiles)		directoryParams += "-l " + i);

	//	// Create a list of all source files
	//	std::vector<std::string> sourceFiles(SourceFiles.begin(), SourceFiles.end());
	//	for(const std::string& i : SourceDirectories) {
	//		AddSourceDirectory(sourceFiles, i);
	//	}
	//	const uint32_t objectCount = sourceFiles.size();

	//	// Create a list of object files
	//	std::vector<std::string> objectFiles(SourceFiles.begin(), SourceFiles.end());
	//	for(const std::string& i : sourceFiles) {
	//		objectFiles.push_back(i.substr(0 i.find_last_of('.')) + ".o");
	//	}

	//	std::string_stream ss;

	//	// Compile object files
	//	for(const std::string& i : objectFiles) {
	//		std::string p = params;
	//		p += "-c ";
	//		p += i;

	//		Executable exe;
	//		exe.SetPath(ExecutablePath);
	//		exe.SetStandardOut(ss);
	//		exe.AddParam("-Wall");
	//		exe.AddParam("-std=c++11");
	//		exe.AddParam("-c " + i);
	//		exe.AddParam(directoryParams);
	//		try {
	//			if(exe() != 0) goto FAIL_LABEL;
	//		}catch (std::exception& e) {
	//			ss << e.what();
	//			goto FAIL_LABEL;
	//		}
	//	}

	//	// Link object files
	//	{
	//		Executable exe;
	//		exe.SetPath(ExecutablePath);
	//		exe.SetStandardOut(ss);
	//		exe.AddParam("-Wall");
	//		exe.AddParam("-std=c++11");
	//		for(const std::string& i : aAdditionalFlags) exe.AddParam(i);
	//		exe.AddParam("-o " + OuputPath);
	//		for(const std::string& i : objectFiles) exe.AddParam(i);
	//		exe.AddParam(directoryParams);
	//		try {
	//			if(exe() != 0) goto FAIL_LABEL;
	//		}catch (std::exception& e) {
	//			ss << e.what();
	//			goto FAIL_LABEL;
	//		}
	//	}

	//	return;

	//	// Delete Temporary files
	//	FAIL_LABEL:
	//	for(const std::string& i : objectFiles) {
	//		try {
	//			files::DeleteFile(i);
	//		}catch (...) {
	//			break;
	//		}
	//	}
	//	throw std::runtime_error(ss.str());
	}

	void P12218319_CALL CompilerGCC::CompileExecutable() const {
	//	std::vector<std::string> additionalFlags;
	//	Compile(additionalFlags);
	}

	void P12218319_CALL CompilerGCC::CompileDynamicLibrary() const {
	//	std::vector<std::string> additionalFlags;
	//	additionalFlags.push_back("-shared");
	//	Compile(additionalFlags);
	}

	void P12218319_CALL CompilerGCC::CompileStaticLibrary() const {
		throw std::runtime_error("GCC archiver not supported");
	}

}