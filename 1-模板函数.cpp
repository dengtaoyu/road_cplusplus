#include<iostream>
using namespace std;
#include<string>
/*
	1. 模板的分类：
		函数模板、类模板
	2. 函数模板的作用： 数据类型参数化，在函数定义阶段不指定具体数据类型
	3. 函数模板语法：
		template<typename T>
		void myswap(T &a,T&b)
		{
			T temp = a;
			a = b;
			b =temp;
		}
		// 调用方法
		int a  = 10;
		int  b = 20;
		方法1：类型自动推导法
		myswap(a,b);
		方法2：类型指定法
		myswap<int>(a,b);

*/
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test()
{
	int  a = 10;
	int  b = 20;
	//方法1：类型指定方法
	//myswap<int>(a, b);
	// 方法2： 类型自动推导
	myswap(a, b);
	cout << "a= " << a
		<< "   " << " b= " << b << endl;

}
int main()
{
	test();
	cout<<"hello"<<endl;
	return 0;
}