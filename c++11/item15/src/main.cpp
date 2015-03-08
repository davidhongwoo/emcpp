#include <iostream>
using namespace std;

#if 0
long long factorial(long long x) {
	return x > 2 ? x + factorial(x-1) : 1;
}
#else
constexpr long long factorial(long long x) {
	return x > 0 ? x * factorial(x-1) : 1;
}
#endif

int main() {
	constexpr int i = 10000;
	cout << factorial(i) << endl;
	return 0;
}
