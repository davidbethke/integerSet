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
//DONE check const IntegerSets and see what happens
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
	IntegerSet empty, evenSet, oddSet,evenSet2,oddSet2, halfSizeSet(50);
	int arr[]={200,5,2,4,2,2,0};
	IntegerSet varSet(arr,7);
	makeEven(evenSet);
	makeEven(evenSet2);
	makeEven(halfSizeSet);
	makeOdd(oddSet);
	makeOdd(oddSet2);
	const IntegerSet constSet(varSet);

	//Check print with printSet
	cout << "Print Empty"<<endl;
	empty.printSet();cout <<endl;
	cout << "Print Even"<<endl;
	evenSet.printSet();cout <<endl;
	cout << "Print halfSize"<<endl;
	halfSizeSet.printSet();cout <<endl;
	cout << "Print Odd"<<endl;
	oddSet.printSet();cout <<endl;
	cout << "Print array Init'd"<<endl;
	varSet.printSet();cout <<endl;
	cout << "Print const"<<endl;
	constSet.printSet();cout <<endl;
	
	//Insert using insertElement
	cout << "Insert Empty"<<endl;
	empty.insertElement(0);
	cout <<empty<<endl;
	cout << "Insert Even"<<endl;
	evenSet.insertElement(1);
	cout <<evenSet<<endl;
	cout << "Insert halfSize"<<endl;
	halfSizeSet.insertElement(1);
	cout <<halfSizeSet<<endl;
	cout << "Insert Odd"<<endl;
	oddSet.insertElement(2);
	cout <<oddSet<<endl;
	cout << "Insert array Init'd"<<endl;
	varSet.insertElement(44);
	cout <<varSet<<endl;
	cout << "Can='t Insert const"<<endl;
	//constSet.insertElement(44); //error can't insert
	cout <<constSet<<endl;

	//Delete using deleteElement
	cout << "Delete Empty"<<endl;
	empty.deleteElement(0);
	cout <<empty<<endl;
	cout << "Delete Even"<<endl;
	evenSet.deleteElement(1);
	cout <<evenSet<<endl;
	cout << "Delete halfSize"<<endl;
	halfSizeSet.deleteElement(1);
	cout <<halfSizeSet<<endl;
	cout << "Delete Odd"<<endl;
	oddSet.deleteElement(2);
	cout <<oddSet<<endl;
	cout << "Delete array Init'd"<<endl;
	varSet.deleteElement(44);
	cout <<varSet<<endl;
	cout << "Can='t Delete const"<<endl;
	//constSet.deleteElement(44); //error can't insert
	cout <<constSet<<endl;

	//union of Sets
	cout << "Empty union Even"<<endl;
	IntegerSet unionEE=empty.unionOfSets(evenSet);
	cout <<unionEE<<endl;
	cout << "Odd union Even"<<endl;
	IntegerSet unionOE=oddSet.unionOfSets(evenSet);
	cout <<unionOE<<endl;
	cout << "Odd union HalfSize"<<endl;
	IntegerSet unionOH=oddSet.unionOfSets(halfSizeSet);
	cout <<unionOH<<endl;
	cout << "Even union const"<<endl;
	IntegerSet unionEC=evenSet.unionOfSets(constSet);
	cout <<unionEC<<endl;
	cout << "Even union varSet"<<endl;
	IntegerSet unionEvC=evenSet.unionOfSets(varSet);
	cout <<unionEvC<<endl;

	//intersection of Sets
	cout << "Empty intersection Even"<<endl;
	IntegerSet intersectEE=empty.intersectionOfSets(evenSet);
	cout <<intersectEE<<endl;
	cout << "Odd intersection Even"<<endl;
	IntegerSet intersectOE=oddSet.intersectionOfSets(evenSet);
	cout <<intersectOE<<endl;
	cout << "Odd intersection HalfSize"<<endl;
	IntegerSet intersectOH=oddSet.intersectionOfSets(halfSizeSet);
	cout <<intersectOH<<endl;
	cout << "Even intersection HalfSize"<<endl;
	IntegerSet intersectEH=evenSet.intersectionOfSets(halfSizeSet);
	cout <<intersectEH<<endl;
	cout << "HalfSize intersection Odd"<<endl;
	IntegerSet intersectHO=halfSizeSet.intersectionOfSets(oddSet);
	cout <<intersectHO<<endl;
	cout << "Even intersection const"<<endl;
	IntegerSet intersectEC=evenSet.intersectionOfSets(constSet);
	cout <<intersectEC<<endl;
	cout << "Even intersection Even"<<endl;
	IntegerSet intersectEv=evenSet.intersectionOfSets(evenSet);
	cout <<intersectEv<<endl;
	/////////////////////////////////////
	//   Operators
	//////////////////////////////////////

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

	//Insert using +=
	cout << "Insert Empty"<<endl;
	empty+=0;
	cout <<empty<<endl;
	cout << "Insert Even"<<endl;
	evenSet+=1;
	cout <<evenSet<<endl;
	cout << "Insert halfSize"<<endl;
	halfSizeSet+=1;
	cout <<halfSizeSet<<endl;
	cout << "Insert Odd"<<endl;
	oddSet+=2;
	cout <<oddSet<<endl;
	cout << "Insert array Init'd"<<endl;
	varSet+=44;
	cout <<varSet<<endl;
	cout << "Can='t Insert const"<<endl;
	//constSet.i+=44; //error can't insert
	cout <<constSet<<endl;

	//Delete using deleteElement
	cout << "Delete Empty"<<endl;
	empty-=0;
	cout <<empty<<endl;
	cout << "Delete Even"<<endl;
	evenSet-=1;
	cout <<evenSet<<endl;
	cout << "Delete halfSize"<<endl;
	halfSizeSet-=1;
	cout <<halfSizeSet<<endl;
	cout << "Delete Odd"<<endl;
	oddSet-=2;
	cout <<oddSet<<endl;
	cout << "Delete array Init'd"<<endl;
	varSet-=44;
	cout <<varSet<<endl;
	cout << "Can='t Delete const"<<endl;
	//constSet.-=0; //error can't insert
	cout <<constSet<<endl;

	//union of Sets
	cout << "Empty union Even"<<endl;
	IntegerSet unionEEOp=empty|evenSet;
	cout <<unionEEOp<<endl;
	cout << "Odd union Even"<<endl;
	IntegerSet unionOEOp=oddSet|evenSet;
	cout <<unionOEOp<<endl;
	cout << "Odd union HalfSize"<<endl;
	IntegerSet unionOHOp=oddSet|halfSizeSet;
	cout <<unionOHOp<<endl;
	cout << "Even union const"<<endl;
	IntegerSet unionECOp=evenSet|constSet;
	cout <<unionECOp<<endl;

	//intersection of Sets
	cout << "Empty intersection Even"<<endl;
	IntegerSet intersectEEOp=empty&evenSet;
	cout <<intersectEEOp<<endl;
	cout << "Odd intersection Even"<<endl;
	IntegerSet intersectOEOp=oddSet&evenSet;
	cout <<intersectOEOp<<endl;
	cout << "Odd intersection HalfSize"<<endl;
	IntegerSet intersectOHOp=oddSet&halfSizeSet;
	cout <<intersectOHOp<<endl;
	cout << "Even intersection HalfSize"<<endl;
	IntegerSet intersectEHOp=evenSet&halfSizeSet;
	cout <<intersectEHOp<<endl;
	cout << "HalfSize intersection Even"<<endl;
	IntegerSet intersectHEOp=evenSet&halfSizeSet;
	cout <<intersectHEOp<<endl;
	cout << "HalfSize intersection Odd"<<endl;
	IntegerSet intersectHOOp=halfSizeSet&oddSet;
	cout <<intersectHOOp<<endl;
	cout << "Even intersection const"<<endl;
	IntegerSet intersectECOp=evenSet&constSet;
	cout <<intersectECOp<<endl;
	cout << "Even intersection Even"<<endl;
	IntegerSet intersectEvOp=evenSet&evenSet;
	cout <<intersectEvOp<<endl;
	
	// Check Equality
	if(oddSet == oddSet2)
		cout << "Odd Set Equal, PASS";
	else
		cout << "Odd set Not Equal,FAIL";
	cout<<endl;
	if(evenSet == evenSet2)
		cout << "Even Set Equal, PASS";
	else
		cout << "Evenset Not Equal,FAIL";
	cout<<endl;
	if(halfSizeSet == evenSet)
		cout << "Even Set Equal halfSize, FAIL";
	else
		cout << "Evenset Not Equal halfSize, PASS";
	cout<<endl;
	if(oddSet == evenSet)
		cout << "Even Set Equal Odd, FAIL";
	else
		cout << "Evenset Not Equal Odd, PASS";


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