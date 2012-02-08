#include "StdAfx.h"
#include "IntegerSet.h"
#include <iostream>

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
IntegerSet IntegerSet::unionOfSets(const IntegerSet &other)
{
	IntegerSet unionSet;
	for(int i=0; i<SIZE;++i)
	{
		if(this->v[i] || other.v[i])
			unionSet.v[i]=true;
		return unionSet;
	}

}