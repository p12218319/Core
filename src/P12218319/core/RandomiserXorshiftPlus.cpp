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
#include "P12218319/core/RandomiserXorshiftPlus.hpp"

namespace P12218319 {
	// XorshiftPlus

	P12218319_CALL XorshiftPlus::XorshiftPlus() {
		mSeed[0] = 123456789123456789L;
		mSeed[1] = 123456789123456789L;
	}

	P12218319_CALL XorshiftPlus::XorshiftPlus(uint64_t aSeed)  {
		mSeed[0] = aSeed;
		mSeed[1] = 123456789123456789L;
	}

	P12218319_CALL XorshiftPlus::~XorshiftPlus() {

	}

	void P12218319_CALL XorshiftPlus::SetSeed(const uint64_t aSeed) {
		mSeed[0] = aSeed;
	}

	uint64_t P12218319_CALL XorshiftPlus::GetSeed() const {
		return mSeed[0];
	}

	uint64_t P12218319_CALL XorshiftPlus::Generate() {
		uint64_t x = mSeed[0];
		uint64_t const y = mSeed[1];
		mSeed[0] = y;
		x ^= x << 23L;
		mSeed[1] = x ^ y ^ (x >> 17L) ^ (y >> 26L);
		return mSeed[1] + y;
	}

}