#include<iostream>
using namespace std;
// �����ǳ���� �����Ͼ��� ���ڴ�Ķ���ͷŵ����⡣
// ���ÿ������캯���ķ�ʽ ��ʼ���¶���ʱ�����ԭ���Ķ�����������ڴ棬�����������б����ͷŸö��ڴ棻 ��ʵ����Ϊ�¶����ʼ��
//��ʼ������ʵ�������ԭ����ʵ�����󣬹�ͬ������ͬһ�����ڴ�ָ�룬���������������ڶ����ͷŶ��ڴ�����⣻
// ������������¶���Ŀ������캯���������д����ָ������Ķ�����������һ����ڴ棻

class person {
public:
	//�޲ι��캯��
	person() {
		cout << "�޲ι��캯��" << endl;
	};
	//�вι��캯��
	person(int age, int hi) {
		m_age = age;
		height = new int( hi);  /// hi �Ǵ���ʵ���Ǵ���������ֵ������������ֵ����ڶ��ڴ��ϣ�height �Ǹ���ַ

		cout << "�вι��캯��  age = "<< m_age <<"���"<< *height<< endl;

	}
	//�������캯��
	person(const person & p) {
		m_age = p.m_age;
		//height =p.height;  // ǳ����
		height = new int(*p.height);//���
		cout << "�������캯��  m_age =  " << m_age << "���" << *height << endl;

	}
	// ��������  ��Ҫ�ͷŶ��ڴ�
	~person() {
		if (height != NULL) {
			delete height;
		}
	}
public:
	int m_age;
	int* height;  //��������һ��ָ�룬��ָ��ָ��洢��ߵĵ�ַ��
};

void test01() {
	person  p1(10,160); // �вι���
	person p2(p1);  // ��������
}

int main() {
	
	test01();
	return 0;
}