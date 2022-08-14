#include<iostream>
using namespace std;
class person {
public:
	//默认构造函数
	person() {
		cout << "默认构造函数" << endl;
	}
	//有参构造函数
	person( int a)
	{
		m_age = a;
		cout << "有参构造函数 m_age = " << m_age << endl;
	}
	// 拷贝构造函数
	person(const person &p){
		m_age = p.m_age;
		cout << "拷贝构造函数 age = " << m_age << endl;
	}
	//析构函数
	~person() {
		cout << "析构函数" << endl;
	}
	
public:
	int m_age;
};
void test01() {
	//使用场景1： 对象拷贝
	person p1=10;
	person p2 = p1;
}
void dowork01(person p) {
	cout << p.m_age << endl;
}
person dowork02(){
	person p5 = 88;
	return p5; //此时将p5拷贝

}
void test02() {
	//使用场景2： 将对象作为函数传入时
	person p3(20);
	dowork01(p3);//此时传入的就是拷贝构造的对象
}
void test03() { // 对象作为返回值时
	dowork02();
}
int main() {
	// 拷贝构造函数的使用的范围（我的理解）
	// 01. 将对象赋值给新的对象时；
	// 02. 对象作为函数输入参数时（形参）；
	// 03. 对象作为函数返回值时；
	/* 教程说法
	  01.使用一个已经创建完毕的对象来初始化一个新对象
      02.值传递的方式给函数参数传值
      03. 以值方式返回局部对象
	*/

	//test01();
	//test02();
	test03();
}