#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>
#include "adt_exception.hpp"

using std::ostream;

template <class F, class S>
class pair final
{

public:
	pair() = delete;
	~pair();		// De-constructor
	pair(const F& first, const S& second) noexcept(false);

	pair(const pair& my_pair) noexcept(false);
	pair& operator=(const pair& rhs) noexcept(false);

	pair(pair&& my_pair) noexcept;
	pair& operator=(pair&& rhs) noexcept;

	bool operator==(const pair& pair2) const noexcept;
	friend ostream& operator<<(ostream& in, const pair& my_pair);
	
	F& get_first() const;
	S& get_second() const;

	void set_first(const F& new_first);
	void set_second(const S& new_second);

	static pair* make_pair(const F& first, const S& seond);

private:
	F* first_ = nullptr;
	S* second_ = nullptr;

};



template <class F, class S>
pair<F, S>::pair(const F& first, const S& second) noexcept(false)
{
	try
	{
		first_ = new F(first);
		second_ = new S(second);
	}
	catch (std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}


template <class F, class S>
pair<F, S>::~pair()
{
	if (first_ != nullptr) delete first_;
	if (second_ != nullptr) delete second_;
}

template <class F, class S>
pair<F, S>::pair(const pair& my_pair) noexcept(false)
{
	*this = my_pair;
}

template <class F, class S>
pair<F, S>& pair<F, S>::operator=(const pair& rhs) noexcept(false)
{
	if (this != &rhs)
	{
		if (first_ != nullptr) delete first_;
		if (second_ != nullptr) delete second_;

		first_ = new F(*rhs.first_);
		second_ = new S(*rhs.second_);
	}
	return *this;
}

template <class F, class S>
pair<F, S>::pair(pair&& my_pair) noexcept
{
	*this = std::move(my_pair);
}

template <class F, class S>
pair<F, S>& pair<F, S>::operator=(pair&& rhs) noexcept
{
	if (this != &rhs)
	{
		if (first_ != nullptr) delete first_;
		if (second_ != nullptr) delete second_;

		first_ = rhs.first_;
		second_ = rhs.second_;

		rhs.first_ = nullptr;
		rhs.second_ = nullptr;
	}
	return *this;
}

template <class F, class S>
bool pair<F, S>::operator==(const pair& pair2) const noexcept
{
	return *first_ == *pair2.first_ && *second_ == *pair2.second_;
}



template <class F, class S>
ostream & operator<<(ostream & in, const pair<F, S> & my_pair)
{
	in << *my_pair.first_ << " " << *my_pair.second_;
	return in;
}



template <class F, class S>
F& pair<F, S>::get_first() const
{
	return *first_;
}

template <class F, class S>
S& pair<F, S>::get_second() const
{
	return *second_;
}

template <class F, class S>
void pair<F, S>::set_first(const F& new_first)
{
	*first_ = new_first;
}

template <class F, class S>
void pair<F, S>::set_second(const S& new_second)
{
	*second_ = new_second;
}

template <class F, class S>
pair<F, S>* pair<F, S>::make_pair(const F& first, const S& seond)
{
	return new pair<F, S>(first, seond);
}



#endif
