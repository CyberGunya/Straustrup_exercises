//
//  main.cpp
//  Descriptions (1)
//
//  Created by Serhii Hlushenkov on 28.09.2022.
//

#include <iostream>

extern void first(char*, int&);

typedef void (*second)(char*, int&);

extern void third(second);

extern second fourth();

second fifth(second x)
{
    int q=2;
    char* s = new char();
    (*x)(s,q);
    return fourth();
}

int main(int argc, const char * argv[]) {
    return 0;
}
