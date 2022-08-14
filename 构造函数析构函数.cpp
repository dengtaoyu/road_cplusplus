#include<iostream>
using namespace std;

class person {
public:	//无参构造函数
	person() {
		cout << "无参构造函数" << endl;
	}
	//有参构造函数
	person(int a) {
		age = a;
		cout << "有参构造函数  age= " << age << endl;
	}
	//拷贝构造函数
	person(const person& p) {

		cout << "拷贝构造函数 age = " << p.age <<endl;
	}
	~person() {
		cout << "析构函数" << endl;
	};

public :
	int age;
};
void test()
{  //括号法
	person p0;    //无参调用
	person p1(10);// 括号法调用
	person p3(p1);  //拷贝构造函数
	// 匿名函数法
	cout << "匿名函数 法" << endl;
	person p4 = person();// 无参构造
	person p5 = person(20); // 有参构造
	person p6 = person(p5); //拷贝构造

	// 隐式法
	cout << "隐式法" << endl;
	person p7;
	person p8 = 30;
	person p9 = p8;

}

int main() {
	test();
	return 0;
}