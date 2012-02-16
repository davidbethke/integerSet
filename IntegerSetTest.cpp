#include "StdAfx.h"
#include "IntegerSetTest.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
//todo multi assignment a=b=c
//todo const tests

IntegerSetTest::IntegerSetTest(void)
{
}


IntegerSetTest::~IntegerSetTest(void)
{
}
void IntegerSetTest::even(IntegerSet & evenSet)
{
	//set even to evens
	for(int i=0; i<evenSet.size;++i)
	{
		if(!(i%2))
			//evenSet[i]=true;
			evenSet.insertElement(i);
	}
	// set 0 to false
	//evenSet[0]=true;
	evenSet.insertElement(0);
}
void IntegerSetTest::odd(IntegerSet & oddSet)
{
	//set even to evens
	for(int i=0; i<oddSet.size;++i)
	{
		if((i%2))
			//oddSet[i]=true;
			oddSet.insertElement(i);
	}
	// set 0 to false
	//oddSet[0]=true;
	oddSet.insertElement(0);
}
void IntegerSetTest::oString(string& os)
{
	os="0 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 ";
}
void IntegerSetTest::eString(string& es)
{
	es="0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100 ";
}


TEST_F(IntegerSetTest, testempty)
{
	for (int i=0; i<101; ++i)
		EXPECT_FALSE(v[i])<< "element:"<<i<<" fail";

}
TEST_F(IntegerSetTest,testoneval)
{
	int ir=rand()%100;
	v.insertElement(ir);
	for (int i=0; i<101; ++i)
		if(i==ir)
			EXPECT_TRUE(v[i])<<"element:"<<i<<" fail";
		else
			EXPECT_FALSE(v[i])<< "element:"<<i<<" fail";
}
TEST_F(IntegerSetTest,testmultval)
{
//	v[0]=v[1]=v[20]=v[44]=v[56]=v[100]=true;
	v.insertElement(0);
	v.insertElement(1);
	v.insertElement(20);
	v.insertElement(44);
	v.insertElement(56);
	v.insertElement(100);
	for (int i=0; i<101; ++i)
		if(i==0 || i==1 || i==20 || i==44 || i==56 || i==100)
			EXPECT_TRUE(v[i])<< "element:"<<i<<" fail";
		else
			EXPECT_FALSE(v[i])<< "element:"<<i<<" fail";
}
TEST_F(IntegerSetTest,testprintoneval)
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());
	//v[0]=true;
	v.insertElement(0);
	v.printSet();
	std::cout.rdbuf(p_cout_streambuf); // restore
	
	EXPECT_EQ("0 ",oss.str());

	
}
TEST_F(IntegerSetTest,testprintmultval)
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());
	//v[0]=v[1]=v[20]=v[44]=v[56]=v[100]=true;
	v.insertElement(0);
	v.insertElement(1);
	v.insertElement(20);
	v.insertElement(44);
	v.insertElement(56);
	v.insertElement(100);
	v.printSet();
	std::cout.rdbuf(p_cout_streambuf); // restore
	
	EXPECT_EQ("0 1 20 44 56 100 ",oss.str());

	
}
TEST_F(IntegerSetTest,insertoneelement)
{
	v.insertElement(0);
	EXPECT_TRUE(v[0])<< "element 0 not set";
}

TEST_F(IntegerSetTest,insertElementagain)
{
	v.insertElement(0);
	EXPECT_TRUE(v[0])<< "element 0 not set";
	v.insertElement(0);
	EXPECT_TRUE(v[0])<< "not inserted a second time";
}
TEST_F(IntegerSetTest,insertElement100)
{
	v.insertElement(100);
	EXPECT_TRUE(v[100])<< "not inserted at element 100";
}
TEST_F(IntegerSetTest,insertoutofbounds)
{
	v.insertElement(-1);
	v.insertElement(101);
	 std::cout.rdbuf(oss.rdbuf());
	 v.printSet();
	 EXPECT_EQ(empty,oss.str());
}
TEST_F(IntegerSetTest,uniontest1)
{
	std::cout.rdbuf(oss.rdbuf()); // redirect output to oss instead of cout
	IntegerSet unionset;
	unionset.printSet();
	EXPECT_EQ(101,unionset.size)<<"not initialized to the correct size";
	EXPECT_EQ(empty,oss.str())<<"not initialized empty";
	oss.str("");

	//set v to evens
	for(int i=0; i<v.size;++i)
	{
		if(!(i%2))
			v.insertElement(i);
	}
	// set 0 to false
	v.insertElement(0);
	//set v2 to odds
	for(int i=0; i<v2.size;++i)
	{
		if(i%2)
			v2.insertElement(i);
	}
	// set 0 to false
	v2.deleteElement(0);
	unionset=v.unionOfSets(v2);
	v.printSet();
	EXPECT_EQ(evenString,oss.str())<< "expected all even vals";
	//insert at pos 0	
	v2.insertElement(0);
	oss.str(""); // clear string	
	v2.printSet();
	EXPECT_EQ( oddString,oss.str())<< "expected all odd vals"; 
	//double check size of unionset
	EXPECT_EQ(101,unionset.size);
	//inspect vals of unionset as a doublecheck
	for(int i=0; i<unionset.size;++i)
		EXPECT_TRUE(unionset[i])<< "element:"<<i<<" fail, should be true";
}
TEST_F(IntegerSetTest,eventestmanual)
{
	for(int i=0; i<v.size;++i)
	{
		if(!(i%2))
			v.insertElement(i);
	}
	// set 0 to false
	v.insertElement(0);
	for(int i=0; i<v.size;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(v[i])<< "element:"<<i<<" fail, should be true";
		else
			EXPECT_FALSE(v[i])<< "element:"<<i<<" fail, should be false";

	}

}

TEST_F(IntegerSetTest,eventest)
{
	for(int i=0; i<evenSet.size;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(evenSet[i])<< "element:"<<i<<" fail, should be true";
		else
			EXPECT_FALSE(evenSet[i])<< "element:"<<i<<" fail, should be false";

	}
}
//uniontest2
TEST_F(IntegerSetTest,uniontest2)
{
	IntegerSet unionset;
	IntegerSet emptyset;
	unionset=evenSet.unionOfSets(emptyset);
	for(int i=0; i<unionset.size;++i)
	{
		if(!(i%2))//even
			EXPECT_TRUE(unionset[i])<<"element:"<<i<<" fail, should be true";
		else
			EXPECT_FALSE(unionset[i])<< "element:"<<i<<" fail, should be false";
	}
}
TEST_F(IntegerSetTest,intersectiontest1)
{
	IntegerSet intersectionset;
	intersectionset=evenSet.intersectionOfSets(oddSet);
	EXPECT_TRUE(intersectionset[0])<<"element: 0 should be true";
	for(int i=1; i<intersectionset.size;++i)
	{
		EXPECT_FALSE(intersectionset[i])<<"element:"<<i<<" should be false";
	}
}
TEST_F(IntegerSetTest,intersectiontest2)
{
	IntegerSet intersectionset;
	intersectionset=evenSet.intersectionOfSets(evenSet2);
	for(int i=0;i<intersectionset.size;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(intersectionset[i])<<"element:"<<i<<" should be true";
		else
			EXPECT_FALSE(intersectionset[i])<<"element:"<<i<<"should be false";
	}
}
TEST_F(IntegerSetTest,intersectiontest3)
{
	IntegerSet intersectionset;
	IntegerSet emptyset;
	intersectionset=oddSet.intersectionOfSets(emptyset);
	for(int i=0; i<intersectionset.size;++i)
	{
		EXPECT_FALSE(intersectionset[i])<<"element:"<<i<<" should be false";
	}
}
TEST_F(IntegerSetTest,deletesingleelement)
{
	IntegerSet myset;
	int i=rand()%100;
	myset.insertElement(i);
	EXPECT_TRUE(myset[i])<<"element:"<<i<<" should be true";
	myset.deleteElement(i);
	EXPECT_FALSE(myset[i])<<"element:"<<i<<" should be false";
}
TEST_F(IntegerSetTest,deletemultelement)
{
	//verify evenSet
	for(int i=0; i<evenSet.size;++i)
	{
		if(!(i%2))
			EXPECT_TRUE(evenSet[i])<<"element:"<<i<<" should be true";
		else
			EXPECT_FALSE(evenSet[i])<<"element:"<<i<<" should be false";
	}
	for(int i=0; i<evenSet.size;++i)
		evenSet.deleteElement(i);
	for(int i=0;i<evenSet.size;++i)
		EXPECT_FALSE(evenSet[i])<<"element:"<<i<<" should be false (deleted)";
}
	
TEST_F(IntegerSetTest,opos)
{
	std::cout.rdbuf(oss.rdbuf());
	std::cout << evenSet;
	EXPECT_EQ(evenString,oss.str())<<"expect even vals";
}
TEST_F(IntegerSetTest,oppipe)
{
	IntegerSet unionset;
	unionset=evenSet | oddSet;
	for(int i=0; i< unionset.size;++i)
		EXPECT_TRUE(unionset[i])<<"element:"<<i<<" should be true";

}
TEST_F(IntegerSetTest,opampersand)
{
	IntegerSet unionset;
	IntegerSet emptyset;
	unionset=evenSet & emptyset;
	for(int i=0; i< unionset.size;++i)
		EXPECT_FALSE(unionset[i])<<"element:"<<i<<" should be false";

}
TEST_F(IntegerSetTest,opequal)
{
	EXPECT_TRUE(evenSet==evenSet)<<"expect true, evenSet";
	EXPECT_TRUE(evenSet==evenSet2)<<"expect true, evenSet";
	EXPECT_FALSE(evenSet==oddSet)<<"expect false, evenSet/oddSet";
}
TEST_F(IntegerSetTest,opins)
{
	EXPECT_FALSE(evenSet[99])<<"expect false, insertElement op += at 99, precondition";
	evenSet+=99;
	EXPECT_TRUE(evenSet[99])<<"expect true, insertElement op += at 99";
}
TEST_F(IntegerSetTest,opdel)
{
	EXPECT_TRUE(evenSet[98])<<"expect true, insertElement op -= at 98, precondition";
	evenSet-=98;
	EXPECT_FALSE(evenSet[98])<<"expect false, insertElement op -= at 98";
}
TEST_F(IntegerSetTest,vararr)
{
	//simple test
	int arr[]={5,5,4,3,2,2};
	IntegerSet varset(arr,6);
	EXPECT_TRUE(varset[5])<<"element 5 should be true";
	EXPECT_FALSE(varset[0])<<"element 0 should be false";

}

TEST_F(IntegerSetTest,vararr2)
{
	
	int arr[]={5,99,4,3,2,2};
	IntegerSet varset(arr,6);
	EXPECT_TRUE(varset[5])<<"element 5 should be true";
	EXPECT_FALSE(varset[0])<<"element 0 should be false";
	EXPECT_EQ(100,varset.size)<< "size should be 100";
	//varset.insertElement(99);
	EXPECT_TRUE(varset[99])<<"element 99 should be true";
	EXPECT_EQ(100,varset.size);

}
TEST_F(IntegerSetTest,copyconstructor1)
{
	std::cout.rdbuf(oss.rdbuf());
	IntegerSet emptyset;
	IntegerSet mycopy(evenSet);
	IntegerSet myocopy(oddSet);
	IntegerSet myecopy(emptyset);
	mycopy.printSet();
	EXPECT_EQ(evenString,oss.str())<<"copy constructor failed";
	oss.str("");
	myocopy.printSet();
	EXPECT_EQ(oddString,oss.str())<<"copy constructor failed";
	oss.str("");
	myecopy.printSet();
	EXPECT_EQ(empty,oss.str())<<"copy constructor failed";

}
//done test assignment operator with two unequal size sets
TEST_F(IntegerSetTest,assigntest)
{
	std::cout.rdbuf(oss.rdbuf());
	IntegerSet emptyset;
	//assign even to odd
	//verify first
	evenSet.printSet();
	EXPECT_EQ(evenString,oss.str())<<"should be all even";
	oss.str("");
	oddSet.printSet();
	EXPECT_EQ(oddString,oss.str())<<"should be all odd";
	oss.str("");
	//assign
	oddSet=evenSet;
	oddSet.printSet();
	EXPECT_EQ(evenString,oss.str())<<"should be all even";
	oss.str("");
	evenSet=emptyset;
	evenSet.printSet();
	EXPECT_EQ(empty,oss.str())<<"should be all empty";
	oss.str("");


}

TEST_F(IntegerSetTest,assigntest2)
{
	std::cout.rdbuf(oss.rdbuf());
	//create an unequal size array ,assign, check
	IntegerSet emptyset;
	int arr[]={5,99,4,3,2,2};
	IntegerSet varset(arr,6);
	varset.printSet();
	EXPECT_EQ("2 3 4 5 99 ",oss.str())<<"verify of vararr constructor failed";
	oss.str("");
	emptyset.printSet();
	EXPECT_EQ(empty,oss.str())<<"verify of emptyset constructor failed";
	oss.str("");
	// assign to emptyset
	emptyset=varset;
	emptyset.printSet();
	EXPECT_EQ("2 3 4 5 99 ",oss.str())<<"verify assignementof emptyset to varset failed";
	oss.str("");
	// check size
	EXPECT_EQ(100,emptyset.size)<<"emptyset not resized correctly";// 100 is one more than the 99 of vararr

}
TEST_F(IntegerSetTest,testequals)
{
	//create an unequal size array ,assign, check
	IntegerSet emptyset, emptyset2;
	int arr[]={5,99,4,3,2,2};
	int arr2[]={5,200,4,3,2,2};
	IntegerSet varset(arr,6), varset2(arr2,6);
	EXPECT_TRUE(emptyset==emptyset2)<<"empty sets not equal";
	EXPECT_TRUE(emptyset2==emptyset)<<"empty sets not equal";
	EXPECT_FALSE(emptyset==oddSet)<<"empty set should not equal oddSet";
	EXPECT_FALSE(emptyset==evenSet)<<"empty set should not equal evenSet";
	EXPECT_FALSE(oddSet==evenSet)<<"odd set should not equal evenSet";
	EXPECT_TRUE(varset==varset)<<"var set failed equality";
	EXPECT_FALSE(varset==varset2)<<"var set failed equality varset2";
	EXPECT_FALSE(varset==emptyset)<<"var set failed equality empty";
	EXPECT_FALSE(varset==oddSet)<<"var set failed equality odd";
	EXPECT_FALSE(varset==evenSet)<<"var set failed equality even";

}





