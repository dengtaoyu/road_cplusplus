#include<iostream>
using namespace std;
/*
	1. ���麯����ʲô��
			������麯����һ�㲻�ᱻ���ã���˿��Խ������Ϊ���麯����
			�﷨��virtual ����ֵ���� �������������б� = 0��
	2. ��������ʲô��
			���д��麯���������������
	3. ��������ص�
			�ص㣺1. �������޷�ʵ����
				  2. ����̳г�����󣬱�����д�����еĴ��麯������������Ҳ�ǳ�����
	4. ���ö�̬������ʵ�ֲ�ͬ���ϵ�����
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
{ // �̳��˳����࣬����Ҫ��д�������еĴ��麯�������� �ͳ����࣬�޷�ʵ����
	virtual void boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	virtual void brew() 
	{
		cout << "����" << endl;
	}
	virtual void PutIn() 
	{
		cout << "���뿧�ȱ���" << endl;
	}
	virtual void fulioao() 
	{
		cout << "����ţ�̺�sugar" << endl;
	}
};

class tea :public abstractdrink
{ // �̳��˳����࣬����Ҫ��д�������еĴ��麯�������� �ͳ����࣬�޷�ʵ����
	virtual void boil()
	{
		cout << "���޹���ˮ" << endl;
	}
	virtual void brew()
	{
		cout << "����" << endl;
	}
	virtual void PutIn()
	{
		cout << "��������" << endl;
	}
	virtual void fulioao()
	{
		cout << "��������" << endl;
	}
};
void dowork(abstractdrink* abs) { //abstractdrink * abs
	abs->makedrink(); 
	delete abs; // ���������Ƕ��ڴ��ϴ�����ָ�룬��Ҫ�ͷŶ��ڴ�
}
void test() {
	
	dowork(new coffee);
	cout << "------------------" << endl;
	dowork(new tea);
}
int main() {
	test();
}