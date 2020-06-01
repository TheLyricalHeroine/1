#include "class.hpp"


CVector::CVector() = default;
CVector::~CVector() = default;

CVector::CVector(int len2)
{
	FileName = ""; 
	len=len2;
	v = new double[len];
	
	for (int i=0; i < len; i++)
	{
		v[i]=0;
	}
	
}

CVector::CVector(double *v1, int len1, string FileName1)
{
	FileName = FileName1;
	len = len1;
	v = new double[len];
	
	for (int i = 0; i < len; i++)
	{
		v[i]=v1[i];
	}
	
}

CVector::CVector(const CVector& other)
{
	FileName = other.FileName;
	len = other.len;
	v = new double[len];
	
	for (int i = 0; i < len; i++)
	{
		v[i] = other.v[i];
	}
	
}

double CVector::operator* (const CVector& other)
{
	double result = 0;
	if (len != other.len)
	{
		cout<<"векторы разной длины"<<endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			result += v[i]*other.v[i];
		}
	}
	
	return result;
}

CVector& CVector::operator= (const CVector& other)
{
	
	FileName = other.FileName;
	len  =other.len;
	v = new double[len];
	
	for (int i = 0; i < len; i++)
	{
		v[i] = other.v[i];
	}
	
	return *this;
}

void CVector::Show()
{
	cout<<"(";
	for (int i = 0; i < len; i++)
	{
		cout<<v[i];
		if (i!=len-1) {cout<<",";}
	}
	cout<<")"<<endl;
}
		

//CVector& operator+ (const CVector& other);
//CVector& operator- (const CVector& other);