#include<iostream>
using namespace std;
/*
* 函数模板的局限性
*	1.对于数组和自定义类型，模板函数（比较大小）无法实现
	需要采用：具体化函数模板解决
*/
class person
{
public:
	person(int a, string name)
	{
		this->age = a;
		this->name = name;

	}
	int age;
	string name;
};
// 普通模板函数 
template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 具体制定模板函数
template<> bool myCompare(person &a, person &b)
{
	if ( a.age ==b.age && a.name == b.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test()
{
	person a(10,"destin");
	person b(10, "destin");
	if (myCompare(a, b))
	{
		cout << "  相等   " << endl;
	}
	else
	{
		cout << "  不相等   " << endl;
	}
}
int main()
{
	test();
	return 0;
}