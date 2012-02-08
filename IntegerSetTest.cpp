#include "StdAfx.h"
#include "IntegerSetTest.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

IntegerSetTest::IntegerSetTest(void)
{
}


IntegerSetTest::~IntegerSetTest(void)
{
}

TEST_F(IntegerSetTest, testEmpty)
{
	for (int i=0; i<101; ++i)
		EXPECT_FALSE(v.v[i])<< "Element:"<<i<<" Fail";

}
TEST_F(IntegerSetTest,testOneVal)
{
	int iR=rand()%100;
	v.v[iR]=true;
	for (int i=0; i<101; ++i)
		if(i==iR)
			EXPECT_TRUE(v.v[i])<<"Element:"<<i<<" Fail";
		else
			EXPECT_FALSE(v.v[i])<< "Element:"<<i<<" Fail";
}
TEST_F(IntegerSetTest,testMultVal)
{
	v.v[0]=v.v[1]=v.v[20]=v.v[44]=v.v[56]=v.v[100]=true;
	for (int i=0; i<101; ++i)
		if(i==0 || i==1 || i==20 || i==44 || i==56 || i==100)
			EXPECT_TRUE(v.v[i])<< "Element:"<<i<<" Fail";
		else
			EXPECT_FALSE(v.v[i])<< "Element:"<<i<<" Fail";
}
TEST_F(IntegerSetTest,testPrintOneVal)
{
	std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
	v.v[0]=true;
	v.printSet();
	std::cout.rdbuf(p_cout_streambuf); // restore
	
	EXPECT_EQ("0 \n",oss.str());

	
}
TEST_F(IntegerSetTest,testPrintMultVal)
{
	std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
	v.v[0]=v.v[1]=v.v[20]=v.v[44]=v.v[56]=v.v[100]=true;
	v.printSet();
	std::cout.rdbuf(p_cout_streambuf); // restore
	
	EXPECT_EQ("0 1 20 44 56 100 \n",oss.str());

	
}
TEST_F(IntegerSetTest,insertOneElement)
{
	v.insertElement(0);
	EXPECT_TRUE(v.v[0])<< "Element 0 Not set";
}

TEST_F(IntegerSetTest,insertElementAgain)
{
	v.insertElement(0);
	EXPECT_TRUE(v.v[0])<< "Element 0 Not set";
	v.insertElement(0);
	EXPECT_TRUE(v.v[0])<< "Not inserted a Second Time";
}
TEST_F(IntegerSetTest,insertElement100)
{
	v.insertElement(100);
	EXPECT_TRUE(v.v[100])<< "Not inserted at element 100";
}
TEST_F(IntegerSetTest,insertOutOfBounds)
{
	v.insertElement(-1);
	v.insertElement(101);
	 std::cout.rdbuf(oss.rdbuf());
	 v.printSet();
	 EXPECT_EQ("\n",oss.str());
}
TEST_F(IntegerSetTest,unionTest1)
{
	IntegerSet unionSet;
	//set v to evens
	for(int i=0; i<v.SIZE;++i)
	{
		if(!(i%2))
			v.v[i]=true;
	}
	// set 0 to false
	v.v[0]=false;
	//set v2 to odds
	for(int i=0; i<v2.SIZE;++i)
	{
		if(i%2)
			v.v[i]=true;
	}
	// set 0 to false
	v2.v[0]=false;
	unionSet=v.unionOfSets(v2);
	std::cout.rdbuf(oss.rdbuf());
	unionSet.printSet();
	EXPECT_EQ("\n",oss.str())<< "Expected No Union Vals";
	//inspect vals of unionSet as a doubleCheck
	for(int i=0; i<unionSet.SIZE;++i)
		EXPECT_FALSE(unionSet.v[i])<< "Element:"<<i<<" Fail, Should be false";

		
}
