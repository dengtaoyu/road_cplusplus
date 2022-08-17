#include<iostream>
using namespace std;
class person {
public:
	person(int m) {
		m_age = new int(m); //此处在堆内存开辟了地址，析构函数必须释放相应的内存
	}
	// 重写赋值运算符
	person& operator=(person &p) {
		//m_age = p.m_age //赋值写法
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		
		return *this;
	}
	int * m_age;


	~person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}
};
void test() {
	person p1(10);
	person p2(20);
	//person p3 = p2; //未重载赋值运算符时，该语句可以通过编译，说明class默认创建了赋值运算函数
	cout << "p1 的年龄"<<*p1.m_age << endl;
	cout << "p2 的年龄" << *p2.m_age << endl;
}
int main() {
	test();
}