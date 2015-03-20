#include <iostream>
#include <memory>

class Dog {
public:
	int w[1024*1024];
};

std::shared_ptr<Dog> foo() {
	std::shared_ptr<Dog> pDog (new Dog);
	return pDog;
}

int main() {
	Dog* p = new Dog;
	p->w[0] = 1234;

	std::shared_ptr<Dog> pDog1(p);
	std::shared_ptr<Dog> pDog2(p);

	std::cout << "pDog1 count: " << pDog1.use_count() << std::endl;
	std::cout << "pDog2 count: " << pDog2.use_count() << std::endl;
	pDog1.reset();;
	std::cout << "pDog1 count: " << pDog1.use_count() << std::endl;
	std::cout << "pDog2 count: " << pDog2.use_count() << std::endl;

	std::cout << pDog2.get()->w[0] << std::endl;

	return 0;
}




