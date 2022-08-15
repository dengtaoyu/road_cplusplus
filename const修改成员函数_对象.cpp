#include<iostream>
using namespace std;

/*
* 常对象、常函数
const 修饰成员函数：
	语法： void func() const{}; //此操作的意义：成员函数存在一个指向对象的指针 this ，其表示为 person * cont p;
			现在在函数后面添加上 const 后，将this指针变为 const person * const p ,该指针指向的地址和地址上存储的内容都不可以改变
			，因此 this指向的person地址上的内容也不可以改变；
	特点：
		1. const修饰成员函数，对象变量不能修改；若要修改，需在成员变量前面添加mutable；
const 修饰对象
	语法：const person p；
	特点：该对象只能调用常函数，不能调用 非 常函数
*/
class person {
public:
	int m_a;
	mutable int m_b;
	void func1()const {
	//	this->m_a = 20; //此句语法有错误。 因为 this 是 const person * const p; 指针地址和指针内容都不可以修改；
		this->m_b = 10;
		cout << this->m_b << endl;
	}
	void func2() {
		cout << "这是非 常函数 ，普通成员函数" << endl;
	}

};
void test01() {
	// 常函数调用
	person p;
	p.func1();
	// cout << sizeof(p) << endl;
	// 常对象测试
	const person p2;
	p2.func1(); // 可以调用常对象函数；
	//p2.func2();  // 不可以调用 普通成员函数

}
int main() {
	test01();
}