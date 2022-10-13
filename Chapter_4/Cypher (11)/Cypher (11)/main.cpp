//
//  main.cpp
//  Cypher (11)
//
//  Created by Serhii Hlushenkov on 13.10.2022.
//

#include <iostream>

//checking if command line is empty
bool check(int argc, const char* argv[])
{
    if(argc>1)
    {
        if(argv[1][0]=='\0')
        {
            std::cout<<"Entered key is empty, message won't be encrypted!"<<"\n";
            return false;
        }
        return true;
    }
    else
    {
        std::cout<<"Key is missing, message won't be encrypted!"<<"\n";
        return false;
    }
}

//getting a full key (for a case if there is more than one word)
char* get_key(int argc, const char* argv[], int &num)
{
    char* temp = new char();
    char* key = temp;
    num=0;
    for(int i=1;i<argc;i++)
    {
        const char* pointer = argv[i];
        while(*pointer!='\0')
        {
            *temp++=*pointer++;
            num++;
        }
    }
    return key;
}

//getting input message
char* read(int &count)
{
    char* input = new char();
    char* inp = input;
    count=0;
    do {
        *input=std::cin.get();
        count++;
    } while (*input++!='\n');
    char* rez = new char[count];
    char* result = rez;
    for(int i=0;i<count;i++)
    {
        *rez++=*inp++;
    }
    return result;
}

char* cypher(char* msg, char* key, int length)
{
    char* temp = new char();
    char* output = temp;
    int i=0;
    while(*msg!='\0')
    {
        *temp=*msg^key[i++];
        temp++;
        msg++;
        if(i==length)
        {
            i=0;
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    bool flag = check(argc,argv);
    int num=0;
    char* key = get_key(argc, argv, num);
    int length=0;
    char* input = read(length);
    std::cout<<"Your entered message: "<<input;
    char* output = new char[length];
    output = cypher(input, key, num);
    if(flag)
    {
        std::cout<<"Cyphering with key: "<<key<<"\n";
        std::cout<<"Your encrypted message: "<<output<<"\n";
    }
    else
    {
        std::cout<<"Key is missing, message can't be encrypted!"<<"\n";
    }
    
    return 0;
}
