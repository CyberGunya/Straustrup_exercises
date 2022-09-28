//
//  main.cpp
//  Hello names (3)
//
//  Created by Serhii Hlushenkov on 28.09.2022.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    for(int i=1;i<argc;i++)
    {
        std::cout << "Hello, "<<argv[i]<<"!\n";
    }
    return 0;
}
