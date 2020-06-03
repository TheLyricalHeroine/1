#include "factory.hpp"
#include "factory0.hpp"
#include "class0.hpp"

CVector* CVector0Factory::Create()
{
	//cout<<"hello, you are in factory0"<<endl;
	double *v1{};
	int len1 = 0;
	string FileName1 = "";
	return new CVector0(len1);
}