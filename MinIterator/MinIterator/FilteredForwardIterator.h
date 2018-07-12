#pragma once
#include <iterator>

template <typename Iterator, typename Filter>
class FilteredIterator : public Iterator
{
private:
	Iterator iterator_;
	Iterator end_;
	Filter* filter_;
public:

	FilteredIterator(Iterator iterator, Iterator end, Filter filter) : iterator_(iterator), end_(end), filter_(filter) 
	{
		if (iterator_ == end_) return;
		while (!filter_(*iterator_))
		{
			++iterator_;
			if (iterator_ == end_) return;
		}
	};

	FilteredIterator(const FilteredIterator& ffi) : iterator_(ffi.iterator_), end_(ffi.end_), filter_(ffi.filter_)
	{

	};

	FilteredIterator operator=(const FilteredIterator& rhs)
	{
		iterator_ = rhs.iterator_;
		end_ = rhs.end_;
		filter_ = rhs.filter_;
		return *this;
	};

	~FilteredIterator()
	{

	};

	decltype(*iterator_) operator*() //works
	{
		return *iterator_;
	};

	FilteredIterator& operator++() 
	{
		if (iterator_ == end_) return *this;
		++iterator_;
		if (iterator_ == end_) return *this;
		while (!filter_(*iterator_))
		{
			++iterator_;
			if (iterator_ == end_) return *this;
		}
		return *this;
	};

	bool operator==(const FilteredIterator& rhs) const 
	{
		return iterator_ == rhs.iterator_;
	};

	bool operator!=(const FilteredIterator& rhs) const 
	{
		return iterator_ != rhs.iterator_;
	};

	FilteredIterator operator++(int)
	{
		FilteredIterator tmp(*this); 
		operator++(); 
		return tmp;
	};

	FilteredIterator()
	{

	};
};