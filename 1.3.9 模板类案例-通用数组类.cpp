#include<iostream>
using namespace std;
#include"Myarray.hpp"

/* 
*   通用数组类的要求：
*	1. 可以存放内置数据类型和自定义数据类型；
*	2. 数组中的数据存放到堆区  这怎么实现？
*	3. 构造函数中传入数组的容量
*	4. 提供拷贝构造函数，和operator=操作符，防止浅拷贝的问题
*	5. 提供尾删法和尾插法，对数据数据进行删除增加
*	6. 通过下表方式访问数组中的元素
*	7. 可以获取数组中当前元素的容量和个数
*/
// 注意模板 分文件写时，需要将类命名为.hpp
class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void printPerson(Myarray<person> & p)
{
	for (int i = 0; i < p.getsize(); i++)
	{
		cout << "姓名：" << p.pArray[i].name << "---- 年龄" << p.pArray[i].age << endl;
	}
}


int main()
{
	//Myarray<int> m3(5);
	//for (int i = 0; i < 3; i++)
	//{
	//	m3.pushback(i);
	//}
	//for (int i = 0; i < m3.m_size; i++)
	//{
	//	cout << m3.pArray[i] << endl;
	//}
	//Myarray<int> m2(100);
	//Myarray<int> m1(m3);
	//m2 = m1;
	person p1("张三", 19);
	person p2("李思", 20);
	person p3("赵武", 21);
	person p4("孙刘", 22);
	person p5("王琦", 23);
	Myarray<person> p(10);
	p.pushback(p1);
	p.pushback(p2);
	p.pushback(p3);
	p.pushback(p4);
	p.pushback(p5);
	printPerson(p);

	
	
}