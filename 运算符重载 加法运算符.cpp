#include<iostream>
using namespace std;
/*
��������أ�
	1.Ϊʲô���������
		���°�����
		person p1;
		person p2;
		person p3 = p2 + p1;  ����ʲô��˼��

	2.����ʵ�ַ�����
		- ��Ա����ʵ�ּӷ����������
		- ȫ�ֺ���ʵ�ּӷ����������
	3. ��������صı��ʼ���д
*/
class person {
public:
	int m_a;
	int m_b;

	// ���ó�Ա�����ķ�ʽ  ���ؼӷ������
	//person operator+(person& p1) {
	//	person temp;
	//	temp.m_a = p1.m_a + this->m_a;
	//	return temp;
	//}
};

// ����ȫ�ֺ������ؼӺ������
person operator+(person& p1, person& p2) {
	person temp;
	temp.m_a = p1.m_a + p2.m_a;
	return temp;
}
void test() {
	person p1;
	p1.m_a = 20;
	person p2;
	p2.m_a = 60;
	// ��Ա�������ؼӺ�������ı���
	//person p4 = p1.operator+(p2);
	person p3 = p1 + p2;


	 cout << "p3 �� m_a = " << p3.m_a << endl;
	// cout << "p4 �� m_a = " << p4.m_a << endl;
	

	 // ȫ�ֺ������ؼӺ�������ı���
	 person p5 = operator+(p1, p2);
	 cout << "p5 �� m_a = " << p5.m_a << endl;
}
int main() {
	test();
	return 0;
}