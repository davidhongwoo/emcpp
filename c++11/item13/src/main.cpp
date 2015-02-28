#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/type_index.hpp>

using namespace boost::typeindex;

#define PRINT_TYPENAME(__param) do { 									\
	std::cout << "param (" << #__param << ") "							\
				<< type_id_with_cvr<decltype(__param)>().pretty_name()	\
				<< std::endl;	\
} while(0)

int main() {

	std::vector<int> v = {1, 2, 3,4, 1993, 2014};
	std::vector<int>::iterator vi = std::find(v.begin(), v.end(), 1993);
	v.insert(vi, 1998);

	auto it = std::find(v.cbegin(), v.cend(), 1993);
	PRINT_TYPENAME(it);
	// param (it) __gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >
	//v.insert(it, 1998); //no matching member function for call to 'insert'  

	auto it2 = std::find(std::begin(v), std::end(v), 1993);
	PRINT_TYPENAME(it2);
	// param (it2) __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >
	v.insert(it2, 1998); // compile ok

	return 0;
}
