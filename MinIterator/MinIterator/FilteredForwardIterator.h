#pragma once
#include <iterator>

template <class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T * , class Reference = T & >
	struct MyIterator {
	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};

template <typename Iterator, typename Filter>
class FilteredIterator : public MyIterator<std::forward_iterator_tag, Iterator>
{
private:
	Iterator iterator_;
	Iterator end_;
	Filter* filter_;
public:

	FilteredIterator(Iterator iterator, Iterator end, Filter filter) : iterator_(iterator), end_(end), filter_(filter) 
	{
		while ((iterator_ != end_) && (!filter_(*iterator_)))
		{
			++iterator_;
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
		while ((iterator_ != end_) && (!filter_(*iterator_)))
		{
			++iterator_;
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