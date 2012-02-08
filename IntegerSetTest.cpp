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
	int i=rand()%100;
	v.v[i]=true;
	for (int i=0; i<101; ++i)
		EXPECT_FALSE(v.v[i])<< "Element:"<<i<<" Fail";
}
TEST_F(IntegerSetTest,testMultVal)
{
	v.v[0]=v.v[1]=v.v[20]=v.v[44]=v.v[56]=v.v[100]=true;
	for (int i=0; i<101; ++i)
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
	
	EXPECT_EQ("0 1 20 44 56 101 \n",oss.str());

	
}