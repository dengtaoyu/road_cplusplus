#include<iostream>
using namespace std;
/* 
*  探究模板类中的成员函数创建时机；
*  1. 普通类的成员函数的创建发生在 类实例化时；
*  2. 模板类的成员函数的创建发生在 类实例函数被调用时；
*/
class person1
{
public:
	void showperson1()
	{
		cout << "person 1  show" << endl;
	 }
};
class person2
{
public:
	void showperson1()
	{
		cout << "person 2  show" << endl;
	}
};
template<class T>
class Myclass
{
public:
	T obj;
	void func1() { obj.showperson1(); }
	void func2() { obj.showperson2(); }
};

void test() {
	Myclass<person1> m;
	//m.func1();
	m.func2();  // 编译会出错，说明函数调用才会去创建成员函数
}
int main() {
	test();
	return 0;
}