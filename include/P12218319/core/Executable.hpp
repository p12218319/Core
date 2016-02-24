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
#ifndef P12218319_CORE_EXECUTEABLE_HPP
#define P12218319_CORE_EXECUTEABLE_HPP

#include <iostream>
#include "Core.hpp"

namespace P12218319 {
	/*!
		\date 23rd Febuary 2016
		\version 0.1
	*/
	class P12218319_EXPORT_API Executable {
	private:
		std::istream* mStdIn;
		std::ostream* mStdOut;
		std::ostream* mStdErr;
		std::string mPath;
		std::string mParams;
	public:
		P12218319_CALL Executable();
		P12218319_CALL Executable(const std::string&);
		P12218319_CALL Executable(const std::string&, const std::initializer_list<std::string>);
		P12218319_CALL Executable(const std::string&, const std::initializer_list<std::string>, std::istream&, std::ostream&, std::ostream&);
		P12218319_CALL ~Executable();
		
		void P12218319_CALL SetPath(const std::string&) throw();
		void P12218319_CALL AddParameter(const std::string&) throw();
		void P12218319_CALL SetStandardIn(std::istream&) throw();
		void P12218319_CALL SetStandardOut(std::ostream&) throw();
		void P12218319_CALL SetStandardError(std::ostream&) throw();
		int P12218319_CALL operator()();
	};
}
#endif