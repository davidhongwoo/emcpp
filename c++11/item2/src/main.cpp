#include <iostream>
#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;

#define PRINT_TYPENAME(__param) do { 													\
	cout << "param (" << #__param << ") " << type_id_with_cvr<decltype(__param)>().pretty_name() << endl;	\
} while(0)

template <typename T>
void f(T param) { }

template <typename T>
void fi(std::initializer_list<T> param) { }


int main(int argc, char** argv) {
	int i = 1;
	const int ci = i;
	const int* const pi = &ci;
	int& ri = i;
	const int& cri = i;

	auto a3_1 = i;
	PRINT_TYPENAME(a3_1);	// int

	const auto a3_2 = i;
	PRINT_TYPENAME(a3_2);	// const int

	auto& a1_1 = i;
	PRINT_TYPENAME(a1_1);	// int&

	const auto& a1_2 = i;
	PRINT_TYPENAME(a1_2);	// const int&

	auto a1_3 = pi;
	PRINT_TYPENAME(a1_3);	// const int&

	auto&& a2_1 = 50;
	PRINT_TYPENAME(a2_1);	// int&&

	auto&& a2_2 = ri;
	PRINT_TYPENAME(a2_2);	// int&

	{
		const char name[] = "mec";
		auto arr1 = name;
		PRINT_TYPENAME(arr1);

		auto& arr2 = name; 
		PRINT_TYPENAME(arr2);
	}

	{
		auto n1 = 1;
		auto n2(2);
		auto n3 = {3};
		auto n4{4};
		//auto n5 = {1, 2, 3, 4.3};		//   error. 

		PRINT_TYPENAME(n1);
		PRINT_TYPENAME(n2);
		PRINT_TYPENAME(n3);
		PRINT_TYPENAME(n4);
	}

	{
		// difference between auto and template when deduce type with initializer_list. 
		//f( {1,2,3});	// compile error: no matching function for call to 'f'
		auto b1 = {1,2,3};

		fi( {1,2,3});	
	}

	return 0;
}

auto someFunc() { return 1; }
//auto someFunc1() { return {1,2,3}; }	// compile error. 
