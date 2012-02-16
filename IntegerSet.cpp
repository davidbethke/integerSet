#include "StdAfx.h"
#include "IntegerSet.h"
//#include <iostream>
//#include <ostream>
using namespace std;

/*
IntegerSet::IntegerSet():v(size,false)
{
}
*/

IntegerSet::IntegerSet(int s):size(s),v(size,false)
{
}


IntegerSet::IntegerSet(int a[],int s):arr(a),size(s),v(size,false)
{
	// assume max int val> arr size, so need to resize vect to accomodate largest val
	int arrS=size;
	size_t maxV= max(arr,size);
	v.resize(maxV+1,false);
	size=maxV+1;
	for(int i=0; i<arrS;++i)
		insertElement(arr[i]);
	
}
IntegerSet::IntegerSet(const IntegerSet &other):size(other.size),v(other.size,false)
{
	for(int i=0; i<size;++i)
		v[i]=other.v[i];

}
IntegerSet::~IntegerSet(void)
{
	//delete[] arr; // No array to delete, it's passed in, assigned
}
void IntegerSet::printSet() const
{
	bool empty=true;
	for (int i=0; i<size;++i)
	{
		if (v[i])
		{
			cout<<i<<" ";
			empty=false;
		}
	}
	if(empty)
		cout<< "---";
//DONE doubled up endl;
}
void IntegerSet::insertElement(int i)
{
	if(i>=0 && i<size) // bounds check
	{
		if(!v[i])    // insert if false
			v[i]=true;
	}

}
void IntegerSet::deleteElement(int i)
{
	if(i>=0 && i<size)
	{
		if(v[i]) // if its true, set it to false, otherwise nothing
			v[i]=false;
	}

}
IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const
{
	IntegerSet unionSet;
	for(int i=0; i<size;++i)
	{
		if(v[i] || other.v[i])
			unionSet.v[i]=true;
	}
	return unionSet;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const
{
	IntegerSet unionSet;
	for(int i=0; i<size;++i)
	{
		if(v[i] && other.v[i])
			unionSet.v[i]=true;
	}
	return unionSet;

}
IntegerSet IntegerSet::operator|(const IntegerSet &other) const
{
	return unionOfSets(other);
}
IntegerSet IntegerSet::operator&(const IntegerSet &other) const
{
	return intersectionOfSets(other);
}
bool IntegerSet::operator==(const IntegerSet & other)const
{
	//TODO fix multiple return badness
	//TODO check for self ==? is it worth it?
	if(size != other.size)
		return false;
	for(int i=0; i<size;++i)
	{
		if(v[i] != other.v[i])
			return false;
	}
	return true;

}
void IntegerSet::operator+=(int i)
{
	insertElement(i);
}
void IntegerSet::operator-=(int i)
{
	deleteElement(i);
}

IntegerSet& IntegerSet::operator=(const IntegerSet& other)
{
	if(this!=&other)
	{
		//resize, re init
		size=other.size;
		v.resize(size,false);
		for(int i=0; i<size;++i)
			v[i]=other.v[i];
	}
	return *this;
}
size_t IntegerSet::max(int arr[],int s)
{
	int max=arr[0];
	for(int i=1;i<s;++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
bool IntegerSet::operator[](int i)
{
	if(i<0 || i>=size)   // out of bounds
	{
		cerr << "Access to IntegerSet Out of Bounds"<<endl;
		exit(1);
	}
	return v[i];// Does Not return a reference, by design http://www.gotw.ca/publications/N1185.pdf
}
bool IntegerSet::operator[](int i) const
{
	if(i<0 || i>=size)   // out of bounds
	{
		cerr << "Access to IntegerSet Out of Bounds"<<endl;
		exit(1);
	}
	return v[i];
}
std::ostream& operator<<(std::ostream& os, const IntegerSet& iS)
{
	//printSet();// might not be right, only cout, could be some sstream or something else redirected
	bool empty=true;
	for (int i=0; i<iS.size;++i)
	{
		if(iS.v[i])
		{
			os<< i<< " ";
			empty=false;
		}
	}
	if(empty)
		os<< "---";
	//DONE remove this endl, it doubles up the typical cmd cout << integerset<<endl;
	return os;
}


