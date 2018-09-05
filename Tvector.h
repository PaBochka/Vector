#pragma once
#include<iostream>
using namespace std;
class Exception{
protected:
	int num;
public:
	virtual void display() = 0;
};
template <class type>
class TVector
{
	class ExceptionOverflow :public Exception
	{
	public:
		ExceptionOverflow(int num)
		{
			this->num = num;
		}
		void display()
		{
			cout << "Error's number-" << num << endl;
		}
	};
protected:
	int Size; int temp;
	type*pVector;
	int Startindex;
public:
	TVector(int s = 10, int si = 0);
	~TVector();
	int operator==(const TVector<type> &v);
	int GetSize() const;// размер вектора  
	int GetStartIndex() const; // индекс первого элемента
	type GetValue(int index);
	TVector <type>(const TVector <type>&v);
	TVector <type> &operator = (const TVector <type> &op2);
	TVector <type> operator +(const TVector <type> &op2);
	TVector <type> operator -(const TVector <type> &op2);
	type operator * (const TVector <type> &op2);
	TVector <type> &operator * (type val);
	TVector <type> &operator + (type val);
	TVector <type> &operator - (type val);
	TVector <type> &operator ++();
	TVector <type> operator ++ (int);
	type &operator [](int index);
	friend istream &operator>>(istream &is, TVector <type> &val)
	{
		for (int i = 0; i < val.Size; i++)
			is >> val.pVector[i];
		return is;
	}
	friend ostream& operator<<(ostream &out, const TVector <type> &v)
	{
		int i;
		out << "(";
		for (i = 0; i < v.Size; i++)
			out << v.pVector[i] << ",";
		if (i == v.Size)
		{
			out << '\b' << ")";
		}
		return out;
	}
};
template <class type>
TVector <type> ::TVector(int s, int si)
{
	Size = s;
	/*temp = tmp;*/
	Startindex = si;
	pVector = new type[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = 0;
}
template <class type>
TVector < type > :: ~TVector()
{
	delete[] pVector;
}
template <class type>
int TVector < type > :: operator==(const TVector<type> &v)
{
	int res = 0;
	if (Size == v.Size)
		for (int i = 0; i < Size; i++)
			if (pVector[i] == v.pVector[i])
				res = 1;
			else { res = 0; break; }
	return res;
}
template <class type>
int TVector <type> ::GetSize() const// размер вектора 
{
	return Size;
}
template <class type>
int TVector < type > ::GetStartIndex() const
{
	return Startindex;
}
template <class type>
type TVector < type > ::GetValue(int index)
{
	try
	{
		if ((index >= (this->temp)) || (index < 0))
			throw ExceptionOverflow(404);
		return pVector[index - Startindex];
	}
	catch (ExceptionOverflow exp)
	{
		exp.display();
		return pVector[0];
	}
}
template <class type>
TVector < type >::TVector <type>(const TVector <type>&v)
{
	Size = v.Size; Startindex = v.Startindex; pVector = new type[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}
template <class type>
TVector < type >&TVector <type>::operator = (const TVector <type> &v)
{
	if (this != &v)
	{
		if (Size != v.Size)
		{
			delete[] pVector;
			pVector = new type[v.Size];
		}
		Size = v.Size;
		Startindex = v.Startindex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class type>
TVector <type> TVector < type > :: operator +(const TVector <type> &op2)
{
	if (Size > op2.Size)
	{
		TVector<type> res(*this);
		for (int i = 0; i < op2.Size; i++)
			res.pVector[i] = pVector[i] + op2.pVector[i];
		return res;
	}
	else {
		TVector<type> res(op2);
		for (int i = 0; i < Size; i++)
			res.pVector[i] = pVector[i] + op2.pVector[i];
		return res;
	}
}
template <class type>
TVector <type> TVector < type > :: operator -(const TVector <type> &op2)
{ 
	if (Size > op2.Size)
	{
		TVector<type>res(*this);
		for (int i = 0; i < op2.Size; i++)
			res.pVector[i] = pVector[i] - op2.pVector[i];
		return res;
	}
	else {
		TVector<type> res(op2);
		for (int i = 0; i < Size; i++)
			res.pVector[i] = pVector[i] - op2.pVector[i];
		return res;
	}
}
template <class type>
type TVector < type > :: operator *(const TVector <type> &op2)
{
	int min, max;
	if (Size > op2.Size){ max = Size; min = op2.Size; }
	else{ max = op2.Size; min = Size; }
	type res = 0;
	for (int i = 0; i < min; i++)
		res = res + (pVector[i] * op2.pVector[i]);
	return res;
}
template <class type>
TVector <type> &TVector < type > ::operator * (type val)
{
	for (int i = 0; i < this->Size; i++)
		pVector[i] *= val;
	return *this;
}
template <class type>
TVector <type> &TVector < type > ::operator + (type val)
{
	for (int i = 0; i < this->Size; i++)
		pVector[i] += val;
	return *this;
}
template <class type>
TVector <type> &TVector < type > ::operator - (type val)
{
	for (int i = 0; i < this->Size; i++)
		pVector[i] -= val;
	return *this;
}
template <class type>
TVector <type> &TVector < type > ::operator ++()
{
	for (int i = 0; i < Size; i++)
		++pVector[i];
	return *this;
}
template <class type>
TVector <type> TVector < type > :: operator ++ (int)
{
	TVector res(*this);
	operator++();
	return res;
}
template <class type>
type &TVector < type > ::operator [](int index)
{
	try
	{	
		if ((index >=(Size+Startindex)) || (index<0))
			throw ExceptionOverflow(404);
		return pVector[index - Startindex];
	}
	catch (ExceptionOverflow exp)
	{
		exp.display();
		return pVector[0];
	}
}
