//
//  main.cpp
//  Heap sort (6)
//
//  Created by Serhii Hlushenkov on 29.09.2022.
//  Due to the task 6 from chapter 4 - this program uses heap sort sorting algorithm

#include <iostream>


struct user {
  char* name;
  char* id;
  int dept;
};
typedef user* Puser;
user heads[] = {
  "Ritchie D.M.", "dmr",   11271,
  "Sethi R.", "ravi",  11272,
  "SZYmanski T.G.", "tgs",   11273,
  "Schryer N.L.", "nls",   11274,
  "Schryer N.L.", "nls",   11275,
  "Kernighan B.W.", "bwk",   11276
  };
  void print_id(Puser v, int n)
  {
     for (int i=0; i<n; i++)
       std::cout << v[i].name << '\t'
            << v[i].id << '\t'
            << v[i].dept << '\n';
}


void swap(char* first, char* second, unsigned size)
{
    for(int i=0;i<size;i++)
    {
        char temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

//names comparator
int cmp1(const void* p, const void* q)
{
   return (strcmp(Puser(p)->name, Puser(q)->name)>=0)? 1 : 0 ;
}

//numbers comparator
int cmp2(const void* p, const void* q)
{
    return (Puser(p)->dept - Puser(q)->dept>=0) ? 1 : 0;
}

void heapify(void* base, unsigned n, unsigned i, unsigned size, int (*cmp)(const void*, const void*))
{
    unsigned largest = i;
    unsigned l = 2*i + 1;
    unsigned r = 2*i + 2;
    if(l<n && (*cmp)((char*)base+l*size, (char*)base+largest*size))
    {
        largest=l;
    }
    if(r<n && (*cmp)((char*)base+r*size, (char*)base+largest*size))
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap((char*)base+i*size, (char*)base+largest*size, size);
        heapify(base, n, largest, size, cmp);
    }
}

void heap_sort(void* base, unsigned n, unsigned size, int (*cmp)(const void*, const void*))
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(base, n, i, size, cmp);
    }
    for(int i=n-1;i>0;i--)
    {
        swap((char*)base, (char*)base+i*size, size);
        heapify(base, i, 0, size, cmp);
    }
}


int main(int argc, const char * argv[]) {
    heap_sort(heads,6,sizeof(user), cmp1);
    print_id(heads,6);
    std::cout << "\n";
    heap_sort(heads,6,sizeof(user),cmp2);
    print_id(heads,6);
    return 0;
}
