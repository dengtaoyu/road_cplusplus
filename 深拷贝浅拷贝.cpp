#include<iostream>
using namespace std;
// 深拷贝、浅拷贝 本质上就是 堆内存的多次释放的问题。
// 采用拷贝构造函数的方式 初始化新对象时，如果原来的对象申请过堆内存，则析构函数中必须释放该堆内存； 将实例作为新对象初始化
//初始化后，新实例对象和原来的实例对象，共同保存了同一个堆内存指针，因此析构函数会存在二次释放堆内存的问题；
// 解决方法：重新对象的拷贝构造函数，将其中传入的指针所存的对象重新申请一块堆内存；

class person {
public:
	//无参构造函数
	person() {
		cout << "无参构造函数" << endl;
	};
	//有参构造函数
	person(int age, int hi) {
		m_age = age;
		height = new int( hi);  /// hi 是创建实例是传入的身高数值；将这个身高数值存放在堆内存上；height 是个地址

		cout << "有参构造函数  age = "<< m_age <<"身高"<< *height<< endl;

	}
	//拷贝构造函数
	person(const person & p) {
		m_age = p.m_age;
		//height =p.height;  // 浅拷贝
		height = new int(*p.height);//深拷贝
		cout << "拷贝构造函数  m_age =  " << m_age << "身高" << *height << endl;

	}
	// 析构函数  需要释放堆内存
	~person() {
		if (height != NULL) {
			delete height;
		}
	}
public:
	int m_age;
	int* height;  //属性中有一个指针，该指针指向存储身高的地址；
};

void test01() {
	person  p1(10,160); // 有参构造
	person p2(p1);  // 拷贝构造
}

int main() {
	
	test01();
	return 0;
}