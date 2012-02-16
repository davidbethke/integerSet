#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "IntegerSet.h"
#include <iostream>
#include <sstream>
#include <string>
class IntegerSetTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	//v=IntegerSet();
	//v2=IntegerSet();
	//unionSet=IntegerSet();
	//evenSet=IntegerSet();
	//evenSet2=IntegerSet();
	//oddSet=IntegerSet();
	v=IntegerSet();
	v2=IntegerSet();
	unionSet=IntegerSet();
	evenSet=IntegerSet();
	evenSet2=IntegerSet();
	oddSet=IntegerSet();
	p_cout_streambuf = std::cout.rdbuf();
   //
	even(evenSet);
	even(evenSet2);
	odd(oddSet);
	eString(evenString);
	oString(oddString);
	eVString(evenVarString);
	empty="---";
	}
	virtual void TearDown()
	{
		std::cout.rdbuf(p_cout_streambuf); // restore
	
	}
	void even(IntegerSet&);
	void odd(IntegerSet&);
	void eString(std::string &);
	void oString(std::string &);
	void eVString(std::string &);
	IntegerSet v, v2,unionSet,evenSet, oddSet,evenSet2;
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf;
	std::string evenString, oddString,empty,evenVarString;
public:
	IntegerSetTest(void);
	~IntegerSetTest(void);
};

