//
//  main.cpp
//  intset_str (3)
//
//  Created by Serhii Hlushenkov on 03.11.2022.
//

#include <iostream>

void error (const char* s)
{
    std::cerr<<"set: "<<s<<"\n";
    exit(1);
}

class strset{
    int cursize, maxsize;
    char **x;
public:
    strset(int m);
    ~strset();
    int member (char* t) const;
    void insert (char* t);
    void start (int& i) const {i=0;}
    int ok(int& i) const {return i<cursize;}
    char* next(int& i) const {return x[i++];}
};

strset::strset(int m)
{
    cursize=0;
    maxsize=m;
    x = new char*[maxsize];
}

strset::~strset()
{
    delete x;
}

void strset::insert(char* t)
{
    if(++cursize>maxsize) error("too much elements");
    int i=cursize-1;
    x[i]=t;
}

int strset::member(char* t) const
{
    char* temp = t;
    for(int i=0;i<cursize;i++)
    {
        if(*temp==*x[i])
        {
            char* temp2 = x[i];
            while (*temp==*temp2 && *temp!='\0')
            {
                temp++;
                temp2++;
            }
            if(*temp=='\0' && *temp2=='\0')
                return 1;
        }
        temp=t;
    }
    return 0;
}

void print_in_order (strset* set)
{
    int var;
    set->start(var);
    while (set->ok(var)) std::cout<<set->next(var)<<"\n";
}

int main(int argc, const char * argv[]) {
    if(argc != 2) error("only one number need to be input");
    int count = 0;
    int m = atoi(argv[1]);
    strset s(m);
    std::cout<<"You need to enter a set of "<< m <<" strings"<<"\n";
    while (count<m)
    {
        char* temp = new char;
        std::cout<< "Enter your string: ";
        std::cin>>temp;
        if(s.member(temp)==0)
        {
            s.insert(temp);
            count++;
            std::cout<<m-count<<" strings left"<<"\n";
        }
        else
        {
            std::cout<<"Such string already exists in set, enter another one"<<"\n";
        }
    }
    std::cout<<"You entered those strings:"<<"\n";
    print_in_order(&s);
    return 0;
}
