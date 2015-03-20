#include <iostream>
#include <memory>
#include <vector>

class Dog;
std::vector<std::shared_ptr<Dog>> T_History;

class Dog {
public:
	int w[1024*1024];
	void process() {
		T_History.emplace_back(this);
	}
};

class Cat;
std::vector<std::shared_ptr<Cat>> T_CatHistory;

class Cat : public std::enable_shared_from_this<Cat> {
public:
	template<typename... Ts>
	static std::shared_ptr<Cat> create(Ts&&... params) {};

	void process() {
		T_CatHistory.emplace_back(shared_from_this());
	}
private:
	template<typename... Ts>
	Cat(Ts&&... params) {};
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




