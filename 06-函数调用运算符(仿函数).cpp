#include<iostream>
using namespace std;
   /*
		1. �����������������
   */
class person {
public:
	int m_age;
	int operator()(int a) {
		return 2 * a;
	}
};
void test() {
	person p1;
	int m = p1(20); // ����������������� 
	cout << m << endl;
	// ������������ʽ���� ,��ʱ ֻ��ʹ���вι���ķ���
	cout << person()(40) << endl;
}
int main() {
	test();
}