#include<iostream>
using namespace std;
/*
	1. 多态的分类
		1.1 静态多态： 
			主要是指：函数的重载、运算符的重载；    特点是：在编译阶段就分配了内存；
		1.2 动态多态：主要是子类重写父类的虚函数；  特点是：在运行阶段才会分配内存；
	2. 动态多态的条件和调用方法
		2.1 动态多态的条件：
			01. 存在父子类的关系
			02. 子类重写 父类的虚函数
		2.2 动态多态的调用：
			父类的引用or指针 指向子类对象；

*/
class base {
public :
	virtual void func() {
		cout << "父类 函数" << endl;
	}
};
class son :public base {
	void func() {
		cout << "子类 函数" << endl;
	}
};

void test(base &b1) {  // 函数的形参中是父类的指针or引用
	b1.func();
}
int main() {
	son s1;
	test(s1); // 实参是 子类对象（存在父子类的关系，切子类重写了父类的虚函数）
}