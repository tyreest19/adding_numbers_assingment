//
//  utils.hpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int String_To_Int(char *str);
int Get_Number(int maxium_amount_of_numbers, int minimum_amount_of_numbers, string prompt, string invalid_input_prompt);
#endif /* utils_hpp */
