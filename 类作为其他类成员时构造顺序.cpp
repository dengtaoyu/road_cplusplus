#include<iostream>
using namespace std;
#include<string>
//当类作为其他类的成员时， 会先构造成员类，然后加载类；
// 析构时 ，正好相反，先析构主类，在析构成员类

class  phone {
public :
	//有参构造
	phone(string name):p_name(name){
		cout << "phone的有参构造" << endl;
	}
	string p_name;
	~phone() {
		cout << "phone  的析构函数" << endl;
	}
};
class person {
public:

	//有参构造
	person(string p_name, string ph_name) :P_name(p_name), ph(ph_name) {  
		// 注意：此处的ph(ph_name)是phone类中的有参构造的第三种 隐式转换法；
		cout << P_name << "  有 2 个  " << ph.p_name << "手机" << endl; // 注意此处应该为ph.p_name 

	}
	string P_name;
	phone ph;
	~person() {
		cout << "person 的析构函数" << endl;
	}
};
void test01() {
	person("张三", "华为");
}
int main() {
	test01();
	return 0;
}