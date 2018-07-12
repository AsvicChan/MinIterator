#include <iostream>
#include <algorithm>
#include "FilteredForwardIterator.h"
#include <vector>

bool filter(int n)
{
	if (n % 2 == 0) return true;
	return false;
};

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	FilteredForwardIterator<decltype(vec.begin()), bool(int)> first(vec.begin(),vec.end(), filter);
	FilteredForwardIterator<decltype(vec.end()), bool(int)> second(vec.end(), vec.end(), filter);
	second=std::min_element(first, second);
	std::cout << *(*second);
	system("pause");
	return 0;
};