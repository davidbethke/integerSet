#include "StdAfx.h"
#include "IntegerSet.h"
//#include <iostream>
//#include <ostream>
using namespace std;

IntegerSet::IntegerSet(int s):size(s),v(size,false)
{
}


IntegerSet::IntegerSet(int a[],int s):arr(a),size(s),v(size,false)
{
	// assume max int val> arr size, so need to resize vect to accomodate largest val
	int arrS=size;
	size_t maxV= findArrayMaxVal(arr,size);
	v.resize(maxV+1,false);   // resize by 1 more, index starts at 0
	size=maxV+1;
	for(int i=0; i<arrS;++i)   //copy
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

}
void IntegerSet::insertElement(int i)
{
	if(i>=0 && i<size) // bounds check, fail silently
	{
		if(!v[i])    // insert if false
			v[i]=true;
	}

}
void IntegerSet::deleteElement(int i)
{
	if(i>=0 && i<size) // bounds check, fail silently
	{
		if(v[i]) // if its true, set it to false, otherwise nothing
			v[i]=false;
	}

}
IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const
{
	int min, max;
	//DONE Support union of unequal size Sets?<<assumption>> small set is a subset of larger set, by our definition
	// assume unequal size sets,possibly
	min=minSize(size,other.size);
	max=maxSize(size,other.size);
	IntegerSet unionSet(max);   //set to return
	const IntegerSet bigSet=getBiggestSet(*this,other); //id the largest set check its unique half
	for(int i=0; i<min;++i)
	{
		if(v[i] || other.v[i])
			unionSet.insertElement(i);
	}
	for(int i=min;i<max;++i)
	{
		if(bigSet.v[i])
			unionSet.insertElement(i);
	}
	/* assume equal size
	for(int i=0; i<size;++i)
	{
		if(v[i] || other.v[i])
			unionSet.v[i]=true;
	}
	*/
	return unionSet;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const
{
	int min =minSize(size,other.size);
	IntegerSet intersectSet(min);  //Done Should support unequal size sets?max size of an intersection is the min(size,other.size) <<assumption>>
	for(int i=0; i<min;++i)       // DONE iterate over  min size only fill the new set up to its size, min
	{
		if(v[i] && other.v[i])
			intersectSet.v[i]=true;
	}
	return intersectSet;

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
	
	if(size != other.size)
		return false;
	for(int i=0; i<size;++i)
	{
		if(v[i] != other.v[i])
			return false;
	}
	return true;

}
bool IntegerSet::isEqualTo(const IntegerSet & other) const
{
	return (*this == other);
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
size_t IntegerSet::findArrayMaxVal(int arr[],int s)  //used to size the set when passed an array
{
	int max=arr[0];
	for(int i=1;i<s;++i)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
int IntegerSet::minSize(int a, int b) const
{
	if(a<b)
		return a;
	else
		return b;
}
int IntegerSet::maxSize(int a, int b) const
{
	if(a>b)
		return a;
	else
		return b;
}
const IntegerSet& IntegerSet::getBiggestSet(const IntegerSet& a, const IntegerSet&b) const
{
	if(a.size> b.size) //identify the largest sized set, and return a const ref so that we can union unequal sized sets
		return a;
	else
		return b;
}
/* Experiment Only
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
*/
std::ostream& operator<<(std::ostream& os, const IntegerSet& iS)
{
	
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

	return os;
}


