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
#include "P12218319/core/RandomiserXorshiftStar.hpp"

namespace P12218319 {
	// XorshiftStar

	XorshiftStar::XorshiftStar() :
		mSeed(123456789123456789L)
	{}

	XorshiftStar::XorshiftStar(uint64_t aSeed) :
		mSeed(aSeed)
	{}

	XorshiftStar::~XorshiftStar() {

	}

	void XorshiftStar::SetSeed(const uint64_t aSeed) {
		mSeed = aSeed;
	}

	uint64_t XorshiftStar::GetSeed() const {
		return mSeed;
	}

	uint64_t XorshiftStar::Generate() {
		mSeed ^= mSeed >> 12;
		mSeed ^= mSeed << 25;
		mSeed ^= mSeed >> 27;
		return mSeed * 2685821657736338717L;
	}

}