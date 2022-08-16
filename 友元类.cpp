#include<iostream>
using namespace std;
#include<string>
/*     友元类相关语法和调用         */

class Building {
friend  void gayboy::visit();
public:
	Building();
	string  sittingroom;
private:
	string bedroom;
};


Building::Building() {
	this->bedroom = "卧室";
	this->sittingroom = "客厅";
}
class gayboy {
public:
	gayboy(); //无参构造函数 类内定义，类外实现

	Building* b;
	void visit();
};
gayboy::gayboy() {
	this->b = new Building; // 新开辟一块地址 
}
void gayboy::visit() {
	cout << "gayboy is visiting " << b->sittingroom << endl;
	cout << "gayboy  is visiting" << this->b->sittingroom << endl;
 }
int main() {
	gayboy g1; //无参构造函数
	g1.visit(); //
}