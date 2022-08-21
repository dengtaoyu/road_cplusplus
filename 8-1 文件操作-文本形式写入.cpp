#include<iostream>
using namespace std;
#include<fstream>
#include<string>
/*
	文件相关操作：
		1.分类：
			01. 文本文件
			02. 二进制文件
		2. 写入 ：：操作步骤
			01.引入头文件  include<iostream>
			02.创建流对象： ofstream  ofs；//写入流
			03.打开文件 ofs.open("dir",ios::out)
			04.ofs << "hello world"<<endl;
			05.关闭流 ofs.close();
		3. 读取：：操作步骤
			01.引入头文件  include<iostream>
			02.创建流对象： ifstream  ifs；//写入流
			03.打开文件 ifs.open("dir",ios::in)
			04.四种读取方法；
			05.关闭流 ifs.close();
*/
void test() {
	// 写入操作
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	ofs << "hello world" << endl;
	ofs << "good morning " << endl;
	ofs.close();
}

void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//// 方法1： 通过char buf[1024]={0};
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	// 方法2： 
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// 方法3： 该方法最简洁
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	// 方法4：
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