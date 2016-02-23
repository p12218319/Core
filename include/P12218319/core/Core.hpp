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

// OS and platform

#define P12218319_WINDOWS 0
#define P12218319_LINUX 1
#define P12218319_MAC 2

#define P12218319_X86 0
#define P12218319_X64 1

#ifdef _WIN32
	#define P12218319_OS P12218319_WINDOWS
	
	#ifdef _WIN64
		#define P12218319_PLATFORM P12218319_X64
	#else
		#define P12218319_PLATFORM P12218319_X86
	#endif
	
#endif

#ifdef __gnu_linux__
	#define P12218319_OS P12218319_LINUX
	//! \todo Detect linux platform
	#define P12218319_PLATFORM P12218319_X86
#endif

#ifdef __APPLE__ 
	#define P12218319_OS P12218319_MAC
	//! \todo Detect mac platform
	#define P12218319_PLATFORM P12218319_X86
#endif

#ifndef P12218319_OS
	#error P12218319 Core : Unknown OS
#endif

#ifndef P12218319_PLATFORM
	#error P12218319 Core : Unknown target platform
#endif

// Compile options

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

// Shortcuts

#ifndef P12218319_STATIC_ASSERT
	#define P12218319_STATIC_ASSERT(aCondition, aMessage) static_assert(aCondition, aMessage)
#endif

#ifndef P12218319_RUNTIME_ASSERT
	#define P12218319_RUNTIME_ASSERT(aCondition, aMessage) if(!(aCondition)) throw std::runtime_error(aMessage)
#endif

#endif