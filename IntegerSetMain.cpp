// IntegerSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#ifdef _DEBUG
	#include "gtest/gtest.h"
#endif //_DEBUG
#include "IntegerSet.h"

//DONE Jenkins Test Release and Debug build
//DONE printset empty set prints ---
//DONE fix assignment operator, to resize
//DONE Double Check the Assignment in the Text Book
//FAIL Try to overload the [] operator
//TODO duplicate tests in a main program
//DONE make vector private?
//TODO check const IntegerSets and see what happens
//DONE isEqualTo member function, should dup ==?
//DONE uncapitalize SIZE since not const
using namespace std;
void makeEven(IntegerSet&);
void makeOdd(IntegerSet&);
int main(int argc, char** argv) 
{
#ifdef _DEBUG
		::testing::GTEST_FLAG(print_time) = true;
		::testing::GTEST_FLAG(output) = "xml:C:\\Program Files\\Jenkins\\jobs\\IntegerSetUnitTests\\workspace\\test_detail.xml";
		testing::InitGoogleTest(&argc, argv); 
		RUN_ALL_TESTS(); 
		std::getchar(); // keep console window open until Return keystroke
#endif //_DEBUG
#ifdef NDEBUG
	IntegerSet empty, evenSet, oddSet, halfSizeSet(50);
	int arr[]={99,5,2,4,2,2,0};
	IntegerSet varSet(arr,7);
	makeEven(evenSet);
	makeEven(halfSizeSet);
	makeOdd(oddSet);
	const IntegerSet constSet(varSet);
	
	//Check print with cout
	cout << "Print Empty"<<endl;
	cout <<empty<<endl;
	cout << "Print Even"<<endl;
	cout <<evenSet<<endl;
	cout << "Print halfSize"<<endl;
	cout <<halfSizeSet<<endl;
	cout << "Print Odd"<<endl;
	cout <<oddSet<<endl;
	cout << "Print array Init'd"<<endl;
	cout <<varSet<<endl;
	cout << "Print const"<<endl;
	cout <<constSet<<endl;

	std::getchar();
#endif //NDEBUG


}
void makeEven(IntegerSet& evenSet)
{
	for(int i=0; i<evenSet.size;++i)
	{
		if(!(i%2))
			//evenSet[i]=true;
			evenSet.insertElement(i);
	}
	
	//evenSet.insertElement(0);
}
void makeOdd(IntegerSet& oddSet)
{
	for(int i=0; i<oddSet.size;++i)
	{
		if((i%2))
			
			oddSet.insertElement(i);
	}
	
	//oddSet.insertElement(0);
}