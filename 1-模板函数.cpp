#include<iostream>
using namespace std;
#include<string>
/*
	1. ģ��ķ��ࣺ
		����ģ�塢��ģ��
	2. ����ģ������ã� �������Ͳ��������ں�������׶β�ָ��������������
	3. ����ģ���﷨��
		template<typename T>
		void myswap(T &a,T&b)
		{
			T temp = a;
			a = b;
			b =temp;
		}
		// ���÷���
		int a  = 10;
		int  b = 20;
		����1�������Զ��Ƶ���
		myswap(a,b);
		����2������ָ����
		myswap<int>(a,b);

*/
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test()
{
	int  a = 10;
	int  b = 20;
	//����1������ָ������
	//myswap<int>(a, b);
	// ����2�� �����Զ��Ƶ�
	myswap(a, b);
	cout << "a= " << a
		<< "   " << " b= " << b << endl;

}
int main()
{
	test();
	cout<<"hello"<<endl;
	return 0;
}