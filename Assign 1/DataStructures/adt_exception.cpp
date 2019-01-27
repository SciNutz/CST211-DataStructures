#include "adt_exception.hpp"

const wchar_t * adt_exception::adt_what() const
{
	std::string str = exception::what();
	std::wstring wide_str(str.length(), L' ');

	std::copy(str.begin(), str.end(), wide_str.begin());

	return wide_str.c_str();
}