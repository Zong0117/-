#pragma once
#include <iostream>
using namespace std;
template<class T>
class myarray
{
public:
	myarray(int full) //有参构造
	{
		cout << "有参构造" << endl;
		this->m_full = full;
		this->arrayAdress = new T[this->m_full];
		this->m_size = 0;
	}

	myarray(const myarray& arr) //拷贝构造
	{
		cout << "拷贝构造" << endl;
		this->m_full = arr.m_full;
		this->m_size = arr.m_size;

		this->arrayAdress = new T[arr.m_full];

		for (int i = 0; i < this->m_size; i++)
		{
			this->arrayAdress[i] = arr.arrayAdress[i];
		}
	}
	myarray& operator=(const myarray& arr)
	{
		cout << "operator=重载" << endl;

		if (this->arrayAdress != NULL)
		{
			delete[] this->arrayAdress;
			this->arrayAdress = NULL;
			this->m_full = 0;
			this->m_size = 0;
		}
		this->m_full = arr.m_full;
		this->m_size = arr.m_size;
		this->arrayAdress = new T[arr.m_full];
		for (int i = 0; i < this->m_size; i++)
		{
			this->arrayAdress[i] = arr.arrayAdress[i];
		}
		return *this;
	}
	void lastdelete()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	void pushback(const T& add)
	{
		if (this->m_full == this->m_size)
		{
			return;
		}
		this->arrayAdress[this->m_size] = add;
		this->m_size++;
	}
	T& operator[](int findnum)
	{
		return this->arrayAdress[findnum];
	}
	int getfull()
	{
		return this->m_full;
	}
	int getsize()
	{
		return this->m_size;
	}
	~myarray()
	{
		cout << "析构函数" << endl;

		if (this->arrayAdress != NULL)
		{
			delete[] this->arrayAdress;
			this->arrayAdress = NULL;
		}
	}
private:
	T* arrayAdress;
	int m_full;
	int m_size;
};

