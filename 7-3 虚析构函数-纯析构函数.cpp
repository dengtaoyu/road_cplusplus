#include<iostream>
using namespace std;
/*
	1. 为什么要创造虚析构函数、纯析构函数？（解决什么问题）
		01. 多态中，父类指针指向子类对象，在析构过程中，不走子类析构函数。如果子类属性中在堆上开辟了内存，则无法释放该内存，造成内存泄漏；
		02. 虚析构函数、纯析构函数 可以先走子类析构函数，再走父类析构函数；
	2. 虚构函数、纯析构函数的相同点、不同点？
		01. 共同点：
				1. 都可以解决父类指针指向子类对象时，无法走子类析构函数的问题；
				2. 都需要具体的实现；
		02. 不同点：
				1. 如果是纯虚析构函数，则该类是抽象类，无法实例化；
				2. 而虚函数则不是；
	3. 虚析构函数、纯虚析构函数的语法特点
				语法：
				1. 虚析构函数：      virtual 类名（）{}
				2. 纯虚析构函数：    virtual 类名（）=0；需要在类外实现纯虚析构函数，类名::virtual 类名（）{ 具体实现}
	4. 实例
*/

class Animal {
public :
	Animal() {
		cout << "animal 的构造函数" << endl;
	}
	virtual void speak() = 0; //纯虚函数。子类需要重写该函数
	//虚析构函数
	//virtual ~Animal() {
	//	cout << "animal 析构函数" << endl;
	//}
	// 纯析构函数
	virtual ~Animal() = 0;
};
Animal::~Animal() {
	cout << "animal 纯析构函数" << endl;
}

class cat :public Animal {
public:
	cat(string n) {
		name =new string(n);
		cout << "cat 的构造函数" << endl;
	}
	void speak() {
		cout << *name << " 正在讲话" << endl;
	}
	string * name;
	~cat() {
		cout << "cat 的析构函数" << endl;
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
};
void test() {
	Animal* p = new cat("tom");
	p->speak();
	delete p;
}
int main() {
	test();
}