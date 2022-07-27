//
//  main.cpp
//  Zero pointer (6)
//
//  Created by Serhii Hlushenkov on 21.03.2022.
//

#include <iostream>

struct fudge
{
  union
  {
      int i;
      int* p;
  };
};

int main() {
    fudge a;
    a.p=0;
    int q=a.i;
    std::cout<<q<<"\n";
    return 0;
}
