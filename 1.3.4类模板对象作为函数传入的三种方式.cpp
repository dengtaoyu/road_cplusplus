#include<iostream>
using namespace std;
#include<string>
/* 
   ��ģ������뵽���������ַ�ʽ
   1. ֱ�Ӵ���ָ��������
   2. ����ģ�廯
   3. ������ģ�廯
*/
template<class T1, class T2>
class person
{
public:
	//���캯��
	person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	T1  m_name;
	T2  m_age;
	void info()
	{
		cout << "�����ǣ�" << this->m_name << "    ���䣺" << this->m_age << endl;
	}
};

//����1��    ֱ�Ӳ�������
void showperson1(person<string ,int> &p)
{
	p.info();
}
void test01()
{
	person<string, int> p("�����",100); 
	showperson1(p);
}


//����2��    ����ģ�崫��
//����  ����ģ�����ʽ,���������ģ�廯

template<class T1,class T2>  
void showperson(person<T1,T2> &p)
{
	p.info();
}
void test02()
{
	person<string, int> p("��˼�", 90);
	showperson(p);
}

//����3��    ����ģ����
//��������ģ���� ����������ģ�廯��


template<class T> //��ģ��
void showP3( T &p)
{
	p.info();
}
void test03()
{
	person<string, int> p("��ɮ", 20);
	showP3(p);
}

int main()
{
	test01();
	test02();
	test03();
}
