#include <iostream>
#include "myarray.hpp"
using namespace std;
void print(myarray<int>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i];
	}
	cout << " " << endl;
}
class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->pm_name = name;
		this->pm_age = age;
	};
	string pm_name;
	int pm_age;
};

void test()
{
	myarray<int> arr1(10);
	for (int i = 0; i < 6; i++)
	{
		arr1.pushback(i);
	}
	print(arr1);
	cout << "arr1容量 " << arr1.getfull() << endl;
	cout << "arr1大小 " << arr1.getsize() << endl;
	arr1.lastdelete();
	print(arr1);
	cout << "arr1容量 " << arr1.getfull() << endl;
	cout << "arr1大小 " << arr1.getsize() << endl;

	myarray<int> arr2(arr1);
	print(arr2);
	cout << "arr2容量 " << arr2.getfull() << endl;
	cout << "arr2大小 " << arr2.getsize() << endl;
	arr2.lastdelete();
	print(arr2);
	cout << "arr2容量 " << arr2.getfull() << endl;
	cout << "arr2大小 " << arr2.getsize() << endl;
	myarray<int> arr3(100);
	arr3 = arr1;
	print(arr3);
	cout << "arr3容量 " << arr3.getfull() << endl;
	cout << "arr3大小 " << arr3.getsize() << endl;
	arr3.lastdelete();
	print(arr3);
	cout << "arr3容量 " << arr3.getfull() << endl;
	cout << "arr3大小 " << arr3.getsize() << endl;
	myarray<person>arr4(5);


}

int main()
{
	test();
}