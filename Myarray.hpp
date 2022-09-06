#pragma once
#include<iostream>
using namespace std;
template<class T>
class Myarray
{
public:
	//�вι���
	Myarray(int capicity)
	{
		cout << "�вι��캯��" << endl;
		this->m_capicity = capicity;
		this->m_size = 0;
		pArray = new T[this->m_capicity]; //�ڶ�������û���� T[5]�����ݣ�
	}
	// �������캯��
	Myarray(const Myarray& p)
	{
		cout << "�������캯��" << endl;
		this->m_capicity = p.m_capicity;
		this->m_size = p.m_size;
		this->pArray = new T[p.m_capicity]; // ���ٿռ�
		// �ж�P�Ƿ�Ϊ�գ���Ϊ�յĻ�����P�е����ݸ�ֵ��Myarray
		if (p.pArray != NULL)
		{
			for (int i = 0; i < p.m_size; i++)
			{
				this->pArray[i] = p.pArray[i]; // 
			}
		}
	}

	// =���������
	Myarray& operator=(const Myarray& p)
	{

		cout << " =  ���������" << endl;
		// ���ж��Լ��Ƿ�Ϊ�գ���Ϊ�գ����ÿ�
		if (this->pArray != NULL)
		{
			this->pArray = NULL;
			this->m_capicity = 0;
			this->m_size = 0;
		}
		//Ȼ����и�ֵ����
		//���жϴ����Ƿ�Ϊ�գ���Ϊ���ڽ��в���
		if (p.pArray != NULL)
		{
			this->m_capicity = p.m_capicity;
			this->m_size = p.m_size;
			this->pArray = new T[this->m_capicity];
			// ��ֵ����
			for (int i = 0; i < p.m_size; i++)
			{
				this->pArray[i] = p.pArray[i];
			}
		}
		return *this;
	}
	// ��Ա���� 
	// 01 - pushback
	void pushback(const T &t)
	{
		//���ж��Ƿ��Ѿ��������ˣ�������Ļ����޷�������
		if (this->m_capicity == this->m_size)
		{
			cout << "�����������޷�����" << endl;
			return;
		}
		this->pArray[this->m_size] = t;
		this->m_size++;
	}
	// ��д [] ����� 
	T & operator[](const int& val)
	{
		return this->pArray[val];
	}
	// βɾpopback
	void popback()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	// ��ȡ��������
	int getCapicity()
	{
		return this->m_capicity;
	}
	// ��ȡ�����С
	int getsize()
	{
		return this->m_size;
	}





	// ��������
	~Myarray()
	{
		cout << " ��������" << endl;
		if (this->pArray != NULL)
		{
			delete[] this->pArray;
			this->pArray = NULL;//�ÿգ���ֹ����Ұָ��
			this->m_size = 0;
			this->m_capicity = 0;
		}
	}
	
public:
	T* pArray;
	int m_capicity;
	int m_size;
};