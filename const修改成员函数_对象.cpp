#include<iostream>
using namespace std;

/*
* �����󡢳�����
const ���γ�Ա������
	�﷨�� void func() const{}; //�˲��������壺��Ա��������һ��ָ������ָ�� this �����ʾΪ person * cont p;
			�����ں������������ const �󣬽�thisָ���Ϊ const person * const p ,��ָ��ָ��ĵ�ַ�͵�ַ�ϴ洢�����ݶ������Ըı�
			����� thisָ���person��ַ�ϵ�����Ҳ�����Ըı䣻
	�ص㣺
		1. const���γ�Ա������������������޸ģ���Ҫ�޸ģ����ڳ�Ա����ǰ�����mutable��
const ���ζ���
	�﷨��const person p��
	�ص㣺�ö���ֻ�ܵ��ó����������ܵ��� �� ������
*/
class person {
public:
	int m_a;
	mutable int m_b;
	void func1()const {
	//	this->m_a = 20; //�˾��﷨�д��� ��Ϊ this �� const person * const p; ָ���ַ��ָ�����ݶ��������޸ģ�
		this->m_b = 10;
		cout << this->m_b << endl;
	}
	void func2() {
		cout << "���Ƿ� ������ ����ͨ��Ա����" << endl;
	}

};
void test01() {
	// ����������
	person p;
	p.func1();
	// cout << sizeof(p) << endl;
	// ���������
	const person p2;
	p2.func1(); // ���Ե��ó���������
	//p2.func2();  // �����Ե��� ��ͨ��Ա����

}
int main() {
	test01();
}