#pragma once

#include <ostream>
#include <type_traits>


namespace linal
{
	template <class T>
	requires std::is_arithmetic_v<T>
	class Vec2 final
	{
		public:
			Vec2();
			Vec2(T fill);
			Vec2(T x, T y);
			~Vec2() = default;

			template <class U>
			requires std::is_convertible_v<U, T>
			Vec2(const linal::Vec2<U> &vector);
			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator=(const linal::Vec2<U> &vector);

			template <class U>
			requires std::is_convertible_v<U, T>
			Vec2(linal::Vec2<U> &&vector) noexcept;
			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator=(linal::Vec2<U> &&vector) noexcept;

			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator+=(const linal::Vec2<U> &vector);

			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator-=(const linal::Vec2<U> &vector);

			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator*=(U value);

			template <class U>
			requires std::is_convertible_v<U, T>
			const linal::Vec2<T> &operator/=(U value);

			template <class U>
			requires std::is_convertible_v<U, T>
			inline bool operator==(const linal::Vec2<U> &vector) const noexcept;


			inline T length() const noexcept;
			inline T lengthSquare() const noexcept;


			T x, y;
	};


	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline T dot(const linal::Vec2<T> &a, const linal::Vec2<U> &b);


	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline linal::Vec2<T> operator+(linal::Vec2<T> a, const linal::Vec2<U> &b);

	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline linal::Vec2<T> operator-(linal::Vec2<T> a, const linal::Vec2<U> &b);

	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline linal::Vec2<T> operator*(linal::Vec2<T> a, U value);

	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline linal::Vec2<T> operator/(linal::Vec2<T> a, U value);

	template <class T, class U>
	requires std::is_convertible_v<U, T>
	inline T operator*(const linal::Vec2<T> &a, const linal::Vec2<U> &b);



	template <class T>
	inline T length(const linal::Vec2<T> &vector);

	template <class T>
	inline T lengthSquare(const linal::Vec2<T> &vector);



	template <class T>
	std::ostream &operator<<(std::ostream &stream, const linal::Vec2<T> &vector);


	using Vec2f = Vec2<float>;
	using Vec2d = Vec2<double>;
	using Vec2ld = Vec2<long double>;
	using Vec2i8 = Vec2<int8_t>;
	using Vec2u8 = Vec2<uint8_t>;
	using Vec2i16 = Vec2<int16_t>;
	using Vec2u16 = Vec2<uint16_t>;
	using Vec2i32 = Vec2<int32_t>;
	using Vec2u32 = Vec2<uint32_t>;
	using Vec2i64 = Vec2<int64_t>;
	using Vec2u64 = Vec2<uint64_t>;
	using Vec2i = Vec2i32;
	using Vec2u = Vec2u32;


} // namespace linal


#include "vec2.inl"