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
#ifndef P12218319_CORE_COMPILER_GCC_HPP
#define P12218319_CORE_COMPILER_GCC_HPP

#include "P12218319\core\Compiler.hpp"

namespace P12218319 {
	class P12218319_EXPORT_API CompilerGCC : public Compiler {
	private:
		void P12218319_CALL Compile(const std::vector<std::string>&) const;
	public:
		// Inherited from Compiler
		void P12218319_CALL CompileExecutable() const override;
		void P12218319_CALL CompileDynamicLibrary() const override;
		void P12218319_CALL CompileStaticLibrary() const override;
	};
}
#endif