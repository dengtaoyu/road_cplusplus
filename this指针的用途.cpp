#include<iostream>
using namespace std;
// 代码说明
/*
* 1.0 基础知识
* 2.0 this 指针是什么？
* 3.0 this 指针的用途
*   1.0 基础知识：
*			在C++中，类内的成员变量和成员函数分开存储
*			只有非静态成员变量才属于类的对象上
*			空的类对象 占内存为 1字节；
*			有一个费静态成员变量，占内存大小为4字节；
*			静态成员、成员函数均不占类内存；
*			所有类的实例对象共享一个成员函数内存，考this（指向具体类实例）的指针来操作函数；
*	2.0 this指针是什么？
*			this指针是成员函数中指向具体实例对象的指针；（this指针指向被调用的成员函数所属的对象）
*	3.0 this指针的用途
*			3.1 当形参和成员变量名称相同时 用this->成员变量 来区分；
*			3.2 在类的非静态成员函数中返回对象本身；
* 
*/
class person
{
public:
	person(int age) {
		
		this->age = age;
	}
	int age;
	// 精华部分
	person & func01(person p1) { // 注意此处返回的是 对象的地址的引用，这也是链式编程的基础；返回后还是同一个指针类型
		this->age += p1.age;
		return *this;
	}
};
void test01() {
	person p2(10);
	person p3(10);
	p3.func01(p2).func01(p2).func01(p2);
	cout << p3.age << endl;
}
int main() {
	test01();
}