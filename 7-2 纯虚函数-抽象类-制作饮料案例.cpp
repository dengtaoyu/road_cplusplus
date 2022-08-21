#include<iostream>
using namespace std;
/*
	1. 纯虚函数是什么？
			父类的虚函数，一般不会被调用，因此可以将将其变为纯虚函数；
			语法：virtual 返回值类型 函数名（参数列表） = 0；
	2. 抽象类是什么？
			含有纯虚函数的类叫做抽象类
	3. 抽象类的特点
			特点：1. 抽象类无法实例化
				  2. 子类继承抽象类后，必须重写父类中的纯虚函数，否则子类也是抽象类
	4. 利用多态技术，实现不同饮料的制作
*/
class abstractdrink
{
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void PutIn() = 0;
	virtual void fulioao() = 0;

	void makedrink() {
		boil();
		brew();
		PutIn();
		fulioao();
	}

};
class coffee :public abstractdrink 
{ // 继承了抽象类，必须要重写抽象类中的纯虚函数，否则 就抽象类，无法实例化
	virtual void boil()
	{
		cout << "煮农夫山泉" << endl;
	}
	virtual void brew() 
	{
		cout << "冲泡" << endl;
	}
	virtual void PutIn() 
	{
		cout << "倒入咖啡杯中" << endl;
	}
	virtual void fulioao() 
	{
		cout << "加入牛奶和sugar" << endl;
	}
};

class tea :public abstractdrink
{ // 继承了抽象类，必须要重写抽象类中的纯虚函数，否则 就抽象类，无法实例化
	virtual void boil()
	{
		cout << "煮娃哈哈水" << endl;
	}
	virtual void brew()
	{
		cout << "冲泡" << endl;
	}
	virtual void PutIn()
	{
		cout << "倒入茶壶中" << endl;
	}
	virtual void fulioao()
	{
		cout << "加入柠檬" << endl;
	}
};
void dowork(abstractdrink* abs) { //abstractdrink * abs
	abs->makedrink(); 
	delete abs; // 如果传入的是堆内存上创建的指针，需要释放堆内存
}
void test() {
	
	dowork(new coffee);
	cout << "------------------" << endl;
	dowork(new tea);
}
int main() {
	test();
}