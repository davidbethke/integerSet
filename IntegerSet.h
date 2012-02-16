#include <vector>
#include <iostream>
#include <ostream>
class ostream;
class IntegerSet
{
public:
	IntegerSet(int s=101); // default constructor
	IntegerSet(int[],int); // pass in an array and construct an IntegerSet
	IntegerSet(const IntegerSet&); // copy constructor
	IntegerSet& operator=(const IntegerSet&);
	~IntegerSet(void);
	int SIZE;
	std::vector<bool> v;
	void printSet() const;
	void insertElement(int);
	void deleteElement(int);
// set operations
	IntegerSet unionOfSets(const IntegerSet&)const;
	IntegerSet intersectionOfSets(const IntegerSet&)const ;
// operator overloads
	IntegerSet operator|(const IntegerSet&) const;
	IntegerSet operator&(const IntegerSet&) const;
	bool operator==(const IntegerSet&)const;
	void operator+=(int);
	void operator-=(int);
	size_t max(int arr[],int);
private:
	int *arr;
};
std::ostream& operator<<(std::ostream&,const IntegerSet&);
