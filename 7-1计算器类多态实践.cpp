#include<iostream>
using namespace std;
#include<string>
/* 
*	用普通方法和多态实现计算机计算；
*	多态的有点：
*		1.0 代码结构清晰
*		2.0 可读性强
*		3.0 利于后期代码的维护和扩展
*/

// 普通方法实现计算器
class calcutor {
public:
	int m1;
	int m2;
	int getresult(string oper) 
		{
			if (oper == "+") {
				return m1 + m2;
			}
		else if (oper == "-")	
			{
				return m1 - m2;
			}
		else if (oper == "*")
			{
				return m1 * m2;
			}
		
		}
};
void test01() {
	calcutor c1;
	c1.m1 = 20;
	c1.m2 = 5;
	cout << c1.getresult("+") << endl;
}
// 多态方法实现计算器

class abstractCalculator {
public:
		int m1;
		int m2;
		virtual int getresult() {  //创建一个虚函数
			return 0;
		}

};
class addCalculator :public abstractCalculator {
	//重写父类的虚函数
	 int getresult()
	 {  //创建一个虚函数
		return m1 + m2;
	 }
};
class subCalculator :public abstractCalculator {
	//重写父类的虚函数
	int getresult() 
	{  //创建一个虚函数
		return m1 - m2;
	}
};

class mulCalculator :public abstractCalculator {
	//重写父类的虚函数
	int getresult()
	{  //创建一个虚函数
		return m1 * m2;
	}
};

void test02() {
	// 父类指针or 引用 指向子类对象
	abstractCalculator* abc = new addCalculator; // 在堆去开辟内存，返回指针，用完之后需要delete 该内存；
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "+的结果 = " << abc->getresult() << endl;
	delete abc;  //使用完释放该内存  ，但是abc的类型依然是 abstractCalculator*，只是指向为null；
	abc = new subCalculator;
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "- 的结果 = " << abc->getresult() << endl;
	delete abc;
	abc = new mulCalculator;
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "* 的结果 = " << abc->getresult() << endl;
	delete abc;

}
int main() {
	//test01(); //普通方法实现计算器
	test02();
}