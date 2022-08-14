#include<iostream>
using namespace std;
#include<fstream>
#define MAX 100
//创建 联系人结构体
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
//创建 通讯录结构体
struct AddressBook
{
	struct person PersonArr[MAX];   //最大容量是1000
	int m_size;  // 通讯录中的数量

};

// 显示通讯录
void showMenu()
{
	cout << "********************************" << endl;
	cout << "********  1、添加联系人 ********" << endl;
	cout << "********  2、显示联系人 ********" << endl;
	cout << "********  3、删除联系人 ********" << endl;
	cout << "********  4、查找联系人 ********" << endl;
	cout << "********  5、修改联系人 ********" << endl;
	cout << "********  6、清空联系人 ********" << endl;
	cout << "********  7、保存到本地 ********" << endl;
	cout << "********  0、退出通讯录  *******" << endl;
	cout << "********************************" << endl;
}

// 函数1：添加联系人
void addPerson(AddressBook & ab )
{
	// 判断通讯录是否满
	if (ab.m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}else
	{
		// 添加联系人
		//姓名
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;


		ab.PersonArr[ab.m_size].name = name;
		// 性别
		cout << "请输入性别 1---男  2---女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab.PersonArr[ab.m_size].sex = sex;
				break;
			}
			else {
				cout << "输入错误" << endl;
			}
		}
		// 年龄
		cout << "年龄:" << endl;
		int age;
		cin >> age;
		ab.PersonArr[ab.m_size].age = age;
		// 电话
		cout << "电话:" << endl;
		string phone;
		cin >> phone;
		ab.PersonArr[ab.m_size].phone = phone;
		//地址
		cout << "地址:" << endl;
		string address;
		cin >> address;
		ab.PersonArr[ab.m_size].address = address;
		//更新人数
		ab.m_size++;

		cout << "添加成功!" << endl;
		system("pause");
		system("cls");
	}



}

// 函数2：显示通讯录所有名单
void showAll(AddressBook & ab)
{
	if (ab.m_size > 0) 
	{
		for (int i = 0; i < ab.m_size; i++)
		{
			cout << "姓名:" <<ab.PersonArr[i].name << "\t";
			cout << "性别:" << (ab.PersonArr[i].sex == 1 ? "男" : "女") << "\t"; //注意整体要括号括起来
			cout << "年龄:" << ab.PersonArr[i].age << "\t";
			cout << "电话:" << ab.PersonArr[i].phone << "\t";
			cout << "地址:" << ab.PersonArr[i].address << endl;
			
		}
	}
	else {
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "所有联系人已加载完毕" << endl;
	system("pause");
	system("cls");

}

// 函数3  姓名是否存在函数

int isExist(AddressBook& abs, string name)
{
	for (int i = 0; i < abs.m_size; i++)
	{
		if (name == abs.PersonArr[i].name)
		{
			return i;
		}
		
	}
	cout << "查无此人" << endl;
	system("pause");
	system("cls");
	return -1;
}

// 函数4 删除指定联系人
void deletePerson(AddressBook& abs)
{
	// 输入要删除人的姓名
	//判断是否在在
	cout << "请输入要查询的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		// 移位删除
		for (ret; ret < abs.m_size - 1; ret++)
		{
			abs.PersonArr[ret] = abs.PersonArr[ret + 1];
		}
		abs.m_size--;
		cout << "删除" << name << "成功" << endl;
		system("pause");
		system("cls");
	}
}
//5. 查联系人
void findperson(AddressBook& abs)
{
	cout << "请输入要查询人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "所查人信息如下：" << endl;
		cout << "姓名：   " << abs.PersonArr[ret].name << "\t";
		cout << "性别：   " << (abs.PersonArr[ret].sex == 1 ? "男":"女" )<< "\t";
		cout << "年龄：   " << abs.PersonArr[ret].age << "\t";
		cout << "手机号： " << abs.PersonArr[ret].phone << "\t";
		cout << "地址：   " << abs.PersonArr[ret].address << endl;
		system("pause");
		system("cls");
	}

}

//5.4 修改联系人信息
void modifyPerson(AddressBook& abs)
{
	cout << "请输入修改人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string  phone, address;
		int age, sex;
		cout << "性别：男：1       女：2" << endl;
		cin >> sex;
		cout << "年龄" << endl;
		cin >> age;
		cout << "phone" << endl;
		cin >> phone;
		cout << "地址" << endl;
		cin >> address;
		abs.PersonArr[ret].age = age;
		abs.PersonArr[ret].sex = sex;
		abs.PersonArr[ret].phone = phone;
		abs.PersonArr[ret].address = address;

	}


}

// 5.5 清空通讯录
void clearAll(AddressBook &abs)
{
	cout << "确定清空通讯录吗？ 确认输入Y" << endl;
	char input;
	cin >> input;
	if (input == 'Y')
	{
		abs.m_size = 0;
		cout << "清空成功" << endl;
	}
	else 
	{
		cout << "未能清空通讯录" << endl;
	}
	system("pause");
	system("cls");


}


//6. 读取本地文件
void getAddressBook(AddressBook& abs)
{
	ifstream fin; //创建输入文件流；
	fin.open("通讯录.txt");
	if (!fin.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	string name, sex, phone, adress;
	int age;
	string str;
	while (fin >> str)
	{
		fin >> name; abs.PersonArr[abs.m_size].name = name;
		fin >> str >> sex; abs.PersonArr[abs.m_size].sex = (int)(sex == "男" ? 1 : 2);
		fin >> str >> age; abs.PersonArr[abs.m_size].age = age;
		fin >> str >> phone; abs.PersonArr[abs.m_size].phone = phone;
		fin >> str >> adress; abs.PersonArr[abs.m_size].address = adress;
		abs.m_size++;

	}

}
// 7.保存通讯录到本地文件
void saveAddressBooks(AddressBook ab)
{
	ofstream fout; //创建输出文件对象流 fout；
	fout.open("通讯录.txt");
	for (int i = 0; i < ab.m_size; i++)
	{
		fout << "姓名：" << ab.PersonArr[i].name << "\t";
		fout << "性别：" << (ab.PersonArr[i].sex == 1 ? "男":"女") << "\t";
		fout << "年龄：" << ab.PersonArr[i].age << "\t";
		fout << "姓名：" << ab.PersonArr[i].phone << "\t";
		fout << "姓名：" << ab.PersonArr[i].address << endl;
	}
	fout.close();//断开文件链接
	cout << "成功！" << endl;
	system("pause");
	system("cls");
}

int main()
{

	AddressBook AB ;
	AB.m_size = 0;
	//getAddressBook(AB);


	while(true)
	{
		showMenu();

		int select = 0;
		cout << "请选择功能序号" << endl;
		cin >> select;
		if (select < 8 && select >= 0)
		{
			switch (select)
			{
			case 1: //添加联系人
				addPerson(AB);
				break;
			case 2: //显示联系人
				showAll(AB);
				break;
			case 3: //删除联系人
				deletePerson(AB);
				break;
			case 4: //查找联系人
				findperson(AB);
				break;
			case 5: //修改联系人
				modifyPerson(AB);
				break;
			case 6: //清空联系人
				clearAll(AB);
				break;
			case 7: //保存到本地
				saveAddressBooks(AB);
				break;
			case 0: //退出通讯录				
				return 0;
			}
		}
		else {
			cout << "输入有误" << endl;
		}


	}

	return 0;
}