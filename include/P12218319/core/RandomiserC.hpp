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
#ifndef P12218319_CORE_RANDOMISER_RANDOMISER_C_HPP
#define P12218319_CORE_RANDOMISER_RANDOMISER_C_HPP

#include "Randomiser.hpp"

namespace P12218319 {
	class P12218319_EXPORT_API RandomiserC : public Randomiser {
	private:
		uint32_t mSeed;
	protected:
		virtual uint64_t P12218319_CALL Generate() override;
	public:
		P12218319_CALL RandomiserC();
		P12218319_CALL RandomiserC(uint32_t);
		P12218319_CALL ~RandomiserC();

		void P12218319_CALL SetSeed(const uint64_t) override;
		uint64_t P12218319_CALL GetSeed() const override;
	};
}

#endif