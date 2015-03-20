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
	std::shared_ptr<Dog> pDog1 (new Dog);
	std::shared_ptr<Dog> pDog2 = pDog1;
	std::shared_ptr<Dog> pDog3 = pDog1;
	std::shared_ptr<Dog> pDog4 = pDog1;
	std::shared_ptr<Dog> pDog5 = pDog1;

	std::cout << "Dog1 use count: " << pDog1.use_count() << std::endl;

	pDog3 = foo();
	std::cout << "Dog1 use count: " << pDog1.use_count() << std::endl;

	pDog3.swap(pDog1);
	std::cout << "Dog1 use count: " << pDog1.use_count() << std::endl;
	std::cout << "Dog3 use count: " << pDog3.use_count() << std::endl;

	pDog1.reset();
	std::cout << "Dog1 use count: " << pDog1.use_count() << std::endl;

	return 0;
}
