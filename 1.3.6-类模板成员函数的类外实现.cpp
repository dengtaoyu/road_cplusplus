#include<iostream>
using namespace std;
/* 
*  类模板成员函数的类外实现：
*  person<t1,t2>::person(){}
*/
template<class T1, class T2>
class person
{
public:
	// 构造函数类内实现
	person(T1 name, T2 age);// 类内定义。类外实现
	//person(T1 name, T2 age)//类内定义+实现
	//{
	//	this->m_name = name;
	//	this->m_age =age
	//}
	T1 m_name;
	T2 m_age;
	// 成员函数类内实现
	//void info()
	//{
	//	cout << "name: " << this->m_name << "age: " << this->m_age << endl;
	//}
	//成员函数类内定义，类外实现
	void info();
};
//构造函数类外实现
template<class T1, class T2>
person<T1, T2>::person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}
//
template<class T1, class T2>
void person<T1, T2>::info()
{
	cout << "name: " << this->m_name << "age: " << this->m_age << endl;
}
void test()
{
	person<string, int> p("zhangsna", 11);
	p.info();
}
int main()
{
	test();
	return 0;
}
