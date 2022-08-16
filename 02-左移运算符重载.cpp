#include<iostream>
using namespace std;

class person {

	friend ostream& operator<<(ostream& cout, person& p);
	// 采用全局函数实现左移 <<运算符重载
public:
	person(int a) {
		m_A = a;
	}
private:	
	int m_A;
};
ostream & operator<<(ostream & cout, person & p) {
	cout << p.m_A;
	return cout;
}
void test() {
	
	person p(10);

	//operator<<(cout, p);
	cout << p << endl;
}
int main() {
	test();
	return 0;
}