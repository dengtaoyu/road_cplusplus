#include<iostream>
using namespace std;
#include<string>
/*     ��Ԫ������﷨�͵���         */

class Building {
friend  void gayboy::visit();
public:
	Building();
	string  sittingroom;
private:
	string bedroom;
};


Building::Building() {
	this->bedroom = "����";
	this->sittingroom = "����";
}
class gayboy {
public:
	gayboy(); //�޲ι��캯�� ���ڶ��壬����ʵ��

	Building* b;
	void visit();
};
gayboy::gayboy() {
	this->b = new Building; // �¿���һ���ַ 
}
void gayboy::visit() {
	cout << "gayboy is visiting " << b->sittingroom << endl;
	cout << "gayboy  is visiting" << this->b->sittingroom << endl;
 }
int main() {
	gayboy g1; //�޲ι��캯��
	g1.visit(); //
}