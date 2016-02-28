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
#ifndef P12218319_CORE_COMPILER_HPP
#define P12218319_CORE_COMPILER_HPP

#include <vector>
#include <string>
#include "P12218319\core\Core.hpp"

namespace P12218319 {
	class P12218319_EXPORT_API Compiler {
	public:
		typedef std::pair<std::string, std::string> Macro;
	public:
		std::vector<std::string> IncludeDirectories;
		std::vector<std::string> SourceDirectories;
		std::vector<std::string> LibraryDirectories;
		std::vector<std::string> SourceFiles;
		std::vector<std::string> LibraryFiles;
		std::vector<std::string> Flags;
		std::vector<Macro> MacroDefinitions;
		std::string ExecutablePath;
		std::string OuputPath;
	public:
		virtual P12218319_CALL ~Compiler() {}
		virtual void P12218319_CALL CompileExecutable() const = 0;
		virtual void P12218319_CALL CompileDynamicLibrary() const = 0;
		virtual void P12218319_CALL CompileStaticLibrary() const = 0;
	};
}
#endif