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
#ifndef P12218319_CORE_VECTOR_OPERATORS_INL
#define P12218319_CORE_VECTOR_OPERATORS_INL

#include "P12218319\core\Core.hpp"


namespace P12218319 {

	#define P12218319_VECTOR_OPERATOR(aOperator)\
	template<const uint32_t LENGTH, class T>\
	Vector<LENGTH, T>& P12218319_CALL operator ## aOperator(Vector<LENGTH, T>& aLeft, const Vector<LENGTH, T> aRight) {\
		for(uint32_t i = 0; i < LENGTH; ++i) aLeft[i] aOperator aRight[i];\
		return aLeft;\
	}\
	template<const uint32_t LENGTH, class T>\
	Vector<LENGTH, T>& P12218319_CALL operator ## aOperator(Vector<LENGTH, T>& aLeft, const T aRight) {\
		for(uint32_t i = 0; i < LENGTH; ++i) aLeft[i] aOperator aRight;\
		return aLeft;\
	}

	P12218319_VECTOR_OPERATOR(+=)
	P12218319_VECTOR_OPERATOR(-=)
	P12218319_VECTOR_OPERATOR(*=)
	P12218319_VECTOR_OPERATOR(/=)

	#undef P12218319_VECTOR_OPERATOR

	#define P12218319_VECTOR_OPERATOR(aOperator)\
	template<const uint32_t LENGTH, class T>\
	inline Vector<LENGTH, T> P12218319_CALL operator ## aOperator(const Vector<LENGTH, T> aLeft, const Vector<LENGTH, T> aRight) {\
		return Vector<LENGTH, T>(aLeft) aOperator ## = aRight;\
	}\
	template<const uint32_t LENGTH, class T>\
	Vector<LENGTH, T> P12218319_CALL operator ## aOperator(Vector<LENGTH, T> aLeft, const T aRight) {\
		for(uint32_t i = 0; i < LENGTH; ++i) aLeft[i] aOperator## = aRight;\
		return aLeft;\
	}\
	template<const uint32_t LENGTH, class T>\
	Vector<LENGTH, T> P12218319_CALL operator ## aOperator(const T aLeft, Vector<LENGTH, T> aRight) {\
		for(uint32_t i = 0; i < LENGTH; ++i) aRight[i] = aLeft aOperator aRight[i];\
		return aRight;\
	}

	P12218319_VECTOR_OPERATOR(+)
	P12218319_VECTOR_OPERATOR(-)
	P12218319_VECTOR_OPERATOR(*)
	P12218319_VECTOR_OPERATOR(/)

	#undef P12218319_VECTOR_OPERATOR
}


#endif