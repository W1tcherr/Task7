#include <iostream>
#include <time.h>

int main() {
    const unsigned number = 1000000;
    unsigned count = 1;
    unsigned *arr = new unsigned[number + 1]{};

    double start = clock() * 1.0 / CLOCKS_PER_SEC;

    for (unsigned i = 1; i <= (number / 2); ++i)
    {
        for (unsigned j = i + i; j <= number; j += i)
            arr[j] += i;
    }

    for (unsigned i = 220; i <= number; ++i)
    {
        if (arr[i] <= number && arr[i] != i && arr[arr[i]] == i)
        {
            std::cout << count << ":\t" << i << "\t  " << arr[i] << std::endl;
            arr[i] = 0;
            ++count;
        }

    }
    delete[]arr;

    double end = clock() * 1.0 / CLOCKS_PER_SEC;
    std::cout << end - start << "sec" << std::endl;

    return 0;
}