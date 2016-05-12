// April 2016
// Recursive binary search algorithm and a simple test harness

#include <stdio.h>
#include <stdlib.h>

// The counter tracks callstack depth for fun. Pass NULL if you don't care.
int binary_search(const int* a, int l, int h, int k, int* counter)
{
    if (counter != NULL) (*counter)++;

    // Terminate if indexes cross over, no key found
    if (l > h) return -1;

    int m = (l + h) / 2;

    if (a[m] == k) return m;

    if (a[m] < k) return binary_search(a, m + 1, h, k, counter);
    else return binary_search(a, l, m - 1, k, counter);
}

// Test harness. Populates an incrementing array of ARRAY_LENGTH, then finds
// the index of the element argv[1] (should be equal to the index).
#define ARRAY_LENGTH 8192
int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        printf("USAGE: binary_search key\n");
        exit(1);
    }

    static int sorted[ARRAY_LENGTH];

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        sorted[i] = i;
    }

    int counter = 0;
    int key = atoi(argv[1]);
    int elem_idx = binary_search(sorted, 0, ARRAY_LENGTH - 1, key, &counter);

    printf("Found key=%d at index %d in %d calls\n", key, elem_idx, counter);

    return 0;
}
