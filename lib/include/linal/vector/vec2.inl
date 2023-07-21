#include <cmath>

#include "vec2.hpp"



namespace linal
{
	template <class T>
	requires std::is_arithmetic_v<T>
	Vec2<T>::Vec2() : x {}, y {}
	{

	}



	template <class T>
	requires std::is_arithmetic_v<T>
	Vec2<T>::Vec2(T fill) : x {fill}, y {fill}
	{

	}



	template <class T>
	requires std::is_arithmetic_v<T>
	Vec2<T>::Vec2(T x, T y) : x {x}, y {y}
	{

	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	Vec2<T>::Vec2(const linal::Vec2<U> &vector) : x {vector.x}, y {vector.y}
	{

	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator=(const linal::Vec2<U> &vector)
	{
		x = vector.x;
		y = vector.y;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	Vec2<T>::Vec2(linal::Vec2<U> &&vector) noexcept : x {vector.x}, y {vector.y}
	{

	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator=(linal::Vec2<U> &&vector) noexcept
	{
		x = vector.x;
		y = vector.y;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator+=(const linal::Vec2<U> &vector)
	{
		x += vector.x;
		y += vector.y;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator-=(const linal::Vec2<U> &vector)
	{
		x -= vector.x;
		y -= vector.y;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator*=(U value)
	{
		x *= value;
		y *= value;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	const linal::Vec2<T> &Vec2<T>::operator/=(U value)
	{
		x /= value;
		y /= value;
		return *this;
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	template <class U>
	requires std::is_convertible_v<U, T>
	bool Vec2<T>::operator==(const linal::Vec2<U> &vector) const noexcept
	{
		return x == static_cast<T> (vector.x) && y == static_cast<T> (vector.y);
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	T Vec2<T>::length() const noexcept
	{
		return sqrt(this->lengthSquare());
	}



	template <class T>
	requires std::is_arithmetic_v<T>
	T Vec2<T>::lengthSquare() const noexcept
	{
		return x*x + y*y;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	T dot(const linal::Vec2<T> &a, const linal::Vec2<U> &b)
	{
		return a.x * b.x + a.y * b.y;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	linal::Vec2<T> operator+(linal::Vec2<T> a, const linal::Vec2<U> &b)
	{
		a += b;
		return a;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	linal::Vec2<T> operator-(linal::Vec2<T> a, const linal::Vec2<U> &b)
	{
		a -= b;
		return a;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	linal::Vec2<T> operator*(linal::Vec2<T> a, U value)
	{
		a *= value;
		return a;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	linal::Vec2<T> operator/(linal::Vec2<T> a, U value)
	{
		a /= value;
		return a;
	}



	template <class T, class U>
	requires std::is_convertible_v<U, T>
	T operator*(const linal::Vec2<T> &a, const linal::Vec2<U> &b)
	{
		return linal::dot(a, b);
	}



	template <class T>
	inline T length(const linal::Vec2<T> &vector)
	{
		return vector.length();
	}



	template <class T>
	inline T lengthSquare(const linal::Vec2<T> &vector)
	{
		return vector.lengthSquare();
	}



	template <class T>
	std::ostream &operator<<(std::ostream &stream, const linal::Vec2<T> &vector)
	{
		stream << vector.x << ", " << vector.y;
		return stream;
	}



} // namespace linal
