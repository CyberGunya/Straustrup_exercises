//
//  main.cpp
//  Str_Length (11)
//
//  Created by Serhii Hlushenkov on 25.03.2022.
//

#include <iostream>

int main() {
    
    char str[]="a short string";
    std::cout<<"Char array size : "<<sizeof(str)<<"\n";
    std::string s="a short string";
    std::cout<<"String length : "<<s.length()<<"\n";
    return 0;
}
