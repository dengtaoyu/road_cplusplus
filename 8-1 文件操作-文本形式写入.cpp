#include<iostream>
using namespace std;
#include<fstream>
#include<string>
/*
	�ļ���ز�����
		1.���ࣺ
			01. �ı��ļ�
			02. �������ļ�
		2. д�� ������������
			01.����ͷ�ļ�  include<iostream>
			02.���������� ofstream  ofs��//д����
			03.���ļ� ofs.open("dir",ios::out)
			04.ofs << "hello world"<<endl;
			05.�ر��� ofs.close();
		3. ��ȡ������������
			01.����ͷ�ļ�  include<iostream>
			02.���������� ifstream  ifs��//д����
			03.���ļ� ifs.open("dir",ios::in)
			04.���ֶ�ȡ������
			05.�ر��� ifs.close();
*/
void test() {
	// д�����
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	ofs << "hello world" << endl;
	ofs << "good morning " << endl;
	ofs.close();
}

void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//// ����1�� ͨ��char buf[1024]={0};
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	// ����2�� 
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// ����3�� �÷�������
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	// ����4��
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c ;
	}


	ifs.close();

}
int main() {
	//test();
	test02();
}