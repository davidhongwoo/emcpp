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

bool isLucky(int number) { return number == 10; }

bool isHappy(int n) { return n > 0; }
bool isHappy(char) = delete;
bool isHappy(double) = delete;

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
#if 0
	Dog d1(d0); 	// main.cpp:34: undefined reference to `Dog::Dog(Dog const&)'
	Dog d2(2);	
	d2 = d0;		// main.cpp:36: undefined reference to `Dog::operator=(Dog const&)'
#endif 

	isLucky(10);
	isLucky('a');
	isLucky(3.4);	// warning: implicit conversion from 'double' to 'int' changes value from 3.4 to 3

	isHappy(0);
#if 0
	isHappy('b');	// error: call to deleted function 'isHappy'
	isHappy(4.3);	// error: call to deleted function 'isHappy'
#endif

	return 0;
}
