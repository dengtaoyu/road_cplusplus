#include<iostream>
using namespace std;
/* 
*  ģ�������Ԫ
*/

// ģ�����ȫ�ֺ���  ����ʵ��
template<class T1, class T2>
class Person;
template<class T1, class T2>
void info2(Person<T1, T2>& p)// 1.��Ϊģ�����к����ǵ���ʱ�ż��أ������Ҫ������д�� ģ����֮ǰ
{                            // 2. ��Ϊʹ����ģ����Person<>��������ǰ����ģ����Ĵ���
	cout << "name = " << p.m_name << "    age = " << p.m_age << endl;
}


template<class T1, class T2>
class Person
{
// ȫ�ֺ��� ����ʵ��
	friend void info(Person<T1, T2> &p)
	{
		cout << "name = " << p.m_name << "    age = " << p.m_age << endl;
	}
// ȫ�ֺ��� ���ڶ��壬����ʵ��
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
	Person<string, int> p("����", 12);
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