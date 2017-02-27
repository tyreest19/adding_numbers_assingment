//
//  Number.hpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Number_hpp
#define Number_hpp

#include <string>
#include <iostream>

using namespace std;
const int MAXIMUM_LENGTH_OF_NUMBER = 15;

class Number
{
    
public:
    
    Number() { };
    Number(string user_enter_number, int maxium_choosen_size);
    void Set_String_Representation_Of_Number(string user_enter_number);
    void Set_Digit_Array();
    string Get_String_Representation_Of_Number();
    void Generate_Char_Array(string number);
    int maxium_size;
    char digits_array[MAXIMUM_LENGTH_OF_NUMBER];
    string raw_number;
    
private:
    string String_Representation_Of_Number;
    
};
#endif /* Number_hpp */
