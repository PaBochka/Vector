#pragma once
#include<iostream>
#include <stdio.h>
#include"Tvector.h"
using namespace std;
template <class type>
Tvector<type>::Tvector(int s1, int Startindex)
{
	size = s1;
	startindex = Startindex;
	coord = new type[size];
	cout << "size from constructor=" << size << endl;
}
template <class type>
Tvector < type > :: ~Tvector()
{
	delete[]coord;
}
template <class type>
int Tvector < type > :: operator==(const Tvector<type> &v)
{
	int res = 0;
	if (size == v.size)

		res = 1;
	return res;
}
template <class type>
int Tvector <type> ::GetSize() const// размер вектора 
{
	return size;
}
template <class type>
int Tvector < type > ::GetStartIndex()
{
	return startindex;
}
template <class type>
type Tvector < type > ::GetValue(int pos)
{
	//	try{
	//		if ((pos>size) || (pos < 0))
	//			throw coord[startindex];
	//		return coord[pos];
	//	}
	//	catch (Tvector <type> coordinate){
	//		return coordinate;
	//	}
	if ((pos > size) || (pos < 0))
		return coord[startindex]; else return coord[pos];
}
template <class type>
Tvector < type >::Tvector <type>(const Tvector <type>&v)
{
	size = v.size; startindex = v.startindex; coord = new type[size];
	for (int i = 0; i < size; i++)
		coord[i] = v.coord[i];
}
template <class type>
Tvector < type >&Tvector <type>::operator = (const Tvector <type> &op2)
{
	if (this == &op2) return *this;
	if (size < op2.size) { delete[]coord; size = op2.size; coord = new type[size]; }
	for (int i = 0; i < size; i++)
		coord[i] = op2.coord[i];
	return *this;
}
template <class type>
Tvector <type> Tvector < type > :: operator +(const Tvector <type> &op2)
{
	int min, max;
	if (size > op2.size){ max = size; min = op2.size; }
	else{ max = op2.size; min = size; }
	Tvector res(max);
	for (int i = 0; i < max; i++)
		res.coord[i] = coord[i] + op2.coord[i];
	return res;
}
template <class type>
Tvector <type> Tvector < type > ::operator -(const Tvector <type> &op2)
{
	int min, max;
	if (size > op2.size){ max = size; min = op2.size; }
	else{ max = op2.size; min = size; }
	Tvector res(max);
	for (int i = 0; i < max; i++)
		res.coord[i] = coord[i] - op2.coord[i];
	return res;
}
template <class type>
type Tvector < type > :: operator * (const Tvector <type> &op2)
{
	int min, max;
	if (size > op2.size){ max = size; min = op2.size; }
	else{ max = op2.size; min = size; }
	type res = 0;
	for (int i = 0; i < min; i++)
		res = res + (coord[i] * op2.coord[i]);
	return res;
}
template <class type>
Tvector <type> &Tvector < type > ::operator * (type val)
{
	for (int i = 0; i < this->size; i++)
		coord[i] *= val;
	return *this;
}
template <class type>
Tvector <type> &Tvector < type > ::operator + (type val)
{
	for (int i = 0; i < this->size; i++)
		coord[i] += val;
	return *this;
}
template <class type>
Tvector <type> &Tvector < type > ::operator - (type val)
{
	for (int i = 0; i < this->size; i++)
		coord[i] -= val;
	return *this;
}
template <class type>
Tvector <type> &Tvector < type > ::operator ++()
{
	for (int i = 0; i < size; i++)
		++coord[i];
	return *this;
}
template <class type>
Tvector <type> Tvector < type > :: operator ++ (int)
{
	Tvector res(*this);
	operator++();
	return res;
}
template <class type>
type &Tvector < type > ::operator [](int index)
{
	return coord[index];
}
template <class type>
ostream &operator<<(ostream &os, const Tvector<type>&v)
{
	cout << "HUYLOOOOO" << endl;
	cout << "Vector size = " << v.size << endl;
	cout << "Vector startindex = " << v.startindex << endl;
	for (int i = 0; i < v.size; i++)
	{
		os << v.coord[i] << " ";
	}
	return os;
}
template <class type>
istream &operator>>(istream &is, Tvector <type> &val)
{
	for (int i = 0; i < val.size; i++)
		is >> val.coord[i];
	return is;
}

