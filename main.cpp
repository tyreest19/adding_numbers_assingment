//
//  main.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "utils.hpp"
#include "Number.hpp"

using namespace std;

const int MAXIMUM_AMOUNT_OF_NUMBERS = 10;
const int MINIMUN_AMOUNT_OF_NUMBERS = 2;
const int MAXIUM_AMOUNT_OF_DIGITS = 15;
const int MINIMUN_AMOUNT_OF_DIGITS = 1;
const string  MAXIMUM_USER_INPUTTED_NUMBER = "999999999999999";
const string MINIMUN_USER_INPUTTED_NUMBER = "0";
const string AMOUNT_OF_NUMBERS_PROMPT = "How many numbers? -> ";
const string INPUT_NUMBERS_PROMPT = "Enter number";
const string INVALID_INPUT_PROMPT = "\nInvalid Input \n \n";
const int MAXIMUM_LENGTH_OF_NUMBER = 15;

int main()
{
//    Get_Number(MAXIMUM_AMOUNT_OF_NUMBERS, MINIMUN_AMOUNT_OF_NUMBERS, AMOUNT_OF_NUMBERS_PROMPT, INVALID_INPUT_PROMPT, MAXIMUM_LENGTH_OF_NUMBER);
    Number number("90");
    cout << number.get_string_representation_of_number() <<"\n";
    return 0;
}

