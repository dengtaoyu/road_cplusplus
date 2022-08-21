#include<iostream>
using namespace std;
#include<fstream>
#include<string>
class person
{
public:
	char m_Name[64];
	int age;

};
void test() {
	// 执行写入操作
	person p = {"张三",18};
	
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	ofs.write((const char*) & p, sizeof(p));
	ofs.close();

}

void test02() {
	// 执行二进制文件读入
	person p;
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	ifs.read( (char*) &p, sizeof(p));
	cout << p.age << "  --- " << p.m_Name<< endl;
	ifs.close();
}
int main() {
	//test();
	test02();
	return 0;
}