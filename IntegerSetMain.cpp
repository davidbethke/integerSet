// IntegerSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#ifdef _DEBUG
	#include "gtest/gtest.h"
#endif //_DEBUG
#include "IntegerSet.h"

//DONE Jenkins Test Release and Debug build
//TODO printset empty set prints ---
//TODO fix assignment operator, to resize
//TODO Double Check the Assignment in the Text Book
//TODO Try to overload the [] operator
//TODO duplicate tests in a main program
int main(int argc, char** argv) 
{
#ifdef _DEBUG
		::testing::GTEST_FLAG(print_time) = true;
		::testing::GTEST_FLAG(output) = "xml:C:\\Program Files\\Jenkins\\jobs\\IntegerSetUnitTests\\workspace\\test_detail.xml";
		testing::InitGoogleTest(&argc, argv); 
		RUN_ALL_TESTS(); 
		std::getchar(); // keep console window open until Return keystroke
#endif //_DEBUG
	/*
	IntegerSet iS;
	iS.insertElement(5);
	iS.insertElement(99);
	std::cout << iS;
	*/
		//added to test Jenkins


}
