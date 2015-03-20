#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Dog {
public:
	int w[1024*1024];
};

shared_ptr<Dog> foo() {
	shared_ptr<Dog> pDog (new Dog);
	return pDog;
}

int main() {
	auto dogDel = [](Dog *p) {
		cout << p << endl;
		delete p;
	};

	unique_ptr<Dog, decltype(dogDel)> up(new Dog, dogDel); 
	shared_ptr<Dog> sp(new Dog, dogDel);                   

	auto customDeleter1 = [](Dog* p) { 
		cout << "deleter1" << endl;
		delete p; 
	};
	auto customDeleter2 = [](Dog* p) { 
		cout << "deleter2" << endl;
		delete p; 
	};

	shared_ptr<Dog> pDog1(new Dog, customDeleter1);
	shared_ptr<Dog> pDog2(new Dog, customDeleter2);

	vector<shared_ptr<Dog>> v = {pDog1, pDog2};
	
	return 0;
}



