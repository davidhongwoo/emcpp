#include <iostream>
#include <vector>
#include <string>
#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;

#define PRINT_TYPENAME(__param) do { 													\
	cout << "param (" << #__param << ") " \
		 << type_id_with_cvr<decltype(__param)>().pretty_name() \
		 << endl;	\
} while(0)

template<typename T>
void f(std::vector<T>&& param) {
	// rvalue reference 
	PRINT_TYPENAME(param);
}

int main() {
	f(std::vector<std::string>({"hello"}));

#if 0
	//std::string str("hello");
	//std::vector<std::string> v;
	//v.push_back(str);
	//f(v);
	////no known conversion from 'std::vector<std::string>' to 'std::vector<basic_string<char> > &&'
#endif

	return 0;
}
