#include<iostream>
using namespace std;
#include<string>

//    全局函数做友元   //
class Building {
	friend void func(Building & b);
public :
	// 无参构造
	Building() {
		this->bedroom = "卧室";
		this->sittingroom = "客厅";

	}
	string sittingroom;
private:
	string bedroom;

};
//创建全局函数
void func(Building & b) {
	cout << b.sittingroom << endl; //可以直接访问public成员 ，不能访问 private成员；
	cout << b.bedroom<< endl; //不可以直接访问public成员 ，不能访问 private成员；如果要访问，需要class内第一行添加友元
	//友元语法： friend void func(Building &b);

}

//    全局函数做友元   //

// 类作为 友元类 
class BuildingA{
	friend class gayboy;
public:
	BuildingA(); //构造函数 在类内声明，在类外实现；
	string  sittingroom;

private:
	string bedroom;

};
class gayboy {
public:	
	gayboy(); // 构造函数 在类内声明，可以在类外实现；
	BuildingA  * buildinga;
	void visit();// 成员函数声明在类内 ，实现在类外；
};

// 类外实现
gayboy::gayboy() {
	buildinga = new BuildingA;
}
void gayboy::visit() {
	cout << "gayboy 正在访问" << this->buildinga->bedroom << endl;
	cout << "gayboy 正在访问" <<this->buildinga->sittingroom << endl;
}
BuildingA::BuildingA() {
	this->bedroom = "卧室";
	this->sittingroom = "客厅";
}

void test02() {
	gayboy g1;// 无参构造的语法  括号法；
	g1.visit();
	
}
int main() {
//	Building  b;
//	func(b);
	test02();
	return 0;
}