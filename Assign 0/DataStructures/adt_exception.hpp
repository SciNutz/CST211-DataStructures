#ifndef ADTEXCEPTION_HPP
#define ADTEXCEPTION_HPP
#include <exception>
#include <string>

class adt_exception : public std::exception
{
public:
	explicit adt_exception(const char * what)
		: exception(what) { }

	const wchar_t * adt_what() const;

	friend std::ostream& operator<<(std::ostream& stream, const adt_exception& exception)
	{
		stream << exception.what() << "\n";
		return stream;
	}
};
#endif