#include<iostream>
using namespace std;
/*
	���μ̳У�
	1. ����̳�˫�����ݣ��˷���Դ��
	2. ����virtual ���Խ�������⡣ ���ģ�������̳У�ά��virtual pointer table���ñ�洢�����Ա������ָ�룻
*/
class Animal {
public:
	int a;

};
class sheep:virtual public Animal{

};
class tuo:virtual  public Animal {

};

class sheeptuo: public tuo,public sheep {
};
void test() {
	sheeptuo  st;
	st.sheep::a = 28;
	st.tuo::a = 10;

	cout << st.a << endl;
}
int main() {
	test();



}
