#include<iostream>
using namespace std;
/*
	 父类、子类同名成员的访问 
		1. 非静态成员（属性、函数）
		2. 静态成员（属性、函数）
*/
class Base {
public:
	Base() {
		a = 100;
	}
	int a;
public:
	static int  b;
	void func() {
		cout << "Base func " << endl;
	}
	void static func1() {
		cout << "Base func  static  " << endl;

	}
};

int Base::b = 700; //此处需要添加  int  为什么？保持类内、类外类型一致；

class son :public Base {
public:
	son() {
		a = 200;
	}
	int a;
	static int b;
	void func() {
		cout << "son  func " << endl;
	}
	void static func1() {
		cout << "son func  static  " << endl;
	};
};

int son::b = 800;
void test01() {
	son s1;
	cout << s1.a << endl;
	s1.Base::func();
	s1.func();
	// 方法2： 对于静态成员函数，还可以通过类名的方式调用
	cout << " staic son" << son::b << endl;
	cout << "static base " << son::Base::b << endl;
	son::func1();
	son::Base::func1();

}
int main() {
	test01();
}