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
