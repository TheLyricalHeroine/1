#include "factory.hpp"
#include "factory1.hpp"
#include "class1.hpp"

CVector* CVector1Factory::Create()
{
	//cout<<"hello, you are in factory1"<<endl;
	double *v1{};
	int len1 = 0;
	string FileName1 = "";
	return new CVector1(v1, len1, FileName1);
}