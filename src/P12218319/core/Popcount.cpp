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

#include <chrono>
#include "P12218319\core\Popcount.hpp"

namespace P12218319 {
	static constexpr uint8_t POP_COUNT[16] = {
		0,	// 0000 0
		1,	// 0001 1
		1,	// 0010 2
		2,	// 0011 3
		1,	// 0100 4
		2,	// 0101 5
		2,	// 0110 6
		3,	// 0111 7
		1,	// 1000 8
		2,	// 1001 9
		2,	// 1010 10
		3,	// 1011 11
		2,	// 1100 12
		3,	// 1101 13
		3,	// 1110 14
		4	// 1111 15
	};

	constexpr uint8_t P12218319_CALL Popcount(const uint8_t aValue) throw() {
		return POP_COUNT[aValue >> 4] + POP_COUNT[aValue & 15];
	}

	constexpr uint8_t P12218319_CALL Popcount(const uint16_t aValue) throw() {
		return
			POP_COUNT[aValue & 15] +
			POP_COUNT[(aValue >> 4) & 15] +
			POP_COUNT[(aValue >> 8) & 15] +
			POP_COUNT[(aValue >> 12) & 15];
	}

	constexpr uint8_t P12218319_CALL Popcount(const uint32_t aValue) throw() {
		return
			POP_COUNT[aValue & 15] +
			POP_COUNT[(aValue >> 4) & 15] +
			POP_COUNT[(aValue >> 8) & 15] +
			POP_COUNT[(aValue >> 12) & 15] +
			POP_COUNT[(aValue >> 16) & 15] +
			POP_COUNT[(aValue >> 20) & 15] +
			POP_COUNT[(aValue >> 24) & 15] +
			POP_COUNT[(aValue >> 28) & 15];
	}

	constexpr uint8_t P12218319_CALL Popcount(const uint64_t aValue) throw() {
		return
			POP_COUNT[aValue & 15L] +
			POP_COUNT[(aValue >> 4L) & 15L] +
			POP_COUNT[(aValue >> 8L) & 15L] +
			POP_COUNT[(aValue >> 12L) & 15L] +
			POP_COUNT[(aValue >> 16L) & 15L] +
			POP_COUNT[(aValue >> 20L) & 15L] +
			POP_COUNT[(aValue >> 24L) & 15L] +
			POP_COUNT[(aValue >> 28L) & 15L] +
			POP_COUNT[(aValue >> 32L) & 15L] +
			POP_COUNT[(aValue >> 36L) & 15L] +
			POP_COUNT[(aValue >> 40L) & 15L] +
			POP_COUNT[(aValue >> 44L) & 15L] +
			POP_COUNT[(aValue >> 48L) & 15L] +
			POP_COUNT[(aValue >> 52L) & 15L] +
			POP_COUNT[(aValue >> 56L) & 15L] +
			POP_COUNT[(aValue >> 60L) & 15L];
	}

	constexpr uint8_t P12218319_CALL Popcount(const int8_t aValue) throw() {
		return Popcount(*reinterpret_cast<const uint8_t*>(&aValue));
	}

	constexpr uint8_t P12218319_CALL Popcount(const int16_t aValue) throw() {
		return Popcount(*reinterpret_cast<const uint16_t*>(&aValue));
	}

	constexpr uint8_t P12218319_CALL Popcount(const int32_t aValue) throw() {
		return Popcount(*reinterpret_cast<const uint32_t*>(&aValue));
	}

	constexpr uint8_t P12218319_CALL Popcount(const int64_t aValue) throw() {
		return Popcount(*reinterpret_cast<const uint64_t*>(&aValue));
	}

}