#include<iostream>
using namespace std;
// ��д<< ���������
class person {
	friend ostream& operator<<(ostream& cout, person p1);

public:
	person() {
		m_age = 10;
	}
	// 02-��дǰ��++ �����
	// ��Ҫ���㣺++��++num��  ���Ҫ�󷵻�ֵ���뻹��num������
	person& operator++() {
		++this->m_age;
		return *this;
	}

	// 03-��д����++�����
	// �������㣺��num++��++������ֵ
	person  operator++(int) {
		person   temp = *this;
		this->m_age++;
		return temp;

	}


private:	
	int m_age;

};
// 01-�������������
ostream&  operator<<(ostream & cout,person p1) {
	cout << p1.m_age;
	return cout;
}


void test01() {
	person p;
	cout << p << p << endl;
}
void test02() {
	person p1;
	cout << ++(++p1) << endl;
	cout << p1 << endl;
}
void test03() {
	person p2;
	cout <<"��ʼ p2 = " <<p2 << endl;
	cout << (p2++) << endl;
	cout << p2 << endl;
}
int main() {
	//�������������
	//test01();
	// ����ǰ��++ �����
	//test02();
	// ���Ժ���++ �����
	test03();

}
