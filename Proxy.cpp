// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Proxy.h"
//added a new comment

int Image::mImageCount=1;
int ImageProxy::mProxyImageCount = 1;

vector<string> Employee::mEmployees ;
int Employee::mNext=0;

int _tmain(int argc, _TCHAR* argv[])
{
	// Problem
	//You need to support resource-hungry objects
	cout<<"Example 1 ------------------"<<endl;
	//usual
	{
		cout<<"###############"<<endl;
		//constructing and destructing 5 objects when only 2 are used
		Image wImages[5];
		wImages[2].draw();
		wImages[3].draw();
	}
	//using Proxy
	{
		cout<<"###############"<<endl;
		ImageProxy wImagesProxy[5];
		wImagesProxy[2].draw(); //constructing when we need object
		wImagesProxy[3].draw();
	}

  cout<<"Example 2 ------------------"<<endl;
 // Use an extra level of indirection to support distributed, controlled, or intelligent access.

	//{"Tom", "Jana", "John", "Andrew"};
	Employee::mEmployees.push_back("Tom");
	Employee::mEmployees.push_back("Jana");
	Employee::mEmployees.push_back("John");
	Employee::mEmployees.push_back("Andrew");

	ProxyEmployee wEmployees[4];
	for (int idx=0; idx<4; idx++)
	{
		if (wEmployees[idx].withdraw(100))
		{
			cout<<"Operation goes well for "<<wEmployees[idx].getName()<<endl;
		}
		else
		{
			cout<<"Operation is not allowed for "<<wEmployees[idx].getName()<<endl;
		}
	}

	return 0;
}

