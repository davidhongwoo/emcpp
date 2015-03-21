#include <iostream>
#include <memory>

int main() {
	std::shared_ptr<int> sp1(new int);
	std::weak_ptr<int> wp1 = sp1;

	std::cout << "sp1 rc : " << sp1.use_count() << std::endl;
	std::cout << "wp1 rc : " << wp1.use_count() << std::endl;

	std::shared_ptr<int> sp2 = wp1.lock();
	std::cout << "sp1 rc : " << sp1.use_count() << std::endl;
	std::cout << "wp1 rc : " << wp1.use_count() << std::endl;

	sp2.reset();
	std::cout << "sp1 rc : " << sp1.use_count() << std::endl;
	std::cout << "wp1 rc : " << wp1.use_count() << std::endl;

	return 0;
}
