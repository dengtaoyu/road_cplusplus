#include<iostream>
using namespace  std;
/*
	1. 子类继承父类的属性时，成员属性属于子类吗？
			-	结论： 子类会存储父类所有的非静态属性（包括私有属性）
	2. 子类和父类构造、析构的顺序？
			-   结论： 继承中 是先调用父类的构造函数，然后是子类的构造函数；再是子类的析构函数 -》 父类的析构函数
*/

class F {
public:
	F() {
		cout << "父类无参构造" << endl;
	}
	~F() {
		cout << "父类析构函数" << endl;

	}
public:
	int a;
protected:
	int b;
private :
	int c;
};
class C :public F {
public:
	C() {
		cout << "子类无参构造" << endl;
	}
	~C(){
		cout << "子类析构函数" << endl;
	}
public :
	int d;
};
// 验证子类的大小
void test(){
	C c1;//无参构造
	cout << sizeof(c1) << endl; //大小为16Byte，说明子类还保存了父类的私有成员，只是编译被开放给coder；
}

//判断父类子类的构造、析构顺序

int main() {
	test();
	return 0;
}
