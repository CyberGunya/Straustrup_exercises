//
//  main.cpp
//  Reverse_array (10)
//
//  Created by Serhii Hlushenkov on 05.10.2022.
//
// This code allows to reverse two-dimensional array for all main C++ types

#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <string>

using TypeInfoRef = std::reference_wrapper<const std::type_info>;
 
struct Hasher {
    std::size_t operator()(TypeInfoRef code) const
    {
        return code.get().hash_code();
    }
};
 
struct EqualTo {
    bool operator()(TypeInfoRef lhs, TypeInfoRef rhs) const
    {
        return lhs.get() == rhs.get();
    }
};

void swap(char* first, char* second, unsigned size)
{
    for(int i=0;i<size;i++)
    {
        char temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

void reverse(void** arr, unsigned size_x, unsigned size_y, unsigned size, std::string type)
{
    int left = 0;
    int right = size_x*size_y-1;
    switch (type[0])
    {
        case 'i':{
            int **temp = new int*[size_x];
            for(int i=0;i<size_x;i++)
            {
                temp[i]=static_cast<int*>(arr[i]);
            }
            while(left<right)
            {
                swap((char*)&temp[left/size_y][left%size_y], (char*)&temp[right/size_y][right%size_y], size);
                left++;
                right--;
            }
            for(int i=0;i<size_x;i++)
            {
                arr[i]=&temp[i];
            }
            break;
        }
        case 'd':
        {
            double **temp = new double*[size_x];
            for(int i=0;i<size_x;i++)
            {
                temp[i]=static_cast<double*>(arr[i]);
            }
            while(left<right)
            {
                swap((char*)&temp[left/size_y][left%size_y], (char*)&temp[right/size_y][right%size_y], size);
                left++;
                right--;
            }
            for(int i=0;i<size_x;i++)
            {
                arr[i]=&temp[i];
            }
            break;
        }
        case 'b':
        {
            bool **temp = new bool*[size_x];
            for(int i=0;i<size_x;i++)
            {
                temp[i]=static_cast<bool*>(arr[i]);
            }
            while(left<right)
            {
                swap((char*)&temp[left/size_y][left%size_y], (char*)&temp[right/size_y][right%size_y], size);
                left++;
                right--;
            }
            for(int i=0;i<size_x;i++)
            {
                arr[i]=&temp[i];
            }
            break;
        }
        case 'c':
        {
            char **temp = new char*[size_x];
            for(int i=0;i<size_x;i++)
            {
                temp[i]=static_cast<char*>(arr[i]);
            }
            while(left<right)
            {
                swap((char*)&temp[left/size_y][left%size_y], (char*)&temp[right/size_y][right%size_y], size);
                left++;
                right--;
            }
            for(int i=0;i<size_x;i++)
            {
                arr[i]=&temp[i];
            }
            break;
        }
        case 'f':
        {
            float **temp = new float*[size_x];
            for(int i=0;i<size_x;i++)
            {
                temp[i]=static_cast<float*>(arr[i]);
            }
            while(left<right)
            {
                swap((char*)&temp[left/size_y][left%size_y], (char*)&temp[right/size_y][right%size_y], size);
                left++;
                right--;
            }
            for(int i=0;i<size_x;i++)
            {
                arr[i]=&temp[i];
            }
            break;
        }
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    //declaring all main types
    
    std::unordered_map<TypeInfoRef, std::string, Hasher, EqualTo> type_names;
    type_names[typeid(int)] = "int";
    type_names[typeid(double)] = "double";
    type_names[typeid(bool)] = "bool";
    type_names[typeid(char)] = "char";
    type_names[typeid(float)] = "float";
    
    int arr_int[3][3] = {1,2,3,4,5,6,7,8,9};
    double arr_dbl[3][3] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    bool arr_bool[2][2] = {1,0,1,0};

    void** pointer = new void*[3];
    
    //reverting int array
    for(int i=0;i<3;i++)
    {
        pointer[i] = &arr_int[i];
    }
    reverse(pointer, 3, 3, sizeof(arr_int[0][0]), type_names[typeid(arr_int[0][0])]);
    
    //reverting double array
    for(int i=0;i<3;i++)
    {
        pointer[i] = &arr_dbl[i];
    }
    reverse(pointer, 3, 3, sizeof(arr_dbl[0][0]), type_names[typeid(arr_dbl[0][0])]);
    
    //reverting bool array
    for(int i=0;i<2;i++)
    {
        pointer[i] = &arr_bool[i];
    }
    reverse(pointer, 2, 2, sizeof(arr_bool[0][0]), type_names[typeid(arr_bool[0][0])]);
    return 0;
}
