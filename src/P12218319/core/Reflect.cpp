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
#include "P12218319\core\Reflect.hpp"

namespace P12218319 {

	enum : uint8_t {
		BIN_0000 = 0,
		BIN_0001 = 1,
		BIN_0010 = 2,
		BIN_0011 = 3,
		BIN_0100 = 4,
		BIN_0101 = 5,
		BIN_0110 = 6,
		BIN_0111 = 7,
		BIN_1000 = 8,
		BIN_1001 = 9,
		BIN_1010 = 10,
		BIN_1011 = 11,
		BIN_1100 = 12,
		BIN_1101 = 13,
		BIN_1110 = 14,
		BIN_1111 = 15
	};

	static constexpr uint8_t REFLECT[16] = {
		BIN_0000, // 0000 0
		BIN_1000, // 0001 1
		BIN_0100, // 0010 2
		BIN_1100, // 0011 3
		BIN_0100, // 0100 4
		BIN_1010, // 0101 5
		BIN_0110, // 0110 6
		BIN_1110, // 0111 7
		BIN_0001, // 1000 8
		BIN_1001, // 1001 9
		BIN_0101, // 1010 10
		BIN_1101, // 1011 11
		BIN_0011, // 1100 12
		BIN_1011, // 1101 13
		BIN_0111, // 1110 14
		BIN_1111  // 1111 15
	};

	constexpr uint8_t P12218319_CALL Reflect(const uint8_t aValue) throw() {
		return (REFLECT[aValue >> 4] << 4) | REFLECT[aValue & 15];
	}

	constexpr uint16_t P12218319_CALL Reflect(const uint16_t aValue) throw() {
		return
			(REFLECT[aValue & 15]) |
			(REFLECT[(aValue >> 4) & 15] << 4) |
			(REFLECT[(aValue >> 8) & 15] << 8) |
			(REFLECT[(aValue >> 12) & 15] << 12);
	}

	constexpr uint32_t P12218319_CALL Reflect(const uint32_t aValue) throw() {
		return
			(REFLECT[aValue & 15]) |
			(REFLECT[(aValue >> 4) & 15] << 4) |
			(REFLECT[(aValue >> 8) & 15] << 8) |
			(REFLECT[(aValue >> 12) & 15] << 12) |
			(REFLECT[(aValue >> 16) & 15] << 16) |
			(REFLECT[(aValue >> 20) & 15] << 20) |
			(REFLECT[(aValue >> 24) & 15] << 24) |
			(REFLECT[(aValue >> 28) & 15] << 28);
	}

	constexpr uint64_t P12218319_CALL Reflect(const uint64_t aValue) throw() {
		return
			(REFLECT[aValue & 15L]) |
				(REFLECT[(aValue >> 4L) & 15L] << 4L) |
				(REFLECT[(aValue >> 8L) & 15L] << 8L) |
				(REFLECT[(aValue >> 12L) & 15L] << 12L) |
				(REFLECT[(aValue >> 16L) & 15L] << 16L) |
				(REFLECT[(aValue >> 20L) & 15L] << 20L) |
				(REFLECT[(aValue >> 24L) & 15L] << 24L) |
				(REFLECT[(aValue >> 28L) & 15L] << 28L) |
				(REFLECT[(aValue >> 32L) & 15L] << 32L) |
				(REFLECT[(aValue >> 36L) & 15L] << 36L) |
				(REFLECT[(aValue >> 40L) & 15L] << 40L) |
				(REFLECT[(aValue >> 44L) & 15L] << 44L) |
				(REFLECT[(aValue >> 48L) & 15L] << 48L) |
				(REFLECT[(aValue >> 52L) & 15L] << 52L) |
				(REFLECT[(aValue >> 56L) & 15L] << 56L) |
				(REFLECT[(aValue >> 60L) & 15L] << 60L);
	}

	constexpr int8_t P12218319_CALL Reflect(const int8_t aValue) throw() {
		return Reflect(*reinterpret_cast<const uint8_t*>(&aValue));
	}

	constexpr int16_t P12218319_CALL Reflect(const int16_t aValue) throw() {
		return Reflect(*reinterpret_cast<const uint16_t*>(&aValue));
	}

	constexpr int32_t P12218319_CALL Reflect(const int32_t aValue) throw() {
		return Reflect(*reinterpret_cast<const uint32_t*>(&aValue));
	}

	constexpr int64_t P12218319_CALL Reflect(const int64_t aValue) throw() {
		return Reflect(*reinterpret_cast<const uint64_t*>(&aValue));
	}
}