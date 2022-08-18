#include<iostream>
using namespace std;
   /*
		1. 函数调用运算符重载
   */
class person {
public:
	int m_age;
	int operator()(int a) {
		return 2 * a;
	}
};
void test() {
	person p1;
	int m = p1(20); // 函数调用运算符重载 
	cout << m << endl;
	// 匿名函数的形式调用 ,此时 只能使用有参构造的方法
	cout << person()(40) << endl;
}
int main() {
	test();
}