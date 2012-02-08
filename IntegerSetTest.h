#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "IntegerSet.h"
class IntegerSetTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	v=IntegerSet();
	}
	virtual void TearDown()
	{
	}
	IntegerSet v;
public:
	IntegerSetTest(void);
	~IntegerSetTest(void);
};

