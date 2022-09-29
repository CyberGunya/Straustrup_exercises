//
//  main.cpp
//  Cat (4)
//
//  Created by Serhii Hlushenkov on 28.09.2022.
//

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    std::ifstream input;
    for(int i=1;i<argc;i++)
    {
        std::string file = "/Users/gunya/Desktop/Learn_C++/Chapter_4/Cat (4)/Cat (4)/";
        // Enter the path, where mentioned files are located
        file+=argv[i];
        input.open(file);
        if(input.is_open())
        {
            while(input)
            {
                file=input.get();
                if(file!="\377")
                {
                    std::cout<<file;
                }
            }
        }
        std::cout<<"\n";
        input.close();
    }
    return 0;
}
