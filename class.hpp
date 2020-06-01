#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <iterator>
#include <chrono>

using namespace std;

class CVector
{
	private:
	public:
	
	double* v;
	int len;
	string FileName;
	string type;
	
	CVector();
	CVector(int len2);
	CVector(double* v1, int len1, string FileName1);
	CVector(const CVector& other);

	virtual ~CVector();
	void Show();
	
	double operator* (const CVector& other);
	CVector& operator= (const CVector& other);
	
	virtual void output()=0;
};