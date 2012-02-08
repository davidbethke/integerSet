#include "StdAfx.h"
#include "IntegerSet.h"
//#include <iostream>
//#include <ostream>
using namespace std;


IntegerSet::IntegerSet(void):v(SIZE,false)
{
}


IntegerSet::~IntegerSet(void)
{
}
void IntegerSet::printSet() const
{
	for (int i=0; i<SIZE;++i)
	{
		if (v[i])
			cout<<i<<" ";
	}
	cout <<endl;
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
IntegerSet IntegerSet::unionOfSets(const IntegerSet &other)
{
	IntegerSet unionSet;
	for(int i=0; i<SIZE;++i)
	{
		if(v[i] || other.v[i])
			unionSet.v[i]=true;
	}
	return unionSet;

}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other)
{
	IntegerSet unionSet;
	for(int i=0; i<SIZE;++i)
	{
		if(v[i] && other.v[i])
			unionSet.v[i]=true;
	}
	return unionSet;

}
std::ostream& operator<<(std::ostream& os, const IntegerSet& iS)
{
	//printSet();// might not be right, only cout, could be some sstream or something else redirected
	for (int i=0; i<iS.SIZE;++i)
		if(iS.v[i])
			os<< i<< " ";
	os<<endl;
	return os;
}

