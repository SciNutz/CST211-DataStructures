#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "adt_exception.hpp"
using namespace std;


template <class T>
class dynamic_array
{
public:
	explicit dynamic_array();
	~dynamic_array();
	explicit dynamic_array(size_t length, int start_index = 0);
	explicit dynamic_array(const dynamic_array<T>& array);
	explicit dynamic_array(const T array[], size_t size);
	dynamic_array<T>& operator=(const dynamic_array<T>& rhs);     // copy constructor
	explicit dynamic_array(dynamic_array<T>&& array) noexcept;		      // Move Constructor
	dynamic_array<T>& operator=(dynamic_array<T>&& rhs) noexcept;
	T& operator[](int index);
	T operator[](int index) const;
	explicit operator bool();
	int get_start_index() const;
	size_t get_length() const;
	void set_start_index(int start_index);
	void set_length(size_t length);

private:

	T * storage_ = nullptr;
	size_t length_;
	int start_index_;

};

template <class T>
dynamic_array<T>::dynamic_array() : length_(0), start_index_(0)
{
	//cout << "1D Array Constructor created ..." << endl;

	if (!(storage_ = new T[length_])) 
	{
		////cout << "**Exception Thrown - Memory Allocation Failed" << endl;
		throw adt_exception("Memory Allocation Failed");
	}
	else
	{
		if (storage_ != nullptr)
		{
			delete[] storage_;
			storage_ = nullptr;
		}

		length_ = 0;
		start_index_ = 0;
	}
}

template <class T>
dynamic_array<T>::~dynamic_array()
{


	if (storage_ != nullptr)
	{
		delete[] storage_;
		storage_ = nullptr;
	}

	length_ = 0;
	start_index_ = 0;
	
	//cout << "1D -- its Gone - Deleted 1D Array Constructor" << endl;
	
}

template <class T>
dynamic_array<T>::dynamic_array(size_t length, int start_index) : start_index_(start_index)
{

	try
	{

		//cout << "1D User specified Array Constructor " << endl;
		length_ = length;
		storage_ = new T[length_];
	}
	catch (std::bad_alloc & exception)
	{
		////cout << "**Exception Thrown - Negative Length" << endl;
		throw adt_exception(exception.what());
	}
	////cout << "Length = " << length << " and beginning index = " << start_index << endl;


}

template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& array):storage_(nullptr), length_(array.get_length()), start_index_(array.get_start_index())
{
	//cout << "1D Copy Constructor array" << endl;

	try
	{
		//cout << "1D User specified Array Constructor " << endl;
		storage_ = new T[length_];
	}
	catch (std::bad_alloc & exception)
	{
		////cout << "**Exception Thrown - Negative Length" << endl;
		throw adt_exception(exception.what());
	}
	
	for (int i = 0; i < length_; i++)
	{
		storage_[i] = array.storage_[i];
	}
}

template <class T>
dynamic_array<T>::dynamic_array(const T array[], size_t size): length_(size), start_index_(0)
{
	if (storage_ != nullptr)
	{
		delete[] storage_;
		storage_ = nullptr;
	}

	try 
	{
		//cout << "1D User specified Array Constructor #2 - array" << endl;
		storage_ = new T[length_];
	}
	catch (std::bad_alloc & exception)
	{
		////cout << "**Exception Thrown - Negative Length" << endl;
		throw adt_exception(exception.what());
	}

	for (int i=0; i < size; i++)
	{
		storage_[i] = array[i];
	}

	//cout << "1D Creating a defined array" << endl;
	
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& rhs)
{
	//cout << "1D Assignment (=) operator - rhs " << endl;
	if (this != &rhs)
	{

		length_ = rhs.get_length();
		start_index_ = rhs.get_start_index();

		if (!(storage_ = new T[length_]))
		{
			////cout << "Exception Thrown - Memory Allocation Failed" << endl;
			throw adt_exception("Memory Allocation Failed");
		}
		else
		{
			delete[] storage_;
			//cout << "1D deleted storage_" << endl;
			storage_ = new T[length_];
			//cout << "1D created a new storage_ ..." << endl;

			for (int i = 0; i < length_; i++)
			{
				storage_[i] = rhs.storage_[i];
			}
		}

	}
	return *this;
}

template <class T>
dynamic_array<T>::dynamic_array(dynamic_array<T>&& array) noexcept: length_(0), start_index_(0)
{
	//cout << "1D Move Constructor? from Array to storage" << endl;

	*this = std::move(array);
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& rhs) noexcept
{
	//cout << "1D Move Constructor from rhs to storage. " << endl;
	if (this != &rhs)
	{
		if (storage_ != nullptr)
			delete[]storage_;
		
		storage_ = rhs.storage_;
		length_ = rhs.length_;
		start_index_ = rhs.start_index_;

		rhs.storage_ = nullptr;
	}
	
	return *this;
}

template <class T>
T& dynamic_array<T>::operator[](int index)
{
	//cout << "1D Assignment [] operator " << endl;
	/*
	if (index < start_index_ || index >= length_ - abs(start_index_))
	{
		////cout << "**Exception thrown: Index out of bounds" << endl;
		throw adt_exception("out of bounds");
	}*/
	auto test_index = index - start_index_;
	if (test_index >= length_ || index < start_index_)
	{
		////cout << "**Exception thrown: Index out of bounds" << endl;
		throw adt_exception("out of bounds");
	}
	return storage_[test_index];

}

template <class T>
T dynamic_array<T>::operator[](int index) const
{ // This Operator is used to access a part of the array ... 

	//cout << "1D Assignment [] const operator " << endl;

	if (index < start_index_ || index >= length_ - abs(start_index_))
	{
		////cout << "**Exception thrown: Index out of bounds" << endl;
		throw adt_exception("out of bounds");
	}
	return storage_[index + abs(start_index_)];

}

template <class T>
dynamic_array<T>::operator bool()
{
	if (storage_ != nullptr)
	{
		//cout << "1D operator bool() true" << endl;
		return true;
	}
	else
	{
		//cout << "1D operator bool() false" << endl;
		return false;
	}
}

template <class T>
int dynamic_array<T>::get_start_index() const
{
	//cout << "1D get_Start_Index = " << start_index_ << endl;
	return start_index_;
}

template <class T>
size_t dynamic_array<T>::get_length() const
{
	//cout << "1D get_Length = " << length_ << endl;
	return length_;
}

template <class T>
void dynamic_array<T>::set_start_index(int start_index)
{
	//cout << "1D set_Start_Index " << endl;
	start_index_ = start_index;
}

template <class T>
void dynamic_array<T>::set_length(size_t length)
{
	try
	{
		T * temp = new T[length];
		auto const actual_length = (length_ < length) ? length_ : length;

		for (int i = 0; i < actual_length; i++)
		{
			temp[i] = storage_[i];
		}

		delete[]storage_;
		length_ = length;
		//cout << "1D set_length = " << length_ << endl;

		storage_ = temp;

	}
	catch (std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}


#endif
