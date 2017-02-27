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
    void set_string_representation_of_number(string user_enter_number);
    void set_digit_array();
    string get_string_representation_of_number();
    void generate_char_array(string number);
    int maxium_size;
    char digits_array[MAXIMUM_LENGTH_OF_NUMBER];
    string raw_number;
    
private:
    string string_representation_of_number;
    
};
#endif /* Number_hpp */
