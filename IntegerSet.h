#include <vector>
#include <iostream>
#include <ostream>
class ostream;
class IntegerSet
{
public:
	//IntegerSet();
	IntegerSet(int s=101);
	IntegerSet(int[],int);
	~IntegerSet(void);
	 int SIZE;
	
	int *arr;
	std::vector<bool> v;
	void printSet() const;
	void insertElement(int);
	void deleteElement(int);
	IntegerSet unionOfSets(const IntegerSet&)const;
	IntegerSet intersectionOfSets(const IntegerSet&)const ;
	IntegerSet operator|(const IntegerSet&) const;
	IntegerSet operator&(const IntegerSet&) const;
	bool operator==(const IntegerSet&)const;
	void operator+=(int);
	void operator-=(int);
	IntegerSet& operator=(const IntegerSet&);
	size_t max(int arr[],int);
};
std::ostream& operator<<(std::ostream&,const IntegerSet&);
