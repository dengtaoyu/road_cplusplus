#include<iostream>
using namespace std;
/*
	 ���ࡢ����ͬ����Ա�ķ��� 
		1. �Ǿ�̬��Ա�����ԡ�������
		2. ��̬��Ա�����ԡ�������
*/
class Base {
public:
	Base() {
		a = 100;
	}
	int a;
public:
	static int  b;
	void func() {
		cout << "Base func " << endl;
	}
	void static func1() {
		cout << "Base func  static  " << endl;

	}
};

int Base::b = 700; //�˴���Ҫ���  int  Ϊʲô���������ڡ���������һ�£�

class son :public Base {
public:
	son() {
		a = 200;
	}
	int a;
	static int b;
	void func() {
		cout << "son  func " << endl;
	}
	void static func1() {
		cout << "son func  static  " << endl;
	};
};

int son::b = 800;
void test01() {
	son s1;
	cout << s1.a << endl;
	s1.Base::func();
	s1.func();
	// ����2�� ���ھ�̬��Ա������������ͨ�������ķ�ʽ����
	cout << " staic son" << son::b << endl;
	cout << "static base " << son::Base::b << endl;
	son::func1();
	son::Base::func1();

}
int main() {
	test01();
}