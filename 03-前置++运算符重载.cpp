#include<iostream>
using namespace std;
// 重写<< 左移运算符
class person {
	friend ostream& operator<<(ostream& cout, person p1);

public:
	person() {
		m_age = 10;
	}
	// 02-编写前置++ 运算符
	// 需要满足：++（++num）  这就要求返回值必须还是num的类型
	person& operator++() {
		++this->m_age;
		return *this;
	}

	// 03-编写后置++运算符
	// 不用满足：（num++）++，返回值
	person  operator++(int) {
		person   temp = *this;
		this->m_age++;
		return temp;

	}


private:	
	int m_age;

};
// 01-重载左移运算符
ostream&  operator<<(ostream & cout,person p1) {
	cout << p1.m_age;
	return cout;
}


void test01() {
	person p;
	cout << p << p << endl;
}
void test02() {
	person p1;
	cout << ++(++p1) << endl;
	cout << p1 << endl;
}
void test03() {
	person p2;
	cout <<"开始 p2 = " <<p2 << endl;
	cout << (p2++) << endl;
	cout << p2 << endl;
}
int main() {
	//测试左移运算符
	//test01();
	// 测试前置++ 运算符
	//test02();
	// 测试后置++ 运算符
	test03();

}
