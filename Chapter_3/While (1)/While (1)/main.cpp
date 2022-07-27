//
//  main.cpp
//  While (1)
//
//  Created by Serhii Hlushenkov on 27.07.2022.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int max_length=10;
    char* input_line = new char[max_length];
    std::cin>>input_line;
    int quest_count=0;
    
    for (int i=0; i<max_length; i++)    //Basic loop
    {
        if(input_line[i]=='?')
            quest_count++;
    }
    
    quest_count=0;
    
    char* p = input_line;
    while (*p++ == '?')                //alternative loop
    {
        quest_count++;
    }
    delete[] input_line;
    return 0;
}
