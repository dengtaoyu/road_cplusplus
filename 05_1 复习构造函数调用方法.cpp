#include<iostream>
using namespace std;
#include<string>
/* 
	1.0 复习4个函数：无参、有参、拷贝、析构、赋值运算函数的写法
	2.0 回忆三种构造函数的调用方法
	3.0 左移运算符和赋值运算符重写（目前还存在bug，没有找到原因）


*/
class person {
public :
	// 复习构造函数的特点：  1.无返回值也不写void 2.构造函数和类名相同
	person()
	{
		cout << "无参构造函数" << endl;
	}
	person(int age) {
		m_age = age;
		cout << m_age  <<"   有参构造函数" << endl;
	}
	person(const person & p) {  //拷贝构造函数 这次不会写了；
		m_age = p.m_age;
		cout << m_age << "   拷贝构造函数" << endl;
	}
	~person() {
		cout << "析构函数" << endl;
	}
	// 赋值运算符 重载
	person& operator=(person & p1) {
		m_age = p1.m_age;
		cout << "赋值 = 运算符重载" << endl;
		return *this;
	}
	int m_age;

};
// 重写左移运算符
ostream& operator<<(ostream& cout, person& p) {
	cout << p.m_age;
	return cout;
}
void test() {
	/* 
	* 三种构造函数的调用方法
	* 1. 括号法
	* 2. 显式法
	* 3. 隐式转换法
	*/

	// 1. 括号法
	// person p1;
	//person p2(10);
	//person p3(p2);
	//2. 显示法
	//person p4 = person(20);
	//person p5 = person(p4);
	//3. 隐式转换法
	person p6 = 10;
	person p7 = p6;
	person p8;
	//cout << p8  ; // 此时通过，左移运算符重载没有问题
	cout <<(p8 = p6)<<endl;

}
int main() {
	test();
}