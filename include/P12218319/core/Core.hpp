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
#ifndef P12218319_CORE_HPP
#define P12218319_CORE_HPP

#include <stdexcept>

#define P12218319_STATIC_COMPILE 0
#define P12218319_DYNAMIC_EXPORT_COMPILE 1
#define P12218319_DYNAMIC_IMPORT_COMPILE 2

#ifndef P12218319_COMPILE_MODE
	#define P12218319_COMPILE_MODE P12218319_STATIC_COMPILE 
#endif

#if P12218319_COMPILE_MODE == P12218319_STATIC_COMPILE
	#define P12218319_EXPORT_API
#endif


#if P12218319_COMPILE_MODE == P12218319_DYNAMIC_EXPORT_COMPILE 
	#define P12218319_EXPORT_API __declspec(dllexport)
#endif


#if P12218319_COMPILE_MODE == P12218319_DYNAMIC_IMPORT_COMPILE 
	#define P12218319_EXPORT_API __declspec(dllimport)
#endif

#define P12218319_CALL __stdcall


#ifndef P12218319_STATIC_ASSERT
	#define P12218319_STATIC_ASSERT(aCondition, aMessage) static_assert(aCondition, aMessage)
#endif

#ifndef P12218319_RUNTIME_ASSERT
	#define P12218319_RUNTIME_ASSERT(aCondition, aMessage) if(!(aCondition)) throw std::runtime_error(aMessage)
#endif

#endif