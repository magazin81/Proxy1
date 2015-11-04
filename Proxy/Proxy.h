#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Proxy Provides a surrogate or placeholder for another object to control access to it.

// Problem
//You need to support resource-hungry objects, 
//and you do not want to instantiate such objects unless and until they are actually 
//requested by the client.


//Example 1
class Image // usual Image
{
public:
	Image ()
	{
		mImageNumber = mImageCount++;
		cout<<"construct image "<<mImageNumber<<endl;		
	}
	void draw() {cout <<"drawing image "<<mImageNumber<<endl;}
	~Image()
	{
		cout<<"destruct image "<<mImageNumber<<endl;		
	}
private:
  static int mImageCount;
	int mImageNumber;
};
////////////////////
class RealImage
{
public:
	RealImage (int i)
	{
		mImageNumber = i;
		cout<<"construct image "<<mImageNumber<<endl;		
	}
	void draw() {cout <<"drawing image "<<mImageNumber<<endl;}
	~RealImage()
	{
		cout<<"destruct image "<<mImageNumber<<endl;		
	}
private:
	int mImageNumber;
};

class ImageProxy // proxy
{
	RealImage *mImage;
	static int mProxyImageCount;
	int mProxyNumber;
	
public:
	ImageProxy ()
	{
		mImage = NULL;
		mProxyNumber=mProxyImageCount++;			
	}
	void draw() 
	{
		if (mImage==NULL)
		{
			mImage = new RealImage(mProxyNumber);
		}
		mImage->draw();		
	}
	~ImageProxy()
	{
		delete mImage;		
	}
};
////////////////////////////////////////////////////////////
	// Example 2
	// Use an extra level of indirection to support distributed, controlled, or intelligent access.
	
	class Employee
	{
		
		static int mNext;
		string mName;
		int mBalance;

	public:
		static vector<string> mEmployees;
		Employee(): mBalance(500)
		{
			mName = mEmployees.at(mNext++);			
		}
		bool withdraw(int iSum)
		{
			if (iSum>mBalance)
			{
				return false;
			}
			else
			{
			  mBalance = mBalance - iSum;
				return true;
			}
		}
		string getName() {return mName;}
	};
 /////
	class ProxyEmployee
	{
		Employee* mEmployee;
	
	public:

		ProxyEmployee ()
		{
			mEmployee = new Employee();
		}

		~ProxyEmployee() {delete mEmployee;}
		
		bool withdraw(int iSum)
		{
			if ((mEmployee->getName() == "Tom") || (mEmployee->getName() == "John"))
			{
				return mEmployee->withdraw(iSum);
			}
			else
			{
				return false;
			}
		}
		
		string getName() {return mEmployee->getName();}

	};
