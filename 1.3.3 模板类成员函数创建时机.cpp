#include<iostream>
using namespace std;
/* 
*  ̽��ģ�����еĳ�Ա��������ʱ����
*  1. ��ͨ��ĳ�Ա�����Ĵ��������� ��ʵ����ʱ��
*  2. ģ����ĳ�Ա�����Ĵ��������� ��ʵ������������ʱ��
*/
class person1
{
public:
	void showperson1()
	{
		cout << "person 1  show" << endl;
	 }
};
class person2
{
public:
	void showperson1()
	{
		cout << "person 2  show" << endl;
	}
};
template<class T>
class Myclass
{
public:
	T obj;
	void func1() { obj.showperson1(); }
	void func2() { obj.showperson2(); }
};

void test() {
	Myclass<person1> m;
	//m.func1();
	m.func2();  // ��������˵���������òŻ�ȥ������Ա����
}
int main() {
	test();
	return 0;
}