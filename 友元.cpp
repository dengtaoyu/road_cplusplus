#include<iostream>
using namespace std;
#include<string>

//    ȫ�ֺ�������Ԫ   //
class Building {
	friend void func(Building & b);
public :
	// �޲ι���
	Building() {
		this->bedroom = "����";
		this->sittingroom = "����";

	}
	string sittingroom;
private:
	string bedroom;

};
//����ȫ�ֺ���
void func(Building & b) {
	cout << b.sittingroom << endl; //����ֱ�ӷ���public��Ա �����ܷ��� private��Ա��
	cout << b.bedroom<< endl; //������ֱ�ӷ���public��Ա �����ܷ��� private��Ա�����Ҫ���ʣ���Ҫclass�ڵ�һ�������Ԫ
	//��Ԫ�﷨�� friend void func(Building &b);

}

//    ȫ�ֺ�������Ԫ   //

// ����Ϊ ��Ԫ�� 
class BuildingA{
	friend class gayboy;
public:
	BuildingA(); //���캯�� ������������������ʵ�֣�
	string  sittingroom;

private:
	string bedroom;

};
class gayboy {
public:	
	gayboy(); // ���캯�� ����������������������ʵ�֣�
	BuildingA  * buildinga;
	void visit();// ��Ա�������������� ��ʵ�������⣻
};

// ����ʵ��
gayboy::gayboy() {
	buildinga = new BuildingA;
}
void gayboy::visit() {
	cout << "gayboy ���ڷ���" << this->buildinga->bedroom << endl;
	cout << "gayboy ���ڷ���" <<this->buildinga->sittingroom << endl;
}
BuildingA::BuildingA() {
	this->bedroom = "����";
	this->sittingroom = "����";
}

void test02() {
	gayboy g1;// �޲ι�����﷨  ���ŷ���
	g1.visit();
	
}
int main() {
//	Building  b;
//	func(b);
	test02();
	return 0;
}