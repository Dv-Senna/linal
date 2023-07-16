#include "vector.hpp"



namespace linal
{
	template <typename T, size_t D>
	Vector<T, D>::Vector() :
		m_datas {}
	{

	}



	template <typename T, size_t D>
	Vector<T, D>::Vector(const T &fill) :
		Vector()
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] = fill;
	}



	template <typename T, size_t D>
	template <typename ...Args>
	Vector<T, D>::Vector(
		const T &first,
		const T &second,
		Args ...args
	) :
		Vector()
	{
		static_assert(sizeof...(Args) <= D, "linal : vector's variadic must not contains more than D arguments");

		m_datas = {first, second, args...};
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	Vector<T, D>::Vector(const linal::Vector<U, D> &vector) : 
		Vector()
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] = static_cast<U> (vector[i]);
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator=(const linal::Vector<U, D> &vector)
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] = static_cast<U> (vector[i]);
		return *this;
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	Vector<T, D>::Vector(linal::Vector<U, D> &&vector) noexcept :
		Vector()
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] = static_cast<U> (vector[i]);
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator=(linal::Vector<U, D> &&vector) noexcept
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] = static_cast<U> (vector[i]);
		return *this;
	}



	template <typename T, size_t D>
	std::array<T, D> &Vector<T, D>::getDatas() noexcept
	{
		return m_datas;
	}



	template <typename T, size_t D>
	const std::array<T, D> &Vector<T, D>::getDatas() const noexcept
	{
		return m_datas;
	}



	template <typename T, size_t D>
	T &Vector<T, D>::operator[](size_t index)
	{
		if (index >= D)
			throw std::out_of_range("linal : specified index to vector (" + std::to_string(index) + ") must be lower than the vector size (" + std::to_string(D) + ")");

		return m_datas[index];
	}



	template <typename T, size_t D>
	const T &Vector<T, D>::operator[](size_t index) const
	{
		if (index >= D)
			throw std::out_of_range("linal : specified index to vector (" + std::to_string(index) + ") must be lower than the vector size (" + std::to_string(D) + ")");

		return m_datas[index];
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	bool Vector<T, D>::operator==(const linal::Vector<U, D> &vector) const noexcept
	{
		for (size_t i {0}; i < D; i++)
		{
			if (m_datas[i] != vector.m_datas[i])
				return false;
		}

		return true;
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	bool Vector<T, D>::operator!=(const linal::Vector<U, D> &vector) const noexcept
	{
		return !(*this == vector);
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator+=(const linal::Vector<U, D> &vector) noexcept
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] += vector.m_datas[i];
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator-=(const linal::Vector<U, D> &vector) noexcept
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] -= vector.m_datas[i];
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator*=(const U &value) noexcept
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] *= value;
	}



	template <typename T, size_t D>
	template <typename U>
	requires std::is_convertible_v<U, T>
	const linal::Vector<T, D> &Vector<T, D>::operator/=(const U &value) noexcept
	{
		for (size_t i {0}; i < D; i++)
			m_datas[i] /= value;
	}



	template <typename T, size_t D>
	T Vector<T, D>::length() const noexcept
	{
		return sqrt(this->lengthSquare());
	}



	template <typename T, size_t D>
	T Vector<T, D>::lengthSquare() const noexcept
	{
		T res {};
		for (size_t i {0}; i < D; i++)
			res += m_datas[i] * m_datas[i];

		return res;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator+(linal::Vector<T, D> a, const linal::Vector<U, D> &b)
	{
		a += b;
		return a;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator-(linal::Vector<T, D> a, const linal::Vector<U, D> &b)
	{
		a -= b;
		return a;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator*(linal::Vector<T, D> a, const linal::Vector<U, D> &b)
	{
		T res {0};

		for (size_t i {0}; i < D; i++)
			res += a[i] * b[i];

		return res;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator*(linal::Vector<T, D> vector, const U &value)
	{
		vector *= value;
		return value;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator/(linal::Vector<T, D> vector, const U &value)
	{
		vector /= value;
		return value;
	}



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> dot(linal::Vector<T, D> a, const linal::Vector<U, D> &b)
	{
		return a * b;
	}



	template <typename T, size_t  D>
	inline T length(const linal::Vector<T, D> &vector)
	{
		return vector.length();
	}



	template <typename T, size_t  D>
	inline T lengthSquare(const linal::Vector<T, D> &vector)
	{
		return vector.lengthSquare();
	}



} // namespace linal
