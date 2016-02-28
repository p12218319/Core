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
#ifndef P12218319_CORE_STATISTICS_HPP
#define P12218319_CORE_STATISTICS_HPP

#include <map>
#include <algorithm>
#include "P12218319\core\Core.hpp"

namespace P12218319 {
	template<class T, class ITERATOR>
	static T P12218319_CALL Mean(ITERATOR aBegin, const ITERATOR aEnd) throw() {
		T tmp = static_cast<T>(0);
		const uint32_t count = aEnd - aBegin;
		while(aBegin != aEnd) {
			tmp += *aBegin;
			++aBegin;
		}
		return tmp / static_cast<T>(count);
	}

	template<class T, class ITERATOR>
	static T P12218319_CALL Mode(ITERATOR aBegin, const ITERATOR aEnd) throw() {
		std::map<T, uint32_t> frequency;
		typedef std::map<T, uint32_t>::iterator MapIterator;
		
		while(aBegin != aEnd) {
			MapIterator i = frequency.find(*aBegin);
			if(i == frequency.end()){
				i = frequency.emplace(*aBegin, 0).first;
			}
			++i->second;
			++aBegin;
		}
		
		MapIterator mode = frequency.begin();
		const MapIterator end = frequency.end();
		
		MapIterator i = mode;
		++i;
		for (i; i != end; ++i) {
			if(i->second > mode->second) mode = i;
		}
		
		return mode->first;
	}

	template<class T, class ITERATOR>
	static T P12218319_CALL Median(ITERATOR aBegin, const ITERATOR aEnd) throw() {
		const uint32_t count = aEnd - aBegin;
		T* ordered = new T[count];
		for(uint32_t i = 0; i < count; ++i, ++aBegin) ordered[i] = *aBegin;
		std::sort(ordered, ordered + count, [](const T aLeft, const T aRight)->bool{return aLeft < aRight;});
		const T tmp = count & 1 ? (ordered[count / 2] + ordered[(count / 2) + 1]) / static_cast<T>(2) : ordered[count / 2];
		delete[] ordered;
		return tmp;
	}
	
	template<class T, class ITERATOR>
	static T P12218319_CALL Variance(ITERATOR aBegin, const ITERATOR aEnd) throw() {
		const T mean = Mean<T>(aBegin, aEnd);
		const uint32_t count = aEnd - aBegin;
		T* squares = new T[count];
		for(uint32_t i = 0; i < count; ++i, ++aBegin) squares[i] = (*aBegin - mean) * (*aBegin - mean);
		const T tmp = Mean<T>(squares, squares + count);
		delete[] squares;
		return tmp;
	}
	
	template<class T, class ITERATOR>
	static T P12218319_CALL StandardDeviation(ITERATOR aBegin, const ITERATOR aEnd) throw() {
		return std::sqrt(Variance<T, ITERATOR >(aBegin, aEnd));
	}
}
#endif