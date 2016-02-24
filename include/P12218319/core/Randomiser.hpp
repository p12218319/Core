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
#ifndef P12218319_CORE_RANDOMISER_HPP
#define P12218319_CORE_RANDOMISER_HPP

#include <cstdint>
#include "Core.hpp"

namespace P12218319 {
	class P12218319_EXPORT_API Randomiser {
	protected:
		virtual uint64_t P12218319_CALL Generate() = 0;
	public:
		virtual P12218319_CALL ~Randomiser();

		virtual void P12218319_CALL SetSeed(const uint64_t) = 0;
		virtual uint64_t P12218319_CALL GetSeed() const = 0;

		uint64_t P12218319_CALL Next64u();
		uint32_t P12218319_CALL Next32u();
		uint16_t P12218319_CALL Next16u();
		uint8_t P12218319_CALL Next8u();
		int64_t P12218319_CALL Next64i();
		int32_t P12218319_CALL Next32i();
		int16_t P12218319_CALL Next16i();
		int8_t P12218319_CALL Next8i();
		float P12218319_CALL NextF();
		double P12218319_CALL NextD();

		uint64_t P12218319_CALL Next64u(const uint64_t);
		uint32_t P12218319_CALL Next32u(const uint32_t);
		uint16_t P12218319_CALL Next16u(const uint16_t);
		uint8_t P12218319_CALL Next8u(const uint8_t);
		int64_t P12218319_CALL Next64i(const int64_t);
		int32_t P12218319_CALL Next32i(const int32_t);
		int16_t P12218319_CALL Next16i(const int16_t);
		int8_t P12218319_CALL Next8i(const int8_t);
		float P12218319_CALL NextF(const float);
		double P12218319_CALL NextD(const double);

		uint64_t P12218319_CALL Next64u(const uint64_t, const uint64_t);
		uint32_t P12218319_CALL Next32u(const uint32_t, const uint32_t);
		uint16_t P12218319_CALL Next16u(const uint16_t, const uint16_t);
		uint8_t P12218319_CALL Next8u(const uint8_t, const uint8_t);
		int64_t P12218319_CALL Next64i(const int64_t, const int64_t);
		int32_t P12218319_CALL Next32i(const int32_t, const int32_t);
		int16_t P12218319_CALL Next16i(const int16_t, const int16_t);
		int8_t P12218319_CALL Next8i(const int8_t, const int8_t);
		float P12218319_CALL NextF(const float, const float);
		double P12218319_CALL NextD(const double, const double);

		void P12218319_CALL Next(void* const, const uint32_t);
	};
}

#endif