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
#ifndef P12218319_CORE_SYSTEM_CLOCK_HPP
#define P12218319_CORE_SYSTEM_CLOCK_HPP

#include "P12218319\core\Core.hpp"

namespace P12218319 { namespace systemClock {
	P12218319_EXPORT_API uint64_t P12218319_CALL Milliseconds() throw();
	P12218319_EXPORT_API uint64_t P12218319_CALL Microseconds() throw();
	P12218319_EXPORT_API uint64_t P12218319_CALL Nanoseconds() throw();
}}
#endif