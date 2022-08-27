#include<iostream>
using namespace std;
/*
	模板函数和普通函数的区别：
	1. 模板函数不能发生隐式类型转化
	2. 普通函数隐式调用时，可以发生自动类型转化
	3. 模板函数使用指定数据类型调用时，可以发生隐式类型转化
*/
// 普通函数
int myAdd(int  a, int b)
{
	return a + b;
}
// 模板函数
template<typename T>
T Tadd(T a, T b)
{
	return a + b;
}
void test()
{
	int a = 10;
	int  b = 20;
	char c = 'c';
	// 1. 普通函数调用 会有隐式类型自动转化
	cout << myAdd(a, c) << endl;
	// 2. 模板函数 指定类型后，就可以发生隐式转化
	cout << Tadd<int>(a, c) << endl;
	// 3. 模板函数不能使用隐式类型转化
	//cout << Tadd(a, c) << endl;

}
int main()
{
	test();
}