#include<iostream>
using namespace std;

class person {
public:	//�޲ι��캯��
	person() {
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯��
	person(int a) {
		age = a;
		cout << "�вι��캯��  age= " << age << endl;
	}
	//�������캯��
	person(const person& p) {

		cout << "�������캯�� age = " << p.age <<endl;
	}
	~person() {
		cout << "��������" << endl;
	};

public :
	int age;
};
void test()
{  //���ŷ�
	person p0;    //�޲ε���
	person p1(10);// ���ŷ�����
	person p3(p1);  //�������캯��
	// ����������
	cout << "�������� ��" << endl;
	person p4 = person();// �޲ι���
	person p5 = person(20); // �вι���
	person p6 = person(p5); //��������

	// ��ʽ��
	cout << "��ʽ��" << endl;
	person p7;
	person p8 = 30;
	person p9 = p8;

}

int main() {
	test();
	return 0;
}