#include<iostream>
using namespace std;
class person {
public:
	person(int m) {
		m_age = new int(m); //�˴��ڶ��ڴ濪���˵�ַ���������������ͷ���Ӧ���ڴ�
	}
	// ��д��ֵ�����
	person& operator=(person &p) {
		//m_age = p.m_age //��ֵд��
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		
		return *this;
	}
	int * m_age;


	~person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}
};
void test() {
	person p1(10);
	person p2(20);
	//person p3 = p2; //δ���ظ�ֵ�����ʱ����������ͨ�����룬˵��classĬ�ϴ����˸�ֵ���㺯��
	cout << "p1 ������"<<*p1.m_age << endl;
	cout << "p2 ������" << *p2.m_age << endl;
}
int main() {
	test();
}