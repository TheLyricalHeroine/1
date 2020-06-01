#include "class.hpp"
#include "class0.hpp"
#include "class1.hpp"
#include "func.hpp"


using namespace std;

int main()
{
	cout<<"Hello, do you want the pretest of coding?"<<endl<<endl;
	
	int *n = new int(0);
	//cout<<(*n)<<endl;
	CVector** arr = ReadFile(n);
	//cout<<"step1"<<endl;
	//cout<<"*n= "<<*n<<endl;
	
	for (int i = 0; i < *n; i++)
	{
		arr[i]->output();
		//cout<<"I "<<arr[i]->type<<endl;
	}
	
	delete n;
	
	autotest1();
	autotest2();
	autotest3();
	autotest4();
	
	//string FileName = "test.txt";
	cout<<"the end"<<endl;
	
	
	return 0;
}