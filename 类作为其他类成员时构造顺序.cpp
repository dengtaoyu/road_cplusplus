#include<iostream>
using namespace std;
#include<string>
//������Ϊ������ĳ�Աʱ�� ���ȹ����Ա�࣬Ȼ������ࣻ
// ����ʱ �������෴�����������࣬��������Ա��

class  phone {
public :
	//�вι���
	phone(string name):p_name(name){
		cout << "phone���вι���" << endl;
	}
	string p_name;
	~phone() {
		cout << "phone  ����������" << endl;
	}
};
class person {
public:

	//�вι���
	person(string p_name, string ph_name) :P_name(p_name), ph(ph_name) {  
		// ע�⣺�˴���ph(ph_name)��phone���е��вι���ĵ����� ��ʽת������
		cout << P_name << "  �� 2 ��  " << ph.p_name << "�ֻ�" << endl; // ע��˴�Ӧ��Ϊph.p_name 

	}
	string P_name;
	phone ph;
	~person() {
		cout << "person ����������" << endl;
	}
};
void test01() {
	person("����", "��Ϊ");
}
int main() {
	test01();
	return 0;
}