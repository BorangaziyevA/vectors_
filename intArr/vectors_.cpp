#include "vectors_.h"



vectors_::vectors_()
{
	this->size = 0;
	this->arr = nullptr;
}

vectors_::vectors_(int size, int val)
{
	if (size == 0)
	{
		this->size = 0;
		this->arr = nullptr;
		return;
	}
	this->size = size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
		this->arr[i] = val;
}

vectors_::vectors_(const vectors_ & obj)
{
	this->size = obj.size;
	if (size == 0)
	{
		this->arr = nullptr;
		return;
	}
	this->arr = new int[this->size];

	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

vectors_::~vectors_()
{
	clear();
}

void vectors_::clear()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->size = 0;
	}
}

int vectors_::getSize()const
{
	return this->size;
}

int vectors_::getElement(int x)const
{
	if(x >= 0 && x <this->size)
	return this->arr[x];

}

void vectors_::changeElement(int x,int pos)
{
	this->arr[pos] = x;
}

void vectors_::pushBack(int z)
{
	if (this->size == 0)
	{
		this->size++;
		this->arr = new int;
		*arr = z;
		return;
	}
	int* tmp;
	tmp = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	this->size++;
	tmp[this->size - 1] = z;
	delete[] this->arr;
	this->arr = tmp;
}

void vectors_::print()const
{
	for (size_t i = 0; i < this->size; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}

vectors_ & vectors_::operator=(const vectors_ & obj)
{
	if (this == &obj)
	{
		return *this;
	}
	this->clear();
	if (obj.size != 0)
	{
		this->size = obj.size;
		this->arr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
	}
	return *this;
}

vectors_ & vectors_::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return *this;
}

vectors_ vectors_::operator++(int)
{
	vectors_ tmp = *this;
	for (size_t i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return tmp;
}

vectors_ & vectors_::operator--()
{
	this->size--;
	int *tmp;
	tmp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	arr = tmp;
	return  *this;
}

vectors_ vectors_::operator--(int)
{

	vectors_ a = *this;
	this->size--;
	int *tmp;
	tmp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[] arr;
	arr = tmp;
	return a;
}

ostream & operator<<(ostream & os, const vectors_ & obj)
{
	obj.print();
	return os;
}

istream & operator>>(istream & is, vectors_ & obj)
{
	int h;
	cout << "Fill the vector" << endl;
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		cin >> h;
		obj.changeElement(h, i);
	}
	return is;
}

bool operator==(const vectors_ & a, const vectors_ & b)
{
	if (a.getSize() != b.getSize())
	{
		return false;
	}
	for (size_t i = 0; i < b.getSize(); i++)
	{
		if (a.getElement(i) != b.getElement(i))
		{
			return false;
		}

	}
	return true;
}

//vectors_ & vectors_::operator++()
//{
//	this->size++;
//	int *tmp;
//	tmp = new int[size];
//	for (size_t i = 0; i < size - 1; i++)
//	{
//		tmp[i] = this->arr[i];
//	}
//	tmp[size - 1] = 0;
//	delete[] arr;
//	arr = tmp;
//	return  *this;
//}
//
//vectors_ vectors_::operator++(int)
//{
//
//	vectors_ a = *this;
//	this->size++;
//	int *tmp;
//	tmp = new int[size];
//	for (size_t i = 0; i < size - 1; i++)
//	{
//		tmp[i] = this->arr[i];
//	}
//	tmp[size - 1] = 0;
//	delete[] arr;
//	arr = tmp;
//	return a;
//}
