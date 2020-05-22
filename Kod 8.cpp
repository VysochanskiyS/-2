#pragma once
#include<iostream>
#include<ctime>
using namespace std;

template<typename T>
class Array
{
public:
	Array();
	Array(int aS);
	Array(const Array& other);
	~Array();
	template<typename T>
	friend std::ostream& operator<< (std::ostream& output, Array<T>& other);
	Array& operator=(Array<T>& other);
	void init_array();
	T count_sum();

private:
	int arrSize;
	T *arr;
};
template<typename T>
Array<T>::Array()
{
	arrSize = 0;
	arr = new T[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
}
template<typename T>
Array<T>::Array(int aS)
{
	arrSize = aS;
	arr = new T[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
	cout << "Array for random enter - 1\nArray for user enter - 2" << endl << "Please enter: ";
	int l = 1;
	cin >> l;
	switch (l)
	{
	case 1:
		srand(time(0));
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = rand() % 99-45;
		}
		break;
	case 2:
		for (int i = 0; i < arrSize; i++)
		{
			cout << "a[" << i << "]" << " = ";
			cin >> arr[i];
		}
		break;
	}
}

template<class T>
Array<T>::Array(const Array<T>& other)
{
	if (&arr != 0)
	{
		delete[] arr;
	}
	arrSize = other.arrSize;
	arr = new T[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete []arr;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, Array<T>& other)
{
	for (int i = 0; i < other.arrSize; i++)
	{
		output << "a["<<i<<"] = "<<other.arr[i] << endl;
	}
	output << endl;
	return output;
}

template<typename T>
Array<T>& Array<T>::operator= (Array<T>& other)
{
	if (this != &other)
	{
		if (&arr != 0)
		{
			delete[] arr;
		}
		arrSize = other.arrSize;
		arr = new T [arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	cout << "Operator =" << endl;
	return *this;
}

template<typename T>
void Array<T>::init_array()
{
	if (&arr != 0)
	{
		delete[] arr;
	}
	cout << "Enter the number of elements in the array: ";
	cin >> arrSize;
	arr = new T [arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
	cout << "Matrix for random enter - 1\nMatrix for user enter - 2\nPlease enter: ";
	int l = 1;
	cin >> l;
	switch (l)
	{
	case 1:
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = rand() % 99;
		}
		break;
	case 2:
		for (int i = 0; i < arrSize; i++)
		{
			cout << "a[" << i << "]" << "=";
			cin >> arr[i];
		}
		break;
	}
}
template<typename T>
T Array<T>::count_sum()
{
	int count=0;
	int j=0;
	int k=0;
	T res = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] >= 0)
		{
			count++;
			if (count == 2)
			{
				k = i;
				break;
			}
			j = i+1;
		}
	}
	if (j == k)
	{
		cout << "There is no elements between first and second positive array elements" << endl;
		return res = 0;
	}
	else
	{
		for (j; j < k; j++)
		{
			res += arr[j];
		}
		cout << "Sum between first and second positive array elements: " << res << endl;
		return res;
	}
}

int main()
{
	Array<int> a;
	int aS;
	cout << "Enter the number of elements in the array: ";
	cin >> aS;
	Array<int> a2(aS);
	cout <<"a2:\n"<< a2;
	a2.count_sum();
	a2.init_array();
	cout <<"a2:\n"<< a2;
	a = a2;
	cout << "\ta = a2;\na:\n"<< a;
	Array<int> a3(a2);
	cout <<"\ta3(a2);\na3:\n"<< a3;
	return 0;
}
