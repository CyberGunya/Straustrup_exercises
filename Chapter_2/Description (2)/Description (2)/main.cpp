//
//  main.cpp
//  Description (2)
//
//  Created by Serhii Hlushenkov on 19.03.2022.
//

#include <iostream>
#include "Header.h"
#include <math.h>

extern char ch;
extern int count;
extern char * name;
struct complex;
extern complex cvar;
complex sqrt(complex x)
{
    complex y;
    y.re=sqrt(x.re);
    y.im=sqrt(x.im);
    return y;
}
int error_number=1;
typedef complex point;
float real (complex*);
extern const double pi;
struct user
{
    char* name;
    int age;
};
template<class T> T abs(T);
enum beer;

int main() {
    return 0;
}
