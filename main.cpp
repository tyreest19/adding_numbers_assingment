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
#include "Calculator.hpp"

using namespace std;

const long long int MAXIMUM_AMOUNT_OF_NUMBERS = 10;
const long long int MINIMUN_AMOUNT_OF_NUMBERS = 2;
const int MAXIUM_AMOUNT_OF_DIGITS = 15;
const int MINIMUN_AMOUNT_OF_DIGITS = 1;
const long long int  MAXIMUM_USER_INPUTTED_NUMBER = 922337203685477580;
const long long int  MINIMUN_USER_INPUTTED_NUMBER = 0;
const string AMOUNT_OF_NUMBERS_PROMPT = "How many numbers? -> ";
const string INPUT_NUMBERS_PROMPT = "Enter number: ";
const string INVALID_INPUT_PROMPT = "\nInvalid Input \n \n";
const int MAXIMUM_LENGTH_OF_NUMBER = 15;

void get_numbers(Number array_of_numbers[], int amount_of_numbers);

int main()
{
    string get_amount_of_numbers = Get_Number(MAXIMUM_AMOUNT_OF_NUMBERS, MINIMUN_AMOUNT_OF_NUMBERS, AMOUNT_OF_NUMBERS_PROMPT, INVALID_INPUT_PROMPT, MAXIMUM_LENGTH_OF_NUMBER);
    const int amount_of_numbers = String_To_Int(get_amount_of_numbers.c_str());
    Number *numbers = new Number[amount_of_numbers];
    Calculator caluclator;
    get_numbers(numbers, amount_of_numbers);
    string sum_after_addition = caluclator.addition_operator(numbers, amount_of_numbers, MAXIUM_AMOUNT_OF_DIGITS);
    caluclator.print_addition(numbers, amount_of_numbers, sum_after_addition);

    return 0;
}

void get_numbers(Number array_of_numbers[], int amount_of_numbers)
{
    for (int i = 0; i < amount_of_numbers; i++)
    {
        array_of_numbers[i] = {Get_Number(MAXIMUM_USER_INPUTTED_NUMBER, MINIMUN_USER_INPUTTED_NUMBER, INPUT_NUMBERS_PROMPT, INVALID_INPUT_PROMPT, MAXIMUM_LENGTH_OF_NUMBER), MAXIUM_AMOUNT_OF_DIGITS};
        
    }
}
