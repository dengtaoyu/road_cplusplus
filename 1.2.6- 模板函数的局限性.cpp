#include<iostream>
using namespace std;
/*
* ����ģ��ľ�����
*	1.����������Զ������ͣ�ģ�庯�����Ƚϴ�С���޷�ʵ��
	��Ҫ���ã����廯����ģ����
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
// ��ͨģ�庯�� 
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

// �����ƶ�ģ�庯��
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
		cout << "  ���   " << endl;
	}
	else
	{
		cout << "  �����   " << endl;
	}
}
int main()
{
	test();
	return 0;
}