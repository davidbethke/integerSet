#include <vector>
#include <iostream>
#include <ostream>
class IntegerSet
{
friend	std::ostream& operator<<(std::ostream&, const IntegerSet&);
public:
	IntegerSet(int s=101);										// default constructor
	IntegerSet(int[],int);										// pass in an array and construct an IntegerSet
	IntegerSet(const IntegerSet&);								// copy constructor
	IntegerSet& operator=(const IntegerSet&);
	~IntegerSet(void);
	int size;
	void printSet() const;
	void insertElement(int);
	void deleteElement(int);
	IntegerSet unionOfSets(const IntegerSet&)const;				// set methods
	IntegerSet intersectionOfSets(const IntegerSet&)const ;
	IntegerSet operator|(const IntegerSet&) const;				// operator overloads
	IntegerSet operator&(const IntegerSet&) const;
	bool operator==(const IntegerSet&)const;
	bool isEqualTo(const IntegerSet&)const;
	void operator+=(int);
	void operator-=(int);
	//bool operator[](int);										//required for unit tests broken for bools, hack just return by val (for TESTING ONLY)
	//bool operator[](int) const;								//required for unit tests experiment only
private:
	int *arr;
	std::vector<bool> v;
	size_t findArrayMaxVal(int arr[],int);
	int minSize(int,int) const;
	int maxSize(int,int) const;
	const IntegerSet& getBiggestSet(const IntegerSet&,const IntegerSet&) const;
};
std::ostream& operator<<(std::ostream&,const IntegerSet&);
