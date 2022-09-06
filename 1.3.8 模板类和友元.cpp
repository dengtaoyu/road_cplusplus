#include<iostream>
using namespace std;
/* 
*  模板类和友元
*/

// 模板里的全局函数  类外实现
template<class T1, class T2>
class Person;
template<class T1, class T2>
void info2(Person<T1, T2>& p)// 1.因为模板类中函数是调用时才加载，因此需要将函数写在 模板类之前
{                            // 2. 因为使用了模板类Person<>，必须提前声明模板类的存在
	cout << "name = " << p.m_name << "    age = " << p.m_age << endl;
}


template<class T1, class T2>
class Person
{
// 全局函数 类内实现
	friend void info(Person<T1, T2> &p)
	{
		cout << "name = " << p.m_name << "    age = " << p.m_age << endl;
	}
// 全局函数 类内定义，类外实现
	friend void info2<>(Person<T1, T2>& p);
public:
	Person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_name = name;

	}
private:
	T1 m_name;
	T2 m_age;
};


void test01()
{
	Person<string, int> p("张三", 12);
	info(p);
}
void test02()
{
	Person<string, int> p("jeery", 12);
	info2(p);
}
int main()
{
	//test01();
	test02();
	return 0;
}