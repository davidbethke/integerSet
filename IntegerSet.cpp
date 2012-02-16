#include "StdAfx.h"
#include "IntegerSet.h"
//#include <iostream>
//#include <ostream>
using namespace std;

/*
IntegerSet::IntegerSet():v(SIZE,false)
{
}
*/

IntegerSet::IntegerSet(int s):SIZE(s),v(SIZE,false)
{
}


IntegerSet::IntegerSet(int a[],int s):arr(a),SIZE(s),v(SIZE,false)
{
	// assume max int val> arr size, so need to resize vect to accomodate largest val
	int arrS=SIZE;
	size_t maxV= max(arr,SIZE);
	v.resize(maxV+1,false);
	SIZE=maxV+1;
	for(int i=0; i<arrS;++i)
		insertElement(arr[i]);
	
}
IntegerSet::IntegerSet(const IntegerSet &other):SIZE(other.SIZE),v(other.SIZE,false)
{
	for(int i=0; i<SIZE;++i)
		v[i]=other.v[i];

}
IntegerSet::~IntegerSet(void)
{
	//delete[] arr; // No array to delete, it's passed in, assigned
}
void IntegerSet::printSet() const
{
	bool empty=true;
	for (int i=0; i<SIZE;++i)
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
	if(i>=0 && i<SIZE) // bounds check
	{
		if(!v[i])    // insert if false
			v[i]=true;
	}

}
void IntegerSet::deleteElement(int i)
{
	if(i>=0 && i<SIZE)
	{
		if(v[i]) // if its true, set it to false, otherwise nothing
			v[i]=false;
	}

}
IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const
{
	IntegerSet unionSet;
	for(int i=0; i<SIZE;++i)
	{
		if(v[i] || other.v[i])
			unionSet.v[i]=true;
	}
	return unionSet;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const
{
	IntegerSet unionSet;
	for(int i=0; i<SIZE;++i)
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
	if(SIZE != other.SIZE)
		return false;
	for(int i=0; i<SIZE;++i)
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
		SIZE=other.SIZE;
		v.resize(SIZE,false);
		for(int i=0; i<SIZE;++i)
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

std::ostream& operator<<(std::ostream& os, const IntegerSet& iS)
{
	//printSet();// might not be right, only cout, could be some sstream or something else redirected
	bool empty=true;
	for (int i=0; i<iS.SIZE;++i)
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


