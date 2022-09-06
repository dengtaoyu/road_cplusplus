#pragma once
#include<iostream>
using namespace std;
template<class T>
class Myarray
{
public:
	//有参构造
	Myarray(int capicity)
	{
		cout << "有参构造函数" << endl;
		this->m_capicity = capicity;
		this->m_size = 0;
		pArray = new T[this->m_capicity]; //在堆区开拓没存存放 T[5]的数据；
	}
	// 拷贝构造函数
	Myarray(const Myarray& p)
	{
		cout << "拷贝构造函数" << endl;
		this->m_capicity = p.m_capicity;
		this->m_size = p.m_size;
		this->pArray = new T[p.m_capicity]; // 开辟空间
		// 判断P是否为空，不为空的话，将P中的数据赋值给Myarray
		if (p.pArray != NULL)
		{
			for (int i = 0; i < p.m_size; i++)
			{
				this->pArray[i] = p.pArray[i]; // 
			}
		}
	}

	// =运算符重载
	Myarray& operator=(const Myarray& p)
	{

		cout << " =  运算符重载" << endl;
		// 先判断自己是否为空，不为空，先置空
		if (this->pArray != NULL)
		{
			this->pArray = NULL;
			this->m_capicity = 0;
			this->m_size = 0;
		}
		//然后进行赋值操作
		//先判断传入是否为空，不为空在进行操作
		if (p.pArray != NULL)
		{
			this->m_capicity = p.m_capicity;
			this->m_size = p.m_size;
			this->pArray = new T[this->m_capicity];
			// 赋值操作
			for (int i = 0; i < p.m_size; i++)
			{
				this->pArray[i] = p.pArray[i];
			}
		}
		return *this;
	}
	// 成员函数 
	// 01 - pushback
	void pushback(const T &t)
	{
		//先判断是否已经满容量了，如果满的话就无法存入了
		if (this->m_capicity == this->m_size)
		{
			cout << "容量已满，无法存入" << endl;
			return;
		}
		this->pArray[this->m_size] = t;
		this->m_size++;
	}
	// 重写 [] 运算符 
	T & operator[](const int& val)
	{
		return this->pArray[val];
	}
	// 尾删popback
	void popback()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	// 获取数组容量
	int getCapicity()
	{
		return this->m_capicity;
	}
	// 获取数组大小
	int getsize()
	{
		return this->m_size;
	}





	// 析构函数
	~Myarray()
	{
		cout << " 析构函数" << endl;
		if (this->pArray != NULL)
		{
			delete[] this->pArray;
			this->pArray = NULL;//置空，防止产生野指针
			this->m_size = 0;
			this->m_capicity = 0;
		}
	}
	
public:
	T* pArray;
	int m_capicity;
	int m_size;
};