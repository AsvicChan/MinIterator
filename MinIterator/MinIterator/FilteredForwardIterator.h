#pragma once
#include <iterator>

template <typename Iterator, typename Filter>
class FilteredForwardIterator : public Iterator
{
private:
	Iterator iterator_;
	Iterator end_;
	Filter* filter_;
public:

	FilteredForwardIterator(Iterator iterator, Iterator end, Filter filter) : iterator_(iterator), end_(end), filter_(filter) 
	{
		if (iterator_ == end_) return;
		while (!filter_(*iterator_))
		{
			++iterator_;
			if (iterator_ == end_) return;
		}
	};

	FilteredForwardIterator(const FilteredForwardIterator& ffi) : iterator_(ffi.iterator_), end_(ffi.end_), filter_(ffi.filter_)
	{

	};

	FilteredForwardIterator operator=(const FilteredForwardIterator& rhs)
	{
		iterator_ = rhs.iterator_;
		end_ = rhs.end_;
		filter_ = rhs.filter_;
		return *this;
	};

	~FilteredForwardIterator()
	{

	};

	Iterator operator*() //works
	{
		return iterator_;
	};

	FilteredForwardIterator& operator++() 
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

	bool operator==(const FilteredForwardIterator& rhs) const 
	{
		return iterator_ == rhs.iterator_;
	};

	bool operator!=(const FilteredForwardIterator& rhs) const 
	{
		return iterator_ != rhs.iterator_;
	};

	FilteredForwardIterator operator++(int)
	{
		FilteredForwardIterator tmp(*this); 
		operator++(); 
		return tmp;
	};

	FilteredForwardIterator()
	{

	};
};