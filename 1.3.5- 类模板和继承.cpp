#include<iostream>
using namespace std;
/*
*    ��ģ��̳�ʱ����Ҫע��һ�¼��㣺
*	1. ����̳���ģ��ʱ������ָ����ģ���б��������ͣ���Ϊ������Ҫȷ�����ٿռ�Ĵ�С��
*	2. �����Ҫ���ָ��������T�����ͣ�����ҲҪ��Ϊ��ģ��
*/

// ����ģ�常��
template <class T>
class Base
{
public:
	T m;
};

// ����̳и���
class son :public Base<int> // �˴�����ָ��������T�����ͣ�����ᱨ��
{
public:
	//���캯��
	son() 
	{
		cout << "son ���캯��" << endl;
	}
};

void test01()
{
	son s1;

}

// ���ָ��������T������ʱ������Ҳ��Ҫ��Ϊ��ģ��
template <class T1,class T2>
class son1 :public Base<T2>
{
public:
	son1()
	{
		cout << "T1 ��������" << typeid(T1).name() << endl;
		cout << "T2 ��������" << typeid(T2).name() << endl;
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