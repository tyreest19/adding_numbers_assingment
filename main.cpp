//
//  main.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const string Maxium_Amount_Of_Numbers = "10";
const string Minimum_Amount_Of_Numbers = "2";
const string Maxium_Amount_Of_Digits = "15";
const string Minimum_Amount_Of_Digits = "1";
const string AMOUNT_OF_NUMBERS_PROMPT = "How many numbers? -> ";
const string INPUT_NUMBERS_PROMPT = "Enter number";
const string INVALID_INPUT_PROMPT = "\n Invalid Input \n";

struct Number {
    
    string Number;
    int amount_of_digits;
    
};

int main(int argc, const char * argv[]) {
    string test = "hey there i am an test";
    std::cout << "Hello, World!\n";
    return 0;
}
