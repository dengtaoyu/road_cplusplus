#include<iostream>
using namespace std;
#include<string>
/*
	����ģ��ʵ�����������ַ����顢�������飩

*/
template<typename T>
void sortArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		//�� �±�Ϊi�������
		for (int j = i + 1; j < len; j++)
			if (arr[j] <  arr[i])
			{
				//�����ֵ���±����max�У�
				T temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
	}

}
void test()
{
	//int arr[] = { 555,3,588,9,6,4,8,2 };
	//sortArr(arr, 8);
	char chaArr[] = "destin";
	//��ӡ���
	sortArr(chaArr, sizeof(chaArr) / sizeof(char));
	for (int i = 0; i < sizeof(chaArr)/sizeof(char); i++)
	{
		cout << chaArr[i] << endl;
	}
}
int main()
{
	test();
	return 0;
}