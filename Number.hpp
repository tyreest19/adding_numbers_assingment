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
    
    Number();
    void set_numeric_representation_of_number(long long int user_enter_number);
    void set_string_representation_of_number(string user_enter_number);
    long long int get_numeric_representation_of_number();
    string get_string_representation_of_number();
    
private:
    
    string string_representation_of_number;
    long long int numeric_representation_of_number;
    const int amount_of_digits; // TODO: FIND AWAY TO GENREATE ARRAY ON THE FLY
    
};
#endif /* Number_hpp */
