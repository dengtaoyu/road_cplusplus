#include<iostream>
using namespace std;
/*
	菱形继承：
	1. 子类继承双份数据，浪费资源；
	2. 采用virtual 可以解决该问题。 核心：就是虚继承：维护virtual pointer table；该表存储父类成员变量的指针；
*/
class Animal {
public:
	int a;

};
class sheep:virtual public Animal{

};
class tuo:virtual  public Animal {

};

class sheeptuo: public tuo,public sheep {
};
void test() {
	sheeptuo  st;
	st.sheep::a = 28;
	st.tuo::a = 10;

	cout << st.a << endl;
}
int main() {
	test();



}
