#include <vector>
#include <iostream>
#include <ostream>
class ostream;
class IntegerSet
{
public:
	IntegerSet(void);
	~IntegerSet(void);
	std::vector<bool> v;
	static const int SIZE=101;
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
	
};
std::ostream& operator<<(std::ostream&,const IntegerSet&);
