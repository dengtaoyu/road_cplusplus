#include<iostream>
using namespace std;
#include<string>
/*
	利用模板实现数组排序（字符数组、整形数组）

*/
template<typename T>
void sortArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		//另 下表为i的数最大
		for (int j = i + 1; j < len; j++)
			if (arr[j] <  arr[i])
			{
				//将大的值得下表存在max中；
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
	//打印输出
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