#pragma once

#include <array>
#include <type_traits>


namespace linal
{
	template <typename T, size_t D>
	requires std::is_arithmetic_v<T> && (D > 0)
	class Vector
	{
		public:
			Vector();
			Vector(const T &fill);
			template <typename ...Args>
			Vector(
				const T &first,
				const T &second,
				Args ...args
			);
			virtual ~Vector() = default;

			template <typename U>
			requires std::is_convertible_v<U, T>
			Vector(const linal::Vector<U, D> &vector);

			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator=(const linal::Vector<U, D> &vector);


			template <typename U>
			requires std::is_convertible_v<U, T>
			Vector(linal::Vector<U, D> &&vector) noexcept;

			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator=(linal::Vector<U, D> &&vector) noexcept;


			inline std::array<T, D> &getDatas() noexcept;
			inline const std::array<T, D> &getDatas() const noexcept;


			inline T &operator[](size_t index);
			inline const T &operator[](size_t index) const;


			template <typename U>
			requires std::is_convertible_v<U, T>
			bool operator==(const linal::Vector<U, D> &vector) const noexcept;

			template <typename U>
			requires std::is_convertible_v<U, T>
			inline bool operator!=(const linal::Vector<U, D> &vector) const noexcept;


			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator+=(const linal::Vector<U, D> &vector) noexcept;

			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator-=(const linal::Vector<U, D> &vector) noexcept;

			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator*=(const U &value) noexcept;

			template <typename U>
			requires std::is_convertible_v<U, T>
			const linal::Vector<T, D> &operator/=(const U &value) noexcept;

			inline T length() const noexcept;
			T lengthSquare() const noexcept;


		protected:
			std::array<T, D> m_datas;
	};



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator+(linal::Vector<T, D> a, const linal::Vector<U, D> &b);

	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator-(linal::Vector<T, D> a, const linal::Vector<U, D> &b);

	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator*(linal::Vector<T, D> a, const linal::Vector<U, D> &b);

	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator*(linal::Vector<T, D> vector, const U &value);

	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	linal::Vector<T, D> operator/(linal::Vector<T, D> vector, const U &value);



	template <typename T, typename U, size_t D>
	requires std::is_convertible_v<U, T>
	inline linal::Vector<T, D> dot(linal::Vector<T, D> a, const linal::Vector<U, D> &b);

	template <typename T, size_t  D>
	inline T length(const linal::Vector<T, D> &vector);

	template <typename T, size_t  D>
	inline T lengthSquare(const linal::Vector<T, D> &vector);


} // namespace linal


#include "vector.inl"