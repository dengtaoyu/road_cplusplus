#include<iostream>
using namespace std;
// ��Ա���� ��Ա��������Ա����
// ��̬������
//    �ص㣺1. ���ڶ��壬�����ʼ���� 2.���ж�����ͬһ�ݣ� 3.�༭�׶η����ڴ棬�������н׶Σ�4. ˽�л��������޷����ʺͳ�ʼ����
//    ���ʷ����� 1. ����::��̬�������� 2. ʵ��.��̬��������
// ��̬��Ա������ 
//    �ص�: 1. ���ж�����ͬһ������ 2. ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class person
{
public:
	int id;
	static string name;
	void func1() {
		cout << name << "���� ���ñ���" << endl;
	}
	static void func2() {
		cout << name << "��̬���� ���þ�̬����" << endl;
	}
//private:
//	static string name;
};
void test01() {
	cout<<person::name<<endl;
	person::func2();
}
 string person::name = "yudengtao";
int main() {
	test01();

}