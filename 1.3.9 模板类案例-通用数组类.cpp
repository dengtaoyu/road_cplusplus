#include<iostream>
using namespace std;
#include"Myarray.hpp"

/* 
*   ͨ���������Ҫ��
*	1. ���Դ�������������ͺ��Զ����������ͣ�
*	2. �����е����ݴ�ŵ�����  ����ôʵ�֣�
*	3. ���캯���д������������
*	4. �ṩ�������캯������operator=����������ֹǳ����������
*	5. �ṩβɾ����β�巨�����������ݽ���ɾ������
*	6. ͨ���±�ʽ���������е�Ԫ��
*	7. ���Ի�ȡ�����е�ǰԪ�ص������͸���
*/
// ע��ģ�� ���ļ�дʱ����Ҫ��������Ϊ.hpp
class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void printPerson(Myarray<person> & p)
{
	for (int i = 0; i < p.getsize(); i++)
	{
		cout << "������" << p.pArray[i].name << "---- ����" << p.pArray[i].age << endl;
	}
}


int main()
{
	//Myarray<int> m3(5);
	//for (int i = 0; i < 3; i++)
	//{
	//	m3.pushback(i);
	//}
	//for (int i = 0; i < m3.m_size; i++)
	//{
	//	cout << m3.pArray[i] << endl;
	//}
	//Myarray<int> m2(100);
	//Myarray<int> m1(m3);
	//m2 = m1;
	person p1("����", 19);
	person p2("��˼", 20);
	person p3("����", 21);
	person p4("����", 22);
	person p5("����", 23);
	Myarray<person> p(10);
	p.pushback(p1);
	p.pushback(p2);
	p.pushback(p3);
	p.pushback(p4);
	p.pushback(p5);
	printPerson(p);

	
	
}