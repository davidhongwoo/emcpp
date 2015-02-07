#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>

class Number {
public:
	std::vector<unsigned long> m_list;
	Number() {
		m_list.clear();
	}
	Number(int start, int end) {
		for (auto i = start; i < end; i ++) {
			m_list.push_back(i);
		}
	}
};

// TODO 
// 서로 다른 타입을 리턴하는 함수를 만들 수 있나 ?? 
// closure 를 auto로 받을 때 메모리 사용량. std::function으로 받을 때 메모리 사용량을 확인할 수 있는 예제를 만들자. 

int main() {
#if 1
	auto addFunc = [](const Number& p1, const Number& p2, Number& result) { 
			// TODO. some more heavy code .... 
			unsigned long index = 0;
			auto p2Size = p2.m_list.size();
			unsigned long array[p2Size];
			for (auto i : p1.m_list) {
				if (p2Size < index)
					break;
				if ((i * (p2.m_list.at(index) % (index+191))) % 299) {
					array[i] = i;
					//result.m_list.push_back(i);
				}
				index++;	
			}
			for (auto& i : array) {
				i = i * p1.m_list.front();
			}
			return true; 
		};
#else
	std::function<bool(const Number&, const Number&, Number&)>
		addFunc = [](const Number& p1, const Number& p2, Number& result) { 
			unsigned long index = 0;
			auto p2Size = p2.m_list.size();
			for (auto i : p1.m_list) {
				if (p2Size < index)
					break;
				if ((i * (p2.m_list.at(index) % (index+191))) % 299) {
					result.m_list.push_back(i);
				}
				index++;	
			}
			return true; 
		};
#endif

	//Number n1(100, 1000000);
	//Number n2(2000, 3000000);
	//Number n3;

	//addFunc(n1, n2, n3);

	//for(auto i : n3.m_list) {
		//if (i != 0 && i % 171 == 0)
			//std::cout << i << std::endl;
	//}

	auto j = 0;
	auto k = 0;
	while(true) {
		Number n1(j, j+100000);
		Number n2(k, k+100000);
		Number n3;

		addFunc(n1, n2, n3);

		k = n3.m_list.size();
		
		if (j++ > 1000)
			break;
	}
	
	return 0;
}

