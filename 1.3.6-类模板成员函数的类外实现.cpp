#include<iostream>
using namespace std;
/* 
*  ��ģ���Ա����������ʵ�֣�
*  person<t1,t2>::person(){}
*/
template<class T1, class T2>
class person
{
public:
	// ���캯������ʵ��
	person(T1 name, T2 age);// ���ڶ��塣����ʵ��
	//person(T1 name, T2 age)//���ڶ���+ʵ��
	//{
	//	this->m_name = name;
	//	this->m_age =age
	//}
	T1 m_name;
	T2 m_age;
	// ��Ա��������ʵ��
	//void info()
	//{
	//	cout << "name: " << this->m_name << "age: " << this->m_age << endl;
	//}
	//��Ա�������ڶ��壬����ʵ��
	void info();
};
//���캯������ʵ��
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
