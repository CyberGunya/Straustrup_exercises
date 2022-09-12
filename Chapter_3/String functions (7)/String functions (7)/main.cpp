//
//  main.cpp
//  String functions (7)
//
//  Created by Serhii Hlushenkov on 05.08.2022.
//

#include <iostream>

const int max_length = 150;     //limit for the entry

int my_strlen(const char str[])
{
    int counter=0;
    const char* p = str;
    while(*p++!='\0')
    {
        counter++;
    }
    return counter;
}

char* my_strcpy(const char str[])
{
    char* p = new char[my_strlen(str)];
    char* rez = p;
    const char* q = str;
    while(*q!='\0')
    {
        *p++=*q++;
    }
    return rez;
}

bool my_strcmp(const char str1[], const char str2[])
{
    bool flag=true;
    const char* p=str1;
    const char* q=str2;
    while(*p!='\0'&&*q!='\0')
    {
        if(*p++!=*q++)
        {
            flag=false;
            return flag;
        }
    }
    if(*p=='\0'&&*q=='\0')
    {
        
    }
    else
    {
        flag=false;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    char* str1 = new char();
    std::cin.getline(str1, max_length);
    std::cout<<"Length of entered message is: "<<my_strlen(str1)<<"\n";
    char* str2 = my_strcpy(str1);
    std::cout<<"Copied one: "<<str2<<"\n";
    char* str3 = new char();
    std::cin.getline(str3, max_length);
    std::cout<<"Entered messages "<<(my_strcmp(str1, str3)?"are":"are not")<<" equal"<<"\n";
    return 0;
}
