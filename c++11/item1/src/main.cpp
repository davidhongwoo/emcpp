#include <iostream>
#include <boost/type_index.hpp>
#include <typeinfo>

using namespace std;
using namespace boost::typeindex;

#define PRINT_TYPE(param) do { std::cout << typeid(param).name() << std::endl; } while(0)
#define PRINT_TYPENAME(__TN) do { cout<< "T = " << type_id_with_cvr<__TN>().pretty_name() << "\n"; } while(0)
#define PRINT_PARAM(__PARAM) do { cout<< "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n"; } while(0)

#define PRINT_TYPENAME_PARAM(__TN, __PARAM) do { 							\
	cout<< "T = " << type_id_with_cvr<__TN>().pretty_name() << ",\t" 		\
		<< "param = " << type_id_with_cvr<decltype(param)>().pretty_name()	\
		<< endl;															\
} while(0)

template <typename T>
void f1r(T& param) {
	PRINT_TYPENAME_PARAM(T, param);
}

template <typename T>
void f1p(T* param) {
	PRINT_TYPENAME_PARAM(T, param);
}

template<typename T>
void f1cr(const T& param) {
	PRINT_TYPENAME_PARAM(T, param);
}

template<typename T>
void f2ur(T&& param) {
	PRINT_TYPENAME_PARAM(T, param);
}

template<typename T>
void f3(T param) {
	PRINT_TYPENAME_PARAM(T, param);
}

int main(int argc, char** argv) {
	int i = 1;
	const int ci = i;
	const int* const pi = &ci;
	int& ri = i;
	const int& cri = i;

	cout << "f1r(T& param)" << endl;
	f1r(i);			// T: int, 			param: int& 
	f1r(ci);		// T: const int,	param: const int& 
	f1r(ri);		// T: int,			param: int&
	f1r(cri);		// T: const int,	param: const int&

	cout << "f1p(T* param)" << endl;
	f1p(&i);		// T: int,			param: int*
	f1p(&ci);		// T: const int,	param: const int*
	f1p(pi);		// T: const int,	param: const int*
	f1p(&ri);		// T: int,			param: int*
	f1p(&cri);		// T: const int,	param: const int*

	cout << "f1cr(const T& param)" << endl;
	f1cr(i);		// T: int,			param: const int&
	f1cr(ci);		// T: int,			param: const int&
	f1cr(ri);		// T: int, 			param: const int&
	f1cr(cri);		// T: int, 			param: const int&

	cout << "f2ur(T&& param)" << endl;
	f2ur(i);		// T: int&,			param: int&
	f2ur(ci);		// T: const int&,	param: const int&
	f2ur(2);		// T: int,			param: int&&

	cout << "f3(T param)" << endl;
	f3(i);			// T: int, 			param: int 
	f3(ci);			// T: int,			param: int 
	f3(ri);			// T: int,			param: int
	f3(cri);		// T: int,			param: int

	return 0;
}
