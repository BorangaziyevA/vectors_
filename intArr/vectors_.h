#pragma once
#include<iostream>

using namespace std;
class vectors_
{
	int* arr;
	int size;
public:
	vectors_();
	vectors_(int size,int value = 0);
	vectors_(const vectors_ & obj);
	~vectors_();
	void clear();
	void pushBack(int z);
	void print();
};

