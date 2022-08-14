#include<iostream>
using namespace  std;
//创建类
// 可以采用初始化列表的形式 对象赋初值
// 详细语法如下：
// person(int a , int b ):m_a(a),m_b(b){}
class person {
public:
	//无参构造
	person() {
		cout << "无参构造" << endl;
	};
	// 有参构造；采用初始化列表的方法赋初值
	person(int a,int b,int c):m_a(a),m_b(b),m_c(c) {
		cout << "有参构造" << endl;
		cout << m_a <<"\t"<< m_b << "\t" << m_c << endl;
	}
	// 拷贝构造
	person(const person & p){
		m_a = p.m_a;
		m_b = p.m_b;
		m_c = p.m_c;
	}
		int m_a;
		int m_b;
		int m_c;
};
void test01() {
	person p(10, 20, 30);
}
int main() {
	test01();
}