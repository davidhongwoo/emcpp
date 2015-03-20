// shared_ptr constructor example
#include <iostream>
#include <memory>

struct C {int* data;};

int main () {
	std::shared_ptr<int> p1;
	std::shared_ptr<int> p2 (nullptr);
	std::shared_ptr<int> p3 (new int);
	std::shared_ptr<int> p4 (new int, std::default_delete<int>());
	std::shared_ptr<int> p5 (new int, [](int* p){delete p;}, std::allocator<int>());
	std::shared_ptr<int> p6 (p5);
	std::shared_ptr<int> p7 (std::move(p6));
	std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));
	std::shared_ptr<C> obj (new C);
	std::shared_ptr<int> p9 (obj, obj->data);

	std::cout << "use_count:\n";
	std::cout << "p1: " << p1.use_count() << "	  p1: " << sizeof(p1) << '\n';
	std::cout << "p2: " << p2.use_count() << "	  p2: " << sizeof(p2) << '\n';
	std::cout << "p3: " << p3.use_count() << "	  p3: " << sizeof(p3) << '\n';
	std::cout << "p4: " << p4.use_count() << "	  p4: " << sizeof(p4) << '\n';
	std::cout << "p5: " << p5.use_count() << "	  p5: " << sizeof(p5) << '\n';
	std::cout << "p6: " << p6.use_count() << "	  p6: " << sizeof(p6) << '\n';
	std::cout << "p7: " << p7.use_count() << "	  p7: " << sizeof(p7) << '\n';
	std::cout << "p8: " << p8.use_count() << "	  p8: " << sizeof(p8) << '\n';
	std::cout << "p9: " << p9.use_count() << "	  p9: " << sizeof(p9) << '\n';
	return 0;
}
