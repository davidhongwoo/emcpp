#include <iostream>
#include <unordered_map>
#include <string>

class Dog {
public:
	int age;
	int weight;
	Dog(int a, int w):age(a), weight(w) {};
	
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
		{ {3, 10}, "Ann" },
		{ {4, 11}, "Lucy" },
		{ {5, 15}, "Dave" },
		{ {6, 20}, "Mike" }
	};

	//for (std::pair<Dog, std::string>& i : m) 
	//	do something ;;; 
	//
	//error: invalid initialization of reference of type ‘std::pair<Dog, std::basic_string<char> >&’ from expression of type ‘std::pair<const Dog, std::basic_string<char> >’

	for (std::pair<const Dog, std::string>& i : m) 
		std::cout << "age: " << i.first.age << ", weight: " << i.first.weight << " best friend: " << i.second << std::endl;

	for (auto& i : m) 
		(&i)->second = "haha";

	for (auto& i : m) 
		std::cout << "age: " << i.first.age << ", weight: " << i.first.weight << " best friend: " << i.second << std::endl;

	for (std::pair<const Dog, std::string>& i : m) 
		(&i)->second = "hoho";

	for (auto& i : m) 
		std::cout << "age: " << i.first.age << ", weight: " << i.first.weight << " best friend: " << i.second << std::endl;

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
