//
//  main.cpp
//  Cat and Rev (9)
//
//  Created by Serhii Hlushenkov on 12.09.2022.
//

#include <iostream>

char* cat (const char* first, const char* second)
{
    char* result = new char();
    char* start = result;
    while (*first!='\0') {
        *result++ = *first++;
    }
    while (*second!='\0') {
        *result++ = *second++;
    }
    return start;
}

char* rev (const char* sample)
{
    char* result = new char();
    char* start = result;
    int length=0;
    while(*sample!='\0')
    {
        length++;
        sample++;
    }
    sample--;
    for(int i=0;i<length;i++)
    {
        *result++=*sample--;
    }
    return start;
}

int main(int argc, const char * argv[]) {
    char* first = new char();
    char* second = new char();
    std::cin>>first;
    std::cin>>second;
    std::cout << cat(first, second)<<"\n";
    std::cout << rev(first)<<"\n";
    return 0;
}
