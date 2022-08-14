#include<iostream>
using namespace std;
// 成员包括 成员变量、成员函数
// 静态变量：
//    特点：1. 类内定义，类外初始化； 2.所有对象公用同一份； 3.编辑阶段分配内存，早于运行阶段；4. 私有化后，类外无法访问和初始化；
//    访问方法： 1. 类名::静态变量名； 2. 实例.静态变量名；
// 静态成员函数： 
//    特点: 1. 所有对象共享同一个函数 2. 静态成员函数只能访问静态成员变量
class person
{
public:
	int id;
	static string name;
	void func1() {
		cout << name << "函数 调用变量" << endl;
	}
	static void func2() {
		cout << name << "静态函数 调用静态变量" << endl;
	}
//private:
//	static string name;
};
void test01() {
	cout<<person::name<<endl;
	person::func2();
}
 string person::name = "yudengtao";
int main() {
	test01();

}