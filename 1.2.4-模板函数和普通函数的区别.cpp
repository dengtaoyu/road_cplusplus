#include<iostream>
using namespace std;
/*
	ģ�庯������ͨ����������
	1. ģ�庯�����ܷ�����ʽ����ת��
	2. ��ͨ������ʽ����ʱ�����Է����Զ�����ת��
	3. ģ�庯��ʹ��ָ���������͵���ʱ�����Է�����ʽ����ת��
*/
// ��ͨ����
int myAdd(int  a, int b)
{
	return a + b;
}
// ģ�庯��
template<typename T>
T Tadd(T a, T b)
{
	return a + b;
}
void test()
{
	int a = 10;
	int  b = 20;
	char c = 'c';
	// 1. ��ͨ�������� ������ʽ�����Զ�ת��
	cout << myAdd(a, c) << endl;
	// 2. ģ�庯�� ָ�����ͺ󣬾Ϳ��Է�����ʽת��
	cout << Tadd<int>(a, c) << endl;
	// 3. ģ�庯������ʹ����ʽ����ת��
	//cout << Tadd(a, c) << endl;

}
int main()
{
	test();
}