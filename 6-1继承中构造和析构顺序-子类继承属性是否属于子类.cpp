#include<iostream>
using namespace  std;
/*
	1. ����̳и��������ʱ����Ա��������������
			-	���ۣ� �����洢�������еķǾ�̬���ԣ�����˽�����ԣ�
	2. ����͸��๹�졢������˳��
			-   ���ۣ� �̳��� ���ȵ��ø���Ĺ��캯����Ȼ��������Ĺ��캯��������������������� -�� �������������
*/

class F {
public:
	F() {
		cout << "�����޲ι���" << endl;
	}
	~F() {
		cout << "������������" << endl;

	}
public:
	int a;
protected:
	int b;
private :
	int c;
};
class C :public F {
public:
	C() {
		cout << "�����޲ι���" << endl;
	}
	~C(){
		cout << "������������" << endl;
	}
public :
	int d;
};
// ��֤����Ĵ�С
void test(){
	C c1;//�޲ι���
	cout << sizeof(c1) << endl; //��СΪ16Byte��˵�����໹�����˸����˽�г�Ա��ֻ�Ǳ��뱻���Ÿ�coder��
}

//�жϸ�������Ĺ��졢����˳��

int main() {
	test();
	return 0;
}
