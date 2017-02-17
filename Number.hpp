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
    char digits_array[15];
    
private:
    
    string string_representation_of_number;
    int amount_of_digits; // TODO: FIND AWAY TO GENREATE ARRAY ON THE FLY
    
};
#endif /* Number_hpp */
