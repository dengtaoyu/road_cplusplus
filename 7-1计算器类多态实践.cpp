#include<iostream>
using namespace std;
#include<string>
/* 
*	����ͨ�����Ͷ�̬ʵ�ּ�������㣻
*	��̬���е㣺
*		1.0 ����ṹ����
*		2.0 �ɶ���ǿ
*		3.0 ���ں��ڴ����ά������չ
*/

// ��ͨ����ʵ�ּ�����
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
// ��̬����ʵ�ּ�����

class abstractCalculator {
public:
		int m1;
		int m2;
		virtual int getresult() {  //����һ���麯��
			return 0;
		}

};
class addCalculator :public abstractCalculator {
	//��д������麯��
	 int getresult()
	 {  //����һ���麯��
		return m1 + m2;
	 }
};
class subCalculator :public abstractCalculator {
	//��д������麯��
	int getresult() 
	{  //����һ���麯��
		return m1 - m2;
	}
};

class mulCalculator :public abstractCalculator {
	//��д������麯��
	int getresult()
	{  //����һ���麯��
		return m1 * m2;
	}
};

void test02() {
	// ����ָ��or ���� ָ���������
	abstractCalculator* abc = new addCalculator; // �ڶ�ȥ�����ڴ棬����ָ�룬����֮����Ҫdelete ���ڴ棻
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "+�Ľ�� = " << abc->getresult() << endl;
	delete abc;  //ʹ�����ͷŸ��ڴ�  ������abc��������Ȼ�� abstractCalculator*��ֻ��ָ��Ϊnull��
	abc = new subCalculator;
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "- �Ľ�� = " << abc->getresult() << endl;
	delete abc;
	abc = new mulCalculator;
	abc->m1 = 200;
	abc->m2 = 20;
	cout << "* �Ľ�� = " << abc->getresult() << endl;
	delete abc;

}
int main() {
	//test01(); //��ͨ����ʵ�ּ�����
	test02();
}