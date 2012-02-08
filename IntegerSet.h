#include <vector>
class IntegerSet
{
public:
	IntegerSet(void);
	~IntegerSet(void);
	std::vector<bool> v;
	static const int SIZE=101;
	void printSet() const;
};

