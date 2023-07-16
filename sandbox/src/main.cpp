#include <exception>
#include <iostream>

#include "linal/linal.hpp"


int main(int, char *[])
{
	try
	{
		linal::Vector<float, 2> vec1 {};
		linal::Vector<int, 2> vec2 {1, 2};
		vec1 = vec2;
		std::cout << vec1[0] << ", " << vec1[1] << std::endl;
	}

	catch (const std::exception &exception)
	{
		std::cerr << "ERROR : " << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}