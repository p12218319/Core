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
#ifndef P12218319_CORE_VECTOR_HPP
#define P12218319_CORE_VECTOR_HPP

#include "P12218319\core\Core.hpp"

namespace P12218319 {
	template<const uint32_t LENGTH_, class T>
	class Vector {
	public:
		typedef T Scalar;
		enum {
			LENGTH = LENGTH_
		};
	private:
		Scalar mValues[LENGTH];
	public:
		P12218319_CALL Vector() throw() {
			for(uint32_t i = 0; i < LENGTH; ++i) mValues[i] = static_cast<Scalar>(0);
		}

		P12218319_CALL Vector(const Scalar aValue) throw() {
			for (uint32_t i = 0; i < LENGTH; ++i) mValues[i] = aValue;
		}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 2>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Scalar aY) throw() :
			mValues{ aX, aY }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 3>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Scalar aY, const Scalar aZ) throw() : 
			mValues{aX, aY, aZ} 
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 3>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Vector<2, Scalar> aVector) throw() :
			mValues{ aX, aVector[0], aVector[1] }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 3>::type>
		constexpr P12218319_CALL Vector(const Vector<2, Scalar> aVector, const Scalar aW) throw() :
			mValues{ aVector[0], aVector[1], aW }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Scalar aY, const Scalar aZ, const Scalar aW) throw() :
			mValues{ aX, aY, aZ, aW }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Scalar aY, const Vector<2, Scalar> aVector) throw() :
			mValues{ aX, aY, aVector[0], aVector[1] }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Vector<2, Scalar> aVector, const Scalar aW) throw() :
			mValues{ aX, aVector[0], aVector[1], aW }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Vector<2, Scalar> aVector, const Scalar aZ, const Scalar aW) throw() :
			mValues{ aVector[0], aVector[1], aZ, aW }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Vector<2, Scalar> aLeft, const Vector<2, Scalar> aRight) throw() :
			mValues{ aLeft[0], aLeft[1], aRight[0], aRight[1] }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Scalar aX, const Vector<3, Scalar> aVector) throw() :
			mValues{ aX, aVector[0], aVector[1], aVector[2] }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L == 4>::type>
		constexpr P12218319_CALL Vector(const Vector<3, Scalar> aVector, const Scalar aW) throw() :
			mValues{ aVector[0], aVector[1], aVector[2], aW }
		{}

		template<const uint32_t L = LENGTH, class ENABLE = typename std::enable_if<L != 2 && L != 3 && L != 4>::type>
		P12218319_CALL Vector(const std::initializer_list<Scalar> aValues) throw() {
			const uint32_t size = aValues.size();
			const uint32_t min = size < LENGTH ? size : LENGTH;
			auto it = aValues.begin();
			for(uint32_t i = 0; i < min; ++i, ++it) mValues[i] = *it;
			for (uint32_t i = min; i < LENGTH; ++i) mValues[i] = static_cast<Scalar>(0);
		}

		// Operators

		constexpr Scalar P12218319_CALL operator[](const uint32_t aIndex) const throw() {
			return mValues[aIndex]; 
		}

		inline Scalar& P12218319_CALL operator[](const uint32_t aIndex) throw() {
			return mValues[aIndex]; 
		}

		template<class T2>
		explicit P12218319_CALL operator Vector<LENGTH, T2>() const throw() {
			Vector<LENGTH, T2> tmp;
			for(uint32_t i = 0; i < LENGTH; ++i) tmp.mValues[i] = static_cast<T2>(mValues[i]);
			return tmp;
		}

		// Functions
		Scalar P12218319_CALL Sum() const throw() {
			Scalar tmp = static_cast<Scalar>(0);
			for(uint32_t i = 0; i < LENGTH; ++i) tmp += mValues[i];
			return tmp;
		}

		inline Vector<LENGTH, Scalar> P12218319_CALL DotProduct(const Vector<LENGTH, Scalar> aOther) const throw() {
			return (*this * aOther).Sum();
		}

		template<const uint32_t L = LENGTH>
		typename std::enable_if<L == 3, Vector<LENGTH, Scalar>>::type P12218319_CALL CrossProduct(const Vector<LENGTH, Scalar> aOther) const throw() {
			Vector<LENGTH, Scalar> tmp;
			tmp[0] = (mValues[1] * aOther.mValues[2]) - (mValues[2] * aOther.mValues[1]);
			tmp[1] = (mValues[2] * aOther.mValues[0]) - (mValues[0] * aOther.mValues[2]);
			tmp[2] = (mValues[0] * aOther.mValues[1]) - (mValues[1] * aOther.mValues[0]);
			return tmp;
		}

		inline Scalar P12218319_CALL MagnitudeSquared() const throw() {
			return (*this * *this).Sum();
		}

		inline Scalar P12218319_CALL Magnitude() const throw() {
			return std::sqrt(MagnitudeSquared());
		}

		inline Vector<LENGTH, Scalar> P12218319_CALL LinearInterpolation(const Vector<LENGTH, Scalar> aOther, const Scalar aWeight) const throw() {
			return ((static_cast<Scalar>(1) - aWeight) * *this) + (aWeight * aOther);
		}

		inline Vector<LENGTH, Scalar> P12218319_CALL Normalise() const throw() {
			return *this / Magnitude();
		}

		template<const uint32_t LENGTH2, class T2 = uint8_t>
		Vector<LENGTH2, Scalar> P12218319_CALL Swizzle(const Vector<LENGTH2, T2> aIndices) const throw() {
			Vector<LENGTH2, Scalar> tmp;
			for (uint32_t i = 0; i < LENGTH2; ++i) tmp[i] = mValues[aIndices[i]];
			return tmp;
		}
	};

	template<class T>
	using Vector4 = Vector<4, T>;

	template<class T>
	using Vector3 = Vector<3, T>;

	template<class T>
	using Vector2 = Vector<2, T>;

	#define P12218319_VECTOR_TYPES(aDim)\
	typedef Vector<aDim, double> Vector##aDim##D;\
	typedef Vector<aDim, float> Vector##aDim##F;\
	typedef Vector<aDim, uint64_t> Vector##aDim##U64;\
	typedef Vector<aDim, int64_t> Vector##aDim##I64;\
	typedef Vector<aDim, uint32_t> Vector##aDim##U32;\
	typedef Vector<aDim, int32_t> Vector##aDim##I32;\
	typedef Vector<aDim, uint16_t> Vector##aDim##U16;\
	typedef Vector<aDim, int16_t> Vector##aDim##I16;\
	typedef Vector<aDim, uint8_t> Vector##aDim##U8;\
	typedef Vector<aDim, int8_t> Vector##aDim##I8;\
	typedef Vector<aDim, char> Vector##aDim##C;

	P12218319_VECTOR_TYPES(8)
	P12218319_VECTOR_TYPES(7)
	P12218319_VECTOR_TYPES(6)
	P12218319_VECTOR_TYPES(4)
	P12218319_VECTOR_TYPES(4)
	P12218319_VECTOR_TYPES(3)
	P12218319_VECTOR_TYPES(2)

	#undef P12218319_VECTOR_TYPES
}

#include "VectorOperators.inl"

#endif