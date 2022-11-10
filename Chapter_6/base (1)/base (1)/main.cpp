//
//  main.cpp
//  base (1)
//
//  Created by Serhii Hlushenkov on 10.11.2022.
//

#include <iostream>

class base{
public:
    virtual void iam() { std::cout<< "base\n"; }
};

class base1 : public base{
public:
    void iam() { std::cout<<"base1\n"; }
};

class base2 : public base{
public:
    void iam() { std::cout<<"base2\n"; }
};

int main(int argc, const char * argv[]) {
    base b;
    base1 b1;
    base2 b2;
    b.iam();
    b1.iam();
    b2.iam();
    base* temp = &b1;
    temp->iam();
    temp = &b2;
    temp->iam();
    return 0;
}
