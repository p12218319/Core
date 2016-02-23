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
#include "P12218319/core/RandomiserC.hpp"
#include <stdlib.h> 

namespace P12218319 {
	// XorshiftC

	RandomiserC::RandomiserC() :
		mSeed(123456789)
	{
		srand(mSeed);
	}

	RandomiserC::RandomiserC(uint32_t aSeed) :
		mSeed(aSeed)
	{
		srand(mSeed);
	}

	RandomiserC::~RandomiserC() {

	}

	void RandomiserC::SetSeed(const uint64_t aSeed) {
		mSeed = static_cast<uint32_t>(aSeed);
		srand(mSeed);
	}

	uint64_t RandomiserC::GetSeed() const {
		return mSeed;
	}

	uint64_t RandomiserC::Generate() {
		mSeed = rand();
		return mSeed;
	}

}