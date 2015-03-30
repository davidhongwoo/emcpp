#include <iostream>
#include <string>
#include <memory>
#include <utility>

class ColorInfo {
public:
	int r, g, b;
};

class Widget {
public:
	Widget(std::string&& str) : name(str) {}
	//Widget(Widget&& rhs) : name(std::move(rhs.name)) {}
	Widget(Widget&& rhs) : name(std::forward(rhs.name)) {}
	~Widget() {}

private:
	std::string name;
	std::shared_ptr<ColorInfo> pColorInfo;
};

int main() 
{
	Widget* w = new Widget("aa");
	//std::cout << w->name << std::endl;
	return 0;
}
