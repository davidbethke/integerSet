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
void IntegerSetTest::even(IntegerSet & evenSet)
{
	//set even to evens
	for(int i=0; i<evenSet.SIZE;++i)
	{
		if(!(i%2))
			evenSet.v[i]=true;
	}
	// set 0 to FALSE
	evenSet.v[0]=true;
}
void IntegerSetTest::odd(IntegerSet & oddSet)
{
	//set even to evens
	for(int i=0; i<oddSet.SIZE;++i)
	{
		if((i%2))
			oddSet.v[i]=true;
	}
	// set 0 to FALSE
	oddSet.v[0]=true;
}
void IntegerSetTest::oString(string& oS)
{
	oS="0 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 ";
}
void IntegerSetTest::eString(string& eS)
{
	eS="0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100 ";
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
	 EXPECT_EQ(empty+"\n",oss.str());
}
TEST_F(IntegerSetTest,unionTest1)
{
	std::cout.rdbuf(oss.rdbuf()); // redirect output to oss instead of cout
	IntegerSet unionSet;
	unionSet.printSet();
	EXPECT_EQ(101,unionSet.SIZE)<<"not initialized to the correct size";
	EXPECT_EQ(empty+"\n",oss.str())<<"not initialized empty";
	oss.str("");

	//set v to evens
	for(int i=0; i<v.SIZE;++i)
	{
		if(!(i%2))
			v.v[i]=true;
	}
	// set 0 to FALSE
	v.v[0]=true;
	//set v2 to odds
	for(int i=0; i<v2.SIZE;++i)
	{
		if(i%2)
			v2.v[i]=true;
	}
	// set 0 to FALSE
	v2.v[0]=false;
	unionSet=v.unionOfSets(v2);
	v.printSet();
	EXPECT_EQ(evenString + "\n",oss.str())<< "Expected All Even Vals";
	//insert at pos 0	
	v2.insertElement(0);
	oss.str(""); // clear string	
	v2.printSet();
	EXPECT_EQ( oddString + "\n",oss.str())<< "Expected All Odd Vals"; 
	//double check size of unionset
	EXPECT_EQ(101,unionSet.SIZE);
	//inspect vals of unionSet as a doubleCheck
	for(int i=0; i<unionSet.SIZE;++i)
		EXPECT_TRUE(unionSet.v[i])<< "Element:"<<i<<" Fail, Should be TRUE";
}
TEST_F(IntegerSetTest,evenTestManual)
{
	for(int i=0; i<v.SIZE;++i)
	{
		if(!(i%2))
			v.v[i]=true;
	}
	// set 0 to FALSE
	v.v[0]=true;
	for(int i=0; i<v.SIZE;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(v.v[i])<< "Element:"<<i<<" Fail, Should be TRUE";
		else
			EXPECT_FALSE(v.v[i])<< "Element:"<<i<<" Fail, Should be FALSE";

	}

}

TEST_F(IntegerSetTest,evenTest)
{
	for(int i=0; i<evenSet.SIZE;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(evenSet.v[i])<< "Element:"<<i<<" Fail, Should be TRUE";
		else
			EXPECT_FALSE(evenSet.v[i])<< "Element:"<<i<<" Fail, Should be FALSE";

	}
}
//UnionTest2
TEST_F(IntegerSetTest,unionTest2)
{
	IntegerSet unionSet;
	IntegerSet emptySet;
	unionSet=evenSet.unionOfSets(emptySet);
	for(int i=0; i<unionSet.SIZE;++i)
	{
		if(!(i%2))//even
			EXPECT_TRUE(unionSet.v[i])<<"Element:"<<i<<" Fail, Should be TRUE";
		else
			EXPECT_FALSE(unionSet.v[i])<< "Element:"<<i<<" Fail, Should be FALSE";
	}
}
TEST_F(IntegerSetTest,intersectionTest1)
{
	IntegerSet intersectionSet;
	intersectionSet=evenSet.intersectionOfSets(oddSet);
	EXPECT_TRUE(intersectionSet.v[0])<<"Element: 0 should be TRUE";
	for(int i=1; i<intersectionSet.SIZE;++i)
	{
		EXPECT_FALSE(intersectionSet.v[i])<<"Element:"<<i<<" should be FALSE";
	}
}
TEST_F(IntegerSetTest,intersectionTest2)
{
	IntegerSet intersectionSet;
	intersectionSet=evenSet.intersectionOfSets(evenSet2);
	for(int i=0;i<intersectionSet.SIZE;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(intersectionSet.v[i])<<"Element:"<<i<<" should be TRUE";
		else
			EXPECT_FALSE(intersectionSet.v[i])<<"Element:"<<i<<"should be FALSE";
	}
}
TEST_F(IntegerSetTest,intersectionTest3)
{
	IntegerSet intersectionSet;
	IntegerSet emptySet;
	intersectionSet=oddSet.intersectionOfSets(emptySet);
	for(int i=0; i<intersectionSet.SIZE;++i)
	{
		EXPECT_FALSE(intersectionSet.v[i])<<"Element:"<<i<<" should be FALSE";
	}
}
TEST_F(IntegerSetTest,deleteSingleElement)
{
	IntegerSet mySet;
	int i=rand()%100;
	mySet.insertElement(i);
	EXPECT_TRUE(mySet.v[i])<<"Element:"<<i<<" should be TRUE";
	mySet.deleteElement(i);
	EXPECT_FALSE(mySet.v[i])<<"Element:"<<i<<" should be FALSE";
}
TEST_F(IntegerSetTest,deleteMultElement)
{
	//verify evenSET
	for(int i=0; i<evenSet.SIZE;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(evenSet.v[i])<<"Element:"<<i<<" should be TRUE";
		else
			EXPECT_FALSE(evenSet.v[i])<<"Element:"<<i<<" should be FALSE";
	}
	for(int i=0; i<evenSet.SIZE;++i)
		evenSet.deleteElement(i);
	for(int i=0;i<evenSet.SIZE;++i)
		EXPECT_FALSE(evenSet.v[i])<<"Element:"<<i<<" should be FALSE (deleted)";
}
	
TEST_F(IntegerSetTest,opOS)
{
	std::cout.rdbuf(oss.rdbuf());
	std::cout << evenSet;
	EXPECT_EQ(evenString+"\n",oss.str())<<"Expect even vals";
}
TEST_F(IntegerSetTest,opPipe)
{
	IntegerSet unionSet;
	unionSet=evenSet | oddSet;
	for(int i=0; i< unionSet.SIZE;++i)
		EXPECT_TRUE(unionSet.v[i])<<"Element:"<<i<<" should be TRUE";

}
TEST_F(IntegerSetTest,opAmpersand)
{
	IntegerSet unionSet;
	IntegerSet emptySet;
	unionSet=evenSet & emptySet;
	for(int i=0; i< unionSet.SIZE;++i)
		EXPECT_FALSE(unionSet.v[i])<<"Element:"<<i<<" should be FALSE";

}
TEST_F(IntegerSetTest,opEqual)
{
	EXPECT_TRUE(evenSet==evenSet)<<"Expect TRUE, evenSet";
	EXPECT_TRUE(evenSet==evenSet2)<<"Expect TRUE, evenSet";
	EXPECT_FALSE(evenSet==oddSet)<<"Expect FALSE, evenSet/oddSet";
}
TEST_F(IntegerSetTest,opIns)
{
	EXPECT_FALSE(evenSet.v[99])<<"Expect FALSE, insertElement op += at 99, precondition";
	evenSet+=99;
	EXPECT_TRUE(evenSet.v[99])<<"Expect TRUE, insertElement op += at 99";
}
TEST_F(IntegerSetTest,opDel)
{
	EXPECT_TRUE(evenSet.v[98])<<"Expect TRUE, insertElement op -= at 98, precondition";
	evenSet-=98;
	EXPECT_FALSE(evenSet.v[98])<<"Expect FALSE, insertElement op -= at 98";
}
TEST_F(IntegerSetTest,varArr)
{
	//simple test
	int arr[]={5,5,4,3,2,2};
	IntegerSet varSet(arr,6);
	EXPECT_TRUE(varSet.v[5])<<"Element 5 should be TRUE";
	EXPECT_FALSE(varSet.v[0])<<"Element 0 should be FALSE";

}

TEST_F(IntegerSetTest,varArr2)
{
	
	int arr[]={5,99,4,3,2,2};
	IntegerSet varSet(arr,6);
	EXPECT_TRUE(varSet.v[5])<<"Element 5 should be TRUE";
	EXPECT_FALSE(varSet.v[0])<<"Element 0 should be FALSE";
	EXPECT_EQ(100,varSet.SIZE)<< "Size should be 100";
	//varSet.insertElement(99);
	EXPECT_TRUE(varSet.v[99])<<"Element 99 should be TRUE";
	EXPECT_EQ(100,varSet.v.size());

}





