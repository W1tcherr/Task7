#include <iostream>
#include <time.h>
int main()
{
    const int number = 1000000;
    int* arr = new int[number + 1];

    double start = clock() * 1.0 / CLOCKS_PER_SEC;

    for(int i=0;i<=number;++i)
    {
        arr[i] = 0;
    }

    int m = number/2;
    for(int i=1;i<=m;++i)
    {

        for(int j=i+i;j<=number;j+=i)
            arr[j]+=i;
    }
    for(int i=1;i<=number;++i)
    {
        if(arr[i] <= number && arr[i] != i && arr[arr[i]] == i)
        {
            std::cout << i <<"\t  "<< arr[i] <<std::endl;
            arr[i] = 0;
        }

    }

    delete []arr;

    double end = clock() * 1.0 / CLOCKS_PER_SEC;
    std::cout << end - start << "sec" << std::endl;

    return 0;
}