#include<iostream>
using namespace std;
/*
运算符重载：
	1.为什么有这个需求？
		如下案例：
		person p1;
		person p2;
		person p3 = p2 + p1;  代表什么意思？

	2.重载实现方法？
		- 成员函数实现加法运算符重载
		- 全局函数实现加法运算符重载
	3. 运算符重载的本质及简写
*/
class person {
public:
	int m_a;
	int m_b;

	// 采用成员函数的方式  重载加法运算符
	//person operator+(person& p1) {
	//	person temp;
	//	temp.m_a = p1.m_a + this->m_a;
	//	return temp;
	//}
};

// 采用全局函数重载加号运算符
person operator+(person& p1, person& p2) {
	person temp;
	temp.m_a = p1.m_a + p2.m_a;
	return temp;
}
void test() {
	person p1;
	p1.m_a = 20;
	person p2;
	p2.m_a = 60;
	// 成员函数重载加号运算符的本质
	//person p4 = p1.operator+(p2);
	person p3 = p1 + p2;


	 cout << "p3 的 m_a = " << p3.m_a << endl;
	// cout << "p4 的 m_a = " << p4.m_a << endl;
	

	 // 全局函数重载加号运算符的本质
	 person p5 = operator+(p1, p2);
	 cout << "p5 的 m_a = " << p5.m_a << endl;
}
int main() {
	test();
	return 0;
}