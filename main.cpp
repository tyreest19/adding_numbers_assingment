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

const int MAXIMUM_AMOUNT_OF_NUMBERS = 10;
const int MINIMUN_AMOUNT_OF_NUMBERS = 2;
const int MAXIMUM_AMOUNT_OF_DIGITS = 15;
const int MINIMUN_AMOUNT_OF_DIGITS = 1;
const string AMOUNT_OF_NUMBERS_PROMPT = "How many numbers? -> ";
const string INPUT_NUMBERS_PROMPT = "Input number #";
const string INVALID_INPUT_PROMPT = "\nInvalid Input \n \n";
const int MAXIMUM_AMOUNT_OF_MULTIPLES = 2;

void get_numbers(Number array_of_numbers[], int amount_of_numbers);

int main()
{
    int amount_of_numbers = 0;
    do {
        
        string get_amount_of_numbers = Get_Number(AMOUNT_OF_NUMBERS_PROMPT, INVALID_INPUT_PROMPT, MAXIMUM_LENGTH_OF_NUMBER);
        amount_of_numbers = int(String_To_Int(get_amount_of_numbers.c_str()));
       
        if (!(MINIMUN_AMOUNT_OF_DIGITS <= amount_of_numbers && amount_of_numbers <= MAXIMUM_AMOUNT_OF_NUMBERS))
        {
            cout << INVALID_INPUT_PROMPT;
        }
        
    } while (!(MINIMUN_AMOUNT_OF_DIGITS <= amount_of_numbers && amount_of_numbers <= MAXIMUM_AMOUNT_OF_NUMBERS));
    
    Number numbers[MAXIMUM_AMOUNT_OF_NUMBERS];
    Calculator caluclator;
    get_numbers(numbers, amount_of_numbers);
    
    Number array_of_multiplies[MAXIMUM_AMOUNT_OF_MULTIPLES];
    
    for (int i = 0; i < MAXIMUM_AMOUNT_OF_MULTIPLES; i++)
    {
        array_of_multiplies[i] = numbers[i];
    }
    
    string sum_after_addition = caluclator.addition_operator(numbers, amount_of_numbers, MAXIMUM_AMOUNT_OF_DIGITS);
    caluclator.print_addition(numbers, amount_of_numbers, sum_after_addition);
    string product = caluclator.two_digit_multiplication_operator(array_of_multiplies, MAXIMUM_AMOUNT_OF_MULTIPLES, MAXIMUM_AMOUNT_OF_DIGITS);
    caluclator.print_multiplication(array_of_multiplies, MAXIMUM_AMOUNT_OF_MULTIPLES, product);
    cout << "\nfinal multiple answer: " << product << endl;
    
    return 0;
}

//============================================================================================
// Gets user inputted numbers.
//============================================================================================

void get_numbers(Number array_of_numbers[], int amount_of_numbers)
{
    for (int i = 0; i < amount_of_numbers; i++)
    {
        string number_being_entered = "  -> ";
        number_being_entered[0] = (i + 1) + '0';
        
        if (i == 9)
        {
            number_being_entered = "10 -> ";
        }
        
        array_of_numbers[i] = {Get_Number(INPUT_NUMBERS_PROMPT + number_being_entered, INVALID_INPUT_PROMPT,MAXIMUM_LENGTH_OF_NUMBER), MAXIMUM_AMOUNT_OF_DIGITS};
    }
}
