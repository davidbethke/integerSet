#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "IntegerSet.h"
#include <iostream>
#include <sstream>
class IntegerSetTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	v=IntegerSet();
	v2=IntegerSet();
	//std::ostringstream oss;
    //std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	 p_cout_streambuf = std::cout.rdbuf();
   
	}
	virtual void TearDown()
	{
		std::cout.rdbuf(p_cout_streambuf); // restore
	
	}
	IntegerSet v, v2;
	std::ostringstream oss;
    std::streambuf* p_cout_streambuf;
public:
	IntegerSetTest(void);
	~IntegerSetTest(void);
};

