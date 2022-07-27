//
//  main.cpp
//  TypeDef (13)
//
//  Created by Serhii Hlushenkov on 26.03.2022.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    typedef unsigned char first;    //unsigned char
    typedef const first second;     //const unsigned char
    typedef int* third;             //указатель на целое
    typedef char** fourth;          //указатель на указатель на символ
    typedef char (*fifth)[];        //указатель на массив символов
    typedef third sixth[7];         //массив из 7 указателей на целое
    typedef sixth* seventh;         //указатель на массив из 7 указателей на целое
    typedef sixth eighth[8];        //массив из 8 массивов из 7 указателей на целое
    
    return 0;
}
