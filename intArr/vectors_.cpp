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

void vectors_::print()
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
