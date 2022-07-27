//
//  main.cpp
//  a-z-0-9 (5)
//
//  Created by Serhii Hlushenkov on 19.03.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int number=97;
    for(int i=0;i<26;i++)
    {
        char ch(97+i);
        cout<<ch<<"\t"<<number<<"\t"<<"\\x"<<std::hex<<number<<"\n";
        number++;
    }
    number=48;
    for(int i=0;i<10;i++)
    {
        char ch(48+i);
        cout<<ch<<"\t"<<number<<"\t"<<"\\x"<<std::hex<<number<<"\n";
        number++;
    }
    return 0;
}
