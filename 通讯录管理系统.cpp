#include<iostream>
using namespace std;
#include<fstream>
#define MAX 100
//���� ��ϵ�˽ṹ��
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
//���� ͨѶ¼�ṹ��
struct AddressBook
{
	struct person PersonArr[MAX];   //���������1000
	int m_size;  // ͨѶ¼�е�����

};

// ��ʾͨѶ¼
void showMenu()
{
	cout << "********************************" << endl;
	cout << "********  1�������ϵ�� ********" << endl;
	cout << "********  2����ʾ��ϵ�� ********" << endl;
	cout << "********  3��ɾ����ϵ�� ********" << endl;
	cout << "********  4��������ϵ�� ********" << endl;
	cout << "********  5���޸���ϵ�� ********" << endl;
	cout << "********  6�������ϵ�� ********" << endl;
	cout << "********  7�����浽���� ********" << endl;
	cout << "********  0���˳�ͨѶ¼  *******" << endl;
	cout << "********************************" << endl;
}

// ����1�������ϵ��
void addPerson(AddressBook & ab )
{
	// �ж�ͨѶ¼�Ƿ���
	if (ab.m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}else
	{
		// �����ϵ��
		//����
		cout << "����������" << endl;
		string name;
		cin >> name;


		ab.PersonArr[ab.m_size].name = name;
		// �Ա�
		cout << "�������Ա� 1---��  2---Ů" << endl;
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
				cout << "�������" << endl;
			}
		}
		// ����
		cout << "����:" << endl;
		int age;
		cin >> age;
		ab.PersonArr[ab.m_size].age = age;
		// �绰
		cout << "�绰:" << endl;
		string phone;
		cin >> phone;
		ab.PersonArr[ab.m_size].phone = phone;
		//��ַ
		cout << "��ַ:" << endl;
		string address;
		cin >> address;
		ab.PersonArr[ab.m_size].address = address;
		//��������
		ab.m_size++;

		cout << "��ӳɹ�!" << endl;
		system("pause");
		system("cls");
	}



}

// ����2����ʾͨѶ¼��������
void showAll(AddressBook & ab)
{
	if (ab.m_size > 0) 
	{
		for (int i = 0; i < ab.m_size; i++)
		{
			cout << "����:" <<ab.PersonArr[i].name << "\t";
			cout << "�Ա�:" << (ab.PersonArr[i].sex == 1 ? "��" : "Ů") << "\t"; //ע������Ҫ����������
			cout << "����:" << ab.PersonArr[i].age << "\t";
			cout << "�绰:" << ab.PersonArr[i].phone << "\t";
			cout << "��ַ:" << ab.PersonArr[i].address << endl;
			
		}
	}
	else {
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "������ϵ���Ѽ������" << endl;
	system("pause");
	system("cls");

}

// ����3  �����Ƿ���ں���

int isExist(AddressBook& abs, string name)
{
	for (int i = 0; i < abs.m_size; i++)
	{
		if (name == abs.PersonArr[i].name)
		{
			return i;
		}
		
	}
	cout << "���޴���" << endl;
	system("pause");
	system("cls");
	return -1;
}

// ����4 ɾ��ָ����ϵ��
void deletePerson(AddressBook& abs)
{
	// ����Ҫɾ���˵�����
	//�ж��Ƿ�����
	cout << "������Ҫ��ѯ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		// ��λɾ��
		for (ret; ret < abs.m_size - 1; ret++)
		{
			abs.PersonArr[ret] = abs.PersonArr[ret + 1];
		}
		abs.m_size--;
		cout << "ɾ��" << name << "�ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//5. ����ϵ��
void findperson(AddressBook& abs)
{
	cout << "������Ҫ��ѯ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "��������Ϣ���£�" << endl;
		cout << "������   " << abs.PersonArr[ret].name << "\t";
		cout << "�Ա�   " << (abs.PersonArr[ret].sex == 1 ? "��":"Ů" )<< "\t";
		cout << "���䣺   " << abs.PersonArr[ret].age << "\t";
		cout << "�ֻ��ţ� " << abs.PersonArr[ret].phone << "\t";
		cout << "��ַ��   " << abs.PersonArr[ret].address << endl;
		system("pause");
		system("cls");
	}

}

//5.4 �޸���ϵ����Ϣ
void modifyPerson(AddressBook& abs)
{
	cout << "�������޸��˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string  phone, address;
		int age, sex;
		cout << "�Ա��У�1       Ů��2" << endl;
		cin >> sex;
		cout << "����" << endl;
		cin >> age;
		cout << "phone" << endl;
		cin >> phone;
		cout << "��ַ" << endl;
		cin >> address;
		abs.PersonArr[ret].age = age;
		abs.PersonArr[ret].sex = sex;
		abs.PersonArr[ret].phone = phone;
		abs.PersonArr[ret].address = address;

	}


}

// 5.5 ���ͨѶ¼
void clearAll(AddressBook &abs)
{
	cout << "ȷ�����ͨѶ¼�� ȷ������Y" << endl;
	char input;
	cin >> input;
	if (input == 'Y')
	{
		abs.m_size = 0;
		cout << "��ճɹ�" << endl;
	}
	else 
	{
		cout << "δ�����ͨѶ¼" << endl;
	}
	system("pause");
	system("cls");


}


//6. ��ȡ�����ļ�
void getAddressBook(AddressBook& abs)
{
	ifstream fin; //���������ļ�����
	fin.open("ͨѶ¼.txt");
	if (!fin.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	string name, sex, phone, adress;
	int age;
	string str;
	while (fin >> str)
	{
		fin >> name; abs.PersonArr[abs.m_size].name = name;
		fin >> str >> sex; abs.PersonArr[abs.m_size].sex = (int)(sex == "��" ? 1 : 2);
		fin >> str >> age; abs.PersonArr[abs.m_size].age = age;
		fin >> str >> phone; abs.PersonArr[abs.m_size].phone = phone;
		fin >> str >> adress; abs.PersonArr[abs.m_size].address = adress;
		abs.m_size++;

	}

}
// 7.����ͨѶ¼�������ļ�
void saveAddressBooks(AddressBook ab)
{
	ofstream fout; //��������ļ������� fout��
	fout.open("ͨѶ¼.txt");
	for (int i = 0; i < ab.m_size; i++)
	{
		fout << "������" << ab.PersonArr[i].name << "\t";
		fout << "�Ա�" << (ab.PersonArr[i].sex == 1 ? "��":"Ů") << "\t";
		fout << "���䣺" << ab.PersonArr[i].age << "\t";
		fout << "������" << ab.PersonArr[i].phone << "\t";
		fout << "������" << ab.PersonArr[i].address << endl;
	}
	fout.close();//�Ͽ��ļ�����
	cout << "�ɹ���" << endl;
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
		cout << "��ѡ�������" << endl;
		cin >> select;
		if (select < 8 && select >= 0)
		{
			switch (select)
			{
			case 1: //�����ϵ��
				addPerson(AB);
				break;
			case 2: //��ʾ��ϵ��
				showAll(AB);
				break;
			case 3: //ɾ����ϵ��
				deletePerson(AB);
				break;
			case 4: //������ϵ��
				findperson(AB);
				break;
			case 5: //�޸���ϵ��
				modifyPerson(AB);
				break;
			case 6: //�����ϵ��
				clearAll(AB);
				break;
			case 7: //���浽����
				saveAddressBooks(AB);
				break;
			case 0: //�˳�ͨѶ¼				
				return 0;
			}
		}
		else {
			cout << "��������" << endl;
		}


	}

	return 0;
}