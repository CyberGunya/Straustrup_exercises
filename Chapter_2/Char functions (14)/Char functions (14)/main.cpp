//
//  main.cpp
//  Char functions (14)
//
//  Created by Serhii Hlushenkov on 26.03.2022.
//

#include <iostream>
using namespace std;

void f(char x)
{
    cout<<x<<"\n";
}

void g(char &x)
{
    cout<<x<<"\n";
}

void h(const char x)
{
    cout<<x<<"\n";
}


int main(int argc, const char * argv[]) {
    f('a');
    // g('a');   - error
    h('a');
    
    f(49);
    // g(49);   - error
    h(49);
    
    f(3300);
    // g(3300); - error
    h(3300);
    
    char c;
    
    f(c);
    g(c);
    h(c);
    
    unsigned char uc;
    
    f(uc);
    // g(uc);   - error
    h(uc);
    
    signed char sc;
    
    f(sc);
    // g(sc);   - error
    h(sc);
    
    return 0;
}
