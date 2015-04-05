#include <iostream>
#include <memory>
#include <string>

class Widget {
public:
	template<typename T>
	void setName(T&& newName) {
		// universal reference를 rvalue로 casting. 
		// lvalue가 넘어오면 rvalue로 casting 되는 상황이 발생. 
		name = std::move(newName);
	}
private:
	std::string name;
};

class Widget2 {
public:
	void setName(const std::string& newName) {
		name = newName;
	}
	void setName(std::string&& newName) {
		name = std::move(newName);
	}
private:
	std::string name;
};

int main() {
	Widget w;;
	auto name = std::string("haha");
	w.setName(name);
	// unknown behavior 
	std::cout << "n: " << name << std::endl;
	return 0;
}

