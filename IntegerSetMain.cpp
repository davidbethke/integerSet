// IntegerSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"
#include "IntegerSet.h"

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
	IntegerSet iS;
	iS.insertElement(5);
	iS.insertElement(99);
	std::cout << iS;


}
