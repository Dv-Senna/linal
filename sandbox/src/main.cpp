#include <exception>
#include <iostream>

#include "linal/linal.hpp"


int main(int, char *[])
{
	try
	{
		linal::Vec2<float> vec1 {};
		linal::Vec2<float> vec2 {1.f};
		linal::Vec2<float> vec3 {2.f, 3.f};
		linal::Vec2<float> vec4 {vec2};
		linal::Vec2<float> vec5 {std::move(vec3)};
		std::cout << vec1 << std::endl;
		std::cout << vec2 << std::endl;
		std::cout << vec3 << std::endl;
		std::cout << vec4 << std::endl;
		std::cout << vec5 << std::endl;
		vec5 += vec2;
		std::cout << vec5 << std::endl;
		vec5 *= 2.f;
		std::cout << vec5 << std::endl;

		std::cout << (vec5 == linal::Vec2(6, 7)) << std::endl;
		std::cout << linal::length(vec5) << std::endl;
		std::cout << linal::lengthSquare(vec5) << std::endl;
	}

	catch (const std::exception &exception)
	{
		std::cerr << "ERROR : " << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}