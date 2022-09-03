#include<iostream>
using namespace std;
#include<string>
/* 
   类模板对象传入到函数的三种方式
   1. 直接传入指定的类型
   2. 参数模板化
   3. 整个类模板化
*/
template<class T1, class T2>
class person
{
public:
	//构造函数
	person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	T1  m_name;
	T2  m_age;
	void info()
	{
		cout << "名字是：" << this->m_name << "    年龄：" << this->m_age << endl;
	}
};

//方法1：    直接参数传入
void showperson1(person<string ,int> &p)
{
	p.info();
}
void test01()
{
	person<string, int> p("孙悟空",100); 
	showperson1(p);
}


//方法2：    函数模板传入
//采用  函数模板的形式,将传入参数模板化

template<class T1,class T2>  
void showperson(person<T1,T2> &p)
{
	p.info();
}
void test02()
{
	person<string, int> p("猪八家", 90);
	showperson(p);
}

//方法3：    整个模板类
//采用整个模板类 ，将整个类模板化；


template<class T> //类模板
void showP3( T &p)
{
	p.info();
}
void test03()
{
	person<string, int> p("唐僧", 20);
	showP3(p);
}

int main()
{
	test01();
	test02();
	test03();
}
