#include <iostream>
#include <unordered_map>
#include <string>

class Dog {
public:
	int age;
	Dog(int a):age(a) {};

	Dog( const Dog &obj) {
		this->age = obj.age;
		std::cout << "Dog copy constructor, age: " << obj.age << std::endl;
	}
	
	bool operator==(const Dog& other) const {
		return (age == other.age);
	}
};

namespace std {
	template <> 
	struct hash<Dog> {
		std::size_t operator()(const Dog& dog) const {
			return hash<int>()(dog.age);
		}
	};
};


int main(int argc, char** argv) {
	std::unordered_map<Dog, std::string> m = { 
		{ {3}, "Ann" },
		{ {4}, "Lucy" },
		{ {5}, "Dave" },
		{ {6}, "Mike" }
	};

	std::cout << "const pair<Dog, >" << std::endl;
	for (const std::pair<Dog, std::string>& i : m)  { // copy constructor is called. 
		std::cout << "age: " << i.first.age << " best friend: " << i.second << std::endl;
	}

	std::cout << "pair<const Dog, >" << std::endl;
	for (std::pair<const Dog, std::string>& i : m)  { // copy constructor isn't called.
		std::cout << "age: " << i.first.age << " best friend: " << i.second << std::endl;
		(&i)->second = "haha";
	}

	std::cout << "auto " << std::endl;
	for (auto& i : m) { // copy constructor isn't called.
		std::cout << "age: " << i.first.age << " best friend: " << i.second << std::endl;
	}

	std::unordered_map<std::string, std::string> ms = {
		{"aaa", "11111"},
		{"bbb", "21111"},
		{"ccc", "31111"},
		{"ddd", "41111"}
	};

	for (std::pair<const std::string, std::string>& i : ms) 
		std::cout << i.first << " " << i.second << std::endl;	
	return 0;
}
