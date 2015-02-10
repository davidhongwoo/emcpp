#include <iostream>
#include <vector>

using namespace std;

class Widget {
private:
	int a;
public:
	Widget() {
		cout << "default cons" << endl;
	}

	Widget(const Widget& w) {
		this->a = w.a;
		cout << "copy cons" << endl;
	}

	Widget& operator=(const Widget& w) {
		this->a = w.a;
		cout << "assign op" << endl;
		return *this;
	}
};

int main() {
	int x(0);
	int y = 0;
	int z{0};
	int z1 = {0};

	cout << x << y << z << z1 << endl;	


	// review copy cons, assignment operator 
	{
		Widget w1;
		Widget w2 = w1;
		Widget w3;
		w3 = w2;
	}

	// uniform initialization 
	{
		vector<int> v {1, 4, 5};
	}

	// 
	{
		vector<int> v1 (10, 20);
		cout << "size of v1: " << v1.size() << endl;

		vector<int> v2 {10, 20};
		cout << "size of v2: " << v2.size() << endl;
	}

	/*
	 * Braced initialization is the most widely usable initialization syntax, 
	 * it prevents narowing conversions, 
	 * and it's immune to C++;s most vexing parse. 
	 *
	 * During contructor overload resolution, 
	 * braced initializers are matched to std::initializer_list parameters if at all possble, 
	 * even if other constructors seemingly better matches
	 *
	 * An example of where the choice between parentheses and braces can make a significant difference 
	 * is creating a std::vector<numeric tyupe> with two arguments.
	 *
	 * Choosing between parentheses and braces for object creation inside templates can be challenging. 
	 **/

	return 0;
}
