#include<iostream>
using namespace std;
class person {
public:
	//Ĭ�Ϲ��캯��
	person() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	//�вι��캯��
	person( int a)
	{
		m_age = a;
		cout << "�вι��캯�� m_age = " << m_age << endl;
	}
	// �������캯��
	person(const person &p){
		m_age = p.m_age;
		cout << "�������캯�� age = " << m_age << endl;
	}
	//��������
	~person() {
		cout << "��������" << endl;
	}
	
public:
	int m_age;
};
void test01() {
	//ʹ�ó���1�� ���󿽱�
	person p1=10;
	person p2 = p1;
}
void dowork01(person p) {
	cout << p.m_age << endl;
}
person dowork02(){
	person p5 = 88;
	return p5; //��ʱ��p5����

}
void test02() {
	//ʹ�ó���2�� ��������Ϊ��������ʱ
	person p3(20);
	dowork01(p3);//��ʱ����ľ��ǿ�������Ķ���
}
void test03() { // ������Ϊ����ֵʱ
	dowork02();
}
int main() {
	// �������캯����ʹ�õķ�Χ���ҵ���⣩
	// 01. ������ֵ���µĶ���ʱ��
	// 02. ������Ϊ�����������ʱ���βΣ���
	// 03. ������Ϊ��������ֵʱ��
	/* �̳�˵��
	  01.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
      02.ֵ���ݵķ�ʽ������������ֵ
      03. ��ֵ��ʽ���ؾֲ�����
	*/

	//test01();
	//test02();
	test03();
}