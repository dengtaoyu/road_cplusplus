#include<iostream>
using namespace std;
#include<string>
/* 
	1.0 ��ϰ4���������޲Ρ��вΡ���������������ֵ���㺯����д��
	2.0 �������ֹ��캯���ĵ��÷���
	3.0 ����������͸�ֵ�������д��Ŀǰ������bug��û���ҵ�ԭ��


*/
class person {
public :
	// ��ϰ���캯�����ص㣺  1.�޷���ֵҲ��дvoid 2.���캯����������ͬ
	person()
	{
		cout << "�޲ι��캯��" << endl;
	}
	person(int age) {
		m_age = age;
		cout << m_age  <<"   �вι��캯��" << endl;
	}
	person(const person & p) {  //�������캯�� ��β���д�ˣ�
		m_age = p.m_age;
		cout << m_age << "   �������캯��" << endl;
	}
	~person() {
		cout << "��������" << endl;
	}
	// ��ֵ����� ����
	person& operator=(person & p1) {
		m_age = p1.m_age;
		cout << "��ֵ = ���������" << endl;
		return *this;
	}
	int m_age;

};
// ��д���������
ostream& operator<<(ostream& cout, person& p) {
	cout << p.m_age;
	return cout;
}
void test() {
	/* 
	* ���ֹ��캯���ĵ��÷���
	* 1. ���ŷ�
	* 2. ��ʽ��
	* 3. ��ʽת����
	*/

	// 1. ���ŷ�
	// person p1;
	//person p2(10);
	//person p3(p2);
	//2. ��ʾ��
	//person p4 = person(20);
	//person p5 = person(p4);
	//3. ��ʽת����
	person p6 = 10;
	person p7 = p6;
	person p8;
	//cout << p8  ; // ��ʱͨ�����������������û������
	cout <<(p8 = p6)<<endl;

}
int main() {
	test();
}