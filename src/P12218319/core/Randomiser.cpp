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
#include "P12218319/core/Randomiser.hpp"

#include <cmath>

namespace P12218319 {
	// Randomiser

	Randomiser::~Randomiser() {

	}

	uint64_t Randomiser::Next64u() {
		return Generate();
	}

	uint32_t Randomiser::Next32u() {
		return static_cast<uint32_t>(Generate());
	}

	uint16_t Randomiser::Next16u() {
		return static_cast<uint16_t>(Generate());
	}

	uint8_t Randomiser::Next8u() {
		return static_cast<uint8_t>(Generate());
	}

	int64_t Randomiser::Next64i() {
		const uint64_t tmp = Generate();
		return *reinterpret_cast<const int64_t*>(&tmp);
	}

	int32_t Randomiser::Next32i() {
		return static_cast<int32_t>(Next64i());
	}

	int16_t Randomiser::Next16i() {
		return static_cast<int16_t>(Next64i());
	}

	int8_t Randomiser::Next8i() {
		return static_cast<int8_t>(Next64i());
	}

	float Randomiser::NextF() {
		//! \todo Implement Randomiser::NextF
		return 0.f;
	}

	double Randomiser::NextD() {
		return static_cast<double>(NextF());
	}

	uint64_t Randomiser::Next64u(const uint64_t aMax) {
		return Next64u() % aMax;
	}

	uint32_t Randomiser::Next32u(const uint32_t aMax) {
		return static_cast<uint32_t>(Next64u(aMax));
	}

	uint16_t Randomiser::Next16u(const uint16_t aMax) {
		return static_cast<uint16_t>(Next64u(aMax));
	}

	uint8_t Randomiser::Next8u(const uint8_t aMax) {
		return static_cast<uint8_t>(Next64u(aMax));
	}

	int64_t Randomiser::Next64i(const int64_t aMax) {
		return Next64i() % aMax;
	}

	int32_t Randomiser::Next32i(const int32_t aMax) {
		return static_cast<int32_t>(Next64i(aMax));
	}

	int16_t Randomiser::Next16i(const int16_t aMax) {
		return static_cast<int16_t>(Next64i(aMax));
	}

	int8_t Randomiser::Next8i(const int8_t aMax) {
		return static_cast<int8_t>(Next64i(aMax));
	}

	float Randomiser::NextF(const float aMax) {
		return std::fmod(NextF(), aMax);
	}

	double Randomiser::NextD(const double aMax) {
		return static_cast<double>(std::fmod(NextF(), static_cast<float>(aMax)));
	}

	uint64_t Randomiser::Next64u(const uint64_t aMin, const uint64_t aMax) {
		return Next64u(aMax - aMin) + aMin;
	}

	uint32_t Randomiser::Next32u(const uint32_t aMin, const uint32_t aMax) {
		return static_cast<uint32_t>(Next64u(aMin, aMax));
	}

	uint16_t Randomiser::Next16u(const uint16_t aMin, const uint16_t aMax) {
		return static_cast<uint16_t>(Next64u(aMin, aMax));
	}

	uint8_t Randomiser::Next8u(const uint8_t aMin, const uint8_t aMax) {
		return static_cast<uint8_t>(Next64u(aMin, aMax));
	}

	int64_t Randomiser::Next64i(const int64_t aMin, const int64_t aMax) {
		return Next64i(aMax - aMin) + aMin;
	}

	int32_t Randomiser::Next32i(const int32_t aMin, const int32_t aMax) {
		return static_cast<int32_t>(Next64i(aMin, aMax));
	}

	int16_t Randomiser::Next16i(const int16_t aMin, const int16_t aMax) {
		return static_cast<int16_t>(Next64i(aMin, aMax));
	}

	int8_t Randomiser::Next8i(const int8_t aMin, const int8_t aMax) {
		return static_cast<int8_t>(Next64i(aMin, aMax));
	}

	float Randomiser::NextF(const float aMin, const float aMax) {
		return NextF(aMax - aMin) + aMin;
	}

	double Randomiser::NextD(const double aMin, const double aMax) {
		return NextD(aMax - aMin) + aMin;
	}

	void Randomiser::Next(void* const aPtr, const uint32_t aBytes) {
		uint8_t* ptr = static_cast<uint8_t*>(aPtr);
		uint32_t bytes = aBytes;

		while(bytes >= 8) {
			*reinterpret_cast<uint64_t*>(ptr) = Next64u();
			ptr += 8;
			bytes -= 8;
		}

		if(bytes >= 4) {
			*reinterpret_cast<uint32_t*>(ptr) = Next32u();
			ptr += 4;
			bytes -= 4;
		}

		if(bytes >= 2) {
			*reinterpret_cast<uint16_t*>(ptr) = Next16u();
			ptr += 2;
			bytes -= 2;
		}

		if(bytes == 1) {
			*reinterpret_cast<uint8_t*>(ptr) = Next8u();
		}
	}

}