#include <iostream>
#include <vector>
#include <functional>

class DataObject {
public:
	typedef std::function<int (const DataObject&)> FuncType;
	explicit DataObject(int data, FuncType ft) : m_data(data), m_funcType(ft) {}
	int getHealth() const { return m_funcType(*this); }
	int m_data;
private:
	FuncType m_funcType;
};

int SimpleIntCalc(const DataObject& d) { return d.m_data*1; }
struct FunctorCalc {
public:
	int operator () (const DataObject& d) const { return d.m_data*3; }
};


int main() {
	DataObject o1(10, SimpleIntCalc);
	FunctorCalc h;
	DataObject o2(20, h);
	DataObject o3(30, [] (const DataObject&) { return 30; });

	std::vector<DataObject> l = {o1, o2, o3};
	for (DataObject& i : l) 
		std::cout << i.getHealth() << std::endl;
	return 0;
}
