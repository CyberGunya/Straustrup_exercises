//
//  main.cpp
//  Description (3)
//
//  Created by Serhii Hlushenkov on 19.03.2022.
//

#include <iostream>

char x='a';
char* symbol=&x;  //указатель на символ
int v[10]={0,1,2,3,4,5,6,7,8,9};    //массив из 10 целых
int& first=*v;     //ccылка на массив из 10

char mass[2][2]={{'a','b'},{'c','d'}};

char* mass_point=&mass[0][0];      //указатель на массив символьных строк

char** symbol_2=&symbol;    //указатель на указатель на символ
const int y=1;              //целое-константа
const int* z = &y;          //указатель на целое-константу
int w = 2;
int *const q = &w;          //константный указатель на целое


int main()
{
    return 0;
}
