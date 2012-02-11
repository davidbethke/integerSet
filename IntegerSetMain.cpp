// IntegerSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "gtest/gtest.h"
#include "IntegerSet.h"

int main(int argc, char** argv) 
{
#ifdef _DEBUG
		::testing::GTEST_FLAG(print_time) = true;
		::testing::GTEST_FLAG(output) = "xml:C:\\Program Files\\Jenkins\\jobs\\IntegerSetUnitTests\\workspace\\test_detail.xml";
	    testing::InitGoogleTest(&argc, argv); 
	    RUN_ALL_TESTS(); 
    //std::getchar(); // keep console window open until Return keystroke
#endif //_DEBUG
	/*
	IntegerSet iS;
	iS.insertElement(5);
	iS.insertElement(99);
	std::cout << iS;
	*/
		//added to test Jenkins


}
