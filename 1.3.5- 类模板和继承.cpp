#include<iostream>
using namespace std;
/*
*    类模板继承时，需要注意一下几点：
*	1. 子类继承类模板时，必须指定类模板中变量的类型，因为子类需要确定开辟空间的大小；
*	2. 如果想要灵活指定父类中T的类型，子类也要变为类模板
*/

// 定义模板父类
template <class T>
class Base
{
public:
	T m;
};

// 子类继承父类
class son :public Base<int> // 此处必须指定父类中T的类型，否则会报错
{
public:
	//构造函数
	son() 
	{
		cout << "son 构造函数" << endl;
	}
};

void test01()
{
	son s1;

}

// 灵活指定父类中T的类型时，子类也需要变为类模板
template <class T1,class T2>
class son1 :public Base<T2>
{
public:
	son1()
	{
		cout << "T1 的类型是" << typeid(T1).name() << endl;
		cout << "T2 的类型是" << typeid(T2).name() << endl;
	}


};
void test02()
{
	son1<int, char> s2;



}

int main()
{
	//test01();
	test02();
	return 0;
}