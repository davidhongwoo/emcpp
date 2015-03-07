#include <iostream>

class Widget {
public:
	Widget(int a) : m_a(a) {}
	Widget(const Widget&) = delete;
	Widget& operator=(const Widget&) = delete;
private:
	int m_a;
};

class Dog {
public:
	Dog(int a) : m_a(a) {}
	Dog(const Dog&);
	Dog& operator=(const Dog&);
private:
	int m_a;
};

int main() {
	Widget w0(0);

#if 0
	Widget w1(w0);	// call to deleted constructor of 'Widget'
#endif

#if 0
	Widget w2(2);
	w2 = w0;		// overload resolution selected deleted operator '='
#endif

	Dog d0(0);
	Dog d1(d0); 	// main.cpp:34: undefined reference to `Dog::Dog(Dog const&)'
	Dog d2(2);	
	d2 = d0;		// main.cpp:36: undefined reference to `Dog::operator=(Dog const&)'
	return 0;
}
