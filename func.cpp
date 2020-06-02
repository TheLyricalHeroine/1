#include "factory.hpp"
#include "factory0.hpp"
#include "factory1.hpp"
#include "class0.hpp"
#include "class1.hpp"

CVector** ReadFile(int *n)
{
	//int flag = 0;
	CVector0Factory Hori;
	CVector1Factory Vert;

	map<string, Factory*> factories_ = { 
	{"Hori",&Hori},
	{"Vert",&Vert}
	};
	
	ifstream in("in.txt");
	if (!in)
    {
        cout<<"Error with open file "<< '\n';
		//flag = 1;
        exit(0);//???
    }
	//cout<<"dfghjk"<<endl;
	
   	CVector **arr;
	
	
	arr = new CVector*[256];
	/*if (flag == 0)
	{*/
		double m;
		string I;
		int len;
		int i = 0;
		string str;
		
		while (!in.eof())
		{
			//cout<<"you are in while"<<endl;
			//double* v;
			
			in >> I;
			in >> str;
			in >> len;
			//v = new double[len];
			
			//cout<<"len= "<<len<<endl;
			
			
			(*n)=(*n)+1;
			//cout<<(*n)<<endl;
			auto resFactory = factories_[I];
			auto newVector = resFactory->Create();
			newVector->type = I;
			//cout<<"I = "<<I<<endl;
			
			//newVector->v = v;
			newVector->len = len;
			newVector->FileName = str;
			
		
			for (int i = 0; i < len; i++)
			{
				in >> newVector->v[i];
				//cout<<"v[i]= "<<newVector->v[i]<<endl;
				//v[i] = m;
			}
			
			arr[i] = newVector;
			i++;
			
			//delete[] v;
			
		}
		
	//}
	return arr;
}


CVector0 operator+(CVector& first, CVector& second)
{
	CVector0 result;
	result.v = first.v;
	result.len = first.len;
	result.FileName = first.FileName;
	
	for (int i = 0; i < first.len; i++)
	{
		result.v = new double[first.len];
	}
	
	if (first.len != second.len)
	{	
		cout<<"векторы разной длины"<<endl;
	}
	
	else
	{
		for (int i = 0; i < first.len; i++)
		{
			result.v[i] = first.v[i] + second.v[i];
		}
		
	}
	
	return result;
}

CVector0 operator-(CVector& first, CVector& second)
{
	CVector0 result;
	result.v = first.v;
	result.len = first.len;
	result.FileName = first.FileName;
	
	for (int i = 0; i < first.len; i++)
	{
		result.v = new double[first.len];
	}
	
	if (first.len != second.len)
	{
		cout<<"векторы разной длины"<<endl;
	}
	
	else
	{
		for (int i = 0; i < first.len; i++)
		{
			result.v[i] = first.v[i] - second.v[i];
		}
		
	}
	
	return result;
}


void autotest1() 
{
    cout<<"Test 1: start"<<endl;
	
	string FileName = "test.txt";
    double* a1; a1 = new double[5]; 
    double* b1; b1 = new double[5];
	
    a1[0] = 1.1;
	a1[1] = -2.2;
	a1[2] = -3.3;
	a1[3] = 4.4;
	a1[4] = 5.5;
	
	b1[0] = 1.1;
	b1[1] = 2.2;
	b1[2] = 3.3;
	b1[3] = 4.4;
	b1[4] = 5.5;
	
    CVector0 a(a1, 5, FileName);
    CVector0 b(b1, 5, FileName);
    CVector0 c = a + b;
	
	//cout<<a1.v[1]<<endl;
	c.Show();
	
    if ((c.v[0]==2.2)&&(c.v[1]==0)&&(c.v[2]==0)&&(c.v[3]==8.8) && (c.v[4]==11.0)
		&& (c.FileName == "test.txt") && (c.len == 5)) 
		{
			cout << "Test 1: OK!" << endl;
		}
		else 
		{
			cout << "Test 1: FAILED!" << endl;
		}
	cout<<endl;
}



void autotest2() 
{
    cout<<"Test 2: start"<<endl;
	
	int flag = 0;
	string FileName = "test.txt";
    double* a1; a1 = new double[5]; 
    double* b1; b1 = new double[5];
	
	for (int i = 0; i < 5; i++)
	{
		a1[i]=5.5;
		b1[i]=0.3;
	}
	
    CVector1 a(a1, 5, FileName);
    CVector1 b(b1, 5, FileName);
    CVector0 c;
	c = a - b;
	
	c.Show();
	
	for (int i = 0; i < c.len; i++) if (abs(c.v[i] - 5.2)< std::numeric_limits<double>::epsilon()) 
	{
		flag++;
	};
	
	
	if (flag == 5)
	{
		cout << "Test 2: OK!" << endl;
	}
	else 
	{
		cout << "Test 2: FAILED!" << endl;
	}
	
	cout<<endl;
}

void autotest3() 
{
    cout<<"Test 3: start"<<endl;
	
	string FileName = "test.txt";
    double* a1; a1 = new double[5]; 
    double* b1; b1 = new double[5];
	
    a1[0] = 1.1;
	a1[1] = -2.2;
	a1[2] = -3.3;
	a1[3] = 4.4;
	a1[4] = 5.5;
	
	b1[0] = 1.1;
	b1[1] = 2.2;
	b1[2] = 3.3;
	b1[3] = 4.4;
	b1[4] = 5.5;
	
    CVector0 a(a1, 5, FileName);
    CVector1 b(b1, 5, FileName);
    CVector1 c = a + b;
	
	//cout<<a1.v[1]<<endl;
	c.Show();
	
    if ((c.v[0]==2.2)&&(c.v[1]==0)&&(c.v[2]==0)&&(c.v[3]==8.8) && (c.v[4]==11.0)
		&& (c.FileName == "test.txt") && (c.len == 5)) 
		{
			cout << "Test 3: OK!" << endl;
		}
		else 
		{
			cout << "Test 3: FAILED!" << endl;
		}
	cout<<endl;
}

void autotest4() 
{
    cout<<"Test 4: start"<<endl;
	
	//string FileName = "test.txt";
    double* a1; a1 = new double[5]; 
    double* b1; b1 = new double[5];
	
    a1[0] = 1.1;
	a1[1] = -2.5;
	a1[2] = -3.5;
	a1[3] = 4.0;
	a1[4] = 5.5;
	
	b1[0] = 1.5;
	b1[1] = 2.5;
	b1[2] = 3.0;
	b1[3] = 4.4;
	b1[4] = 1.0;
	
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	
    CVector0 a(a1, 5, str1);
    CVector1 b(b1, 5, str2);
    double c;
	c = a * b;
	
	cout<<"c = "<<c<<endl;
	double epsilon = 0.000000000001;

    if (abs(c - 8.0) < epsilon)
	{
		cout << "Test 4: OK!" << endl;
		//cout<<abs(c-8.0)<<endl;
		//cout<<epsilon<<endl;
	}
		
	else 
	{
		cout << "Test 4: FAILED!" << endl;
		//cout<<abs(c-8.0)<<endl;
		//cout<<std::numeric_limits<double>::epsilon()<<endl;
	}
	
	
	cout<<endl;
	
	
	/*if ((c<8.0999999999999999)&&(c>=7.99999999999))
		cout<<"Test 4: OK!"<<endl;
	else 
		cout<<"Test 4: FAILED!"<<endl;
	
	cout<<endl;*/
	
	return;
}