#include<iostream>
using namespace  std;
//������
// ���Բ��ó�ʼ���б����ʽ ���󸳳�ֵ
// ��ϸ�﷨���£�
// person(int a , int b ):m_a(a),m_b(b){}
class person {
public:
	//�޲ι���
	person() {
		cout << "�޲ι���" << endl;
	};
	// �вι��죻���ó�ʼ���б�ķ�������ֵ
	person(int a,int b,int c):m_a(a),m_b(b),m_c(c) {
		cout << "�вι���" << endl;
		cout << m_a <<"\t"<< m_b << "\t" << m_c << endl;
	}
	// ��������
	person(const person & p){
		m_a = p.m_a;
		m_b = p.m_b;
		m_c = p.m_c;
	}
		int m_a;
		int m_b;
		int m_c;
};
void test01() {
	person p(10, 20, 30);
}
int main() {
	test01();
}