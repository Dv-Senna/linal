#pragma once



#ifndef NDEBUG

	#include <stdexcept>

	#define LINAL_ASSERT(cond, msg) if (!(cond)) throw std::logic_error("linal assert in file '" + std::string(__FILE__) + "', line " + std::to_string(__LINE__) + " failed : " + std::string(#cond) + " : " + msg)

#else

	#define LINAL_ASSERT(cond, msg)

#endif
