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
#ifndef P12218319_CORE_DYNAMIC_LIBRARY_HPP
#define P12218319_CORE_DYNAMIC_LIBRARY_HPP

#include <string>
#include <memory>
#include "P12218319\core\Core.hpp"

namespace P12218319 { 
	class P12218319_EXPORT_API DynamicLibrary {
	public:
		typedef void(*FunctionPtr)();
	protected:
		virtual FunctionPtr P12218319_CALL LoadFunction_(const std::string&) const throw() = 0;
	public:
		virtual P12218319_CALL ~DynamicLibrary(){}

		template<class FN, class ENABLE = typename std::enable_if<std::is_pointer<T>::value>::type>
		inline FN LoadFunction(const std::string& aName) const throw() {
			return reinterpret_cast<F>(LoadFunction_(aName));
		}
	};

	P12218319_EXPORT_API std::shared_ptr<DynamicLibrary> P12218319_CALL LoadLibrary(const std::string&) throw();
}
#endif