#include<iostream>
using namespace std;
/*
	1. ΪʲôҪ���������������������������������ʲô���⣩
		01. ��̬�У�����ָ��ָ��������������������У���������������������������������ڶ��Ͽ������ڴ棬���޷��ͷŸ��ڴ棬����ڴ�й©��
		02. ���������������������� �������������������������߸�������������
	2. �鹹��������������������ͬ�㡢��ͬ�㣿
		01. ��ͬ�㣺
				1. �����Խ������ָ��ָ���������ʱ���޷��������������������⣻
				2. ����Ҫ�����ʵ�֣�
		02. ��ͬ�㣺
				1. ����Ǵ�������������������ǳ����࣬�޷�ʵ������
				2. ���麯�����ǣ�
	3. ���������������������������﷨�ص�
				�﷨��
				1. ������������      virtual ��������{}
				2. ��������������    virtual ��������=0����Ҫ������ʵ�ִ�����������������::virtual ��������{ ����ʵ��}
	4. ʵ��
*/

class Animal {
public :
	Animal() {
		cout << "animal �Ĺ��캯��" << endl;
	}
	virtual void speak() = 0; //���麯����������Ҫ��д�ú���
	//����������
	//virtual ~Animal() {
	//	cout << "animal ��������" << endl;
	//}
	// ����������
	virtual ~Animal() = 0;
};
Animal::~Animal() {
	cout << "animal ����������" << endl;
}

class cat :public Animal {
public:
	cat(string n) {
		name =new string(n);
		cout << "cat �Ĺ��캯��" << endl;
	}
	void speak() {
		cout << *name << " ���ڽ���" << endl;
	}
	string * name;
	~cat() {
		cout << "cat ����������" << endl;
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
};
void test() {
	Animal* p = new cat("tom");
	p->speak();
	delete p;
}
int main() {
	test();
}