// April 2016
// Insertion sort algorithm and a simple test harness

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// Public, if I were to write a header...
void insertion_sort(int a[], size_t count);

// Private helpers
static void print_array(int a[], size_t count);
static void swap(int a[], size_t i, size_t j);

void insertion_sort(int a[], size_t count)
{
    // Start at 1 because we swap with i-1
    for (size_t i = 1; i < count; i++)
    {
        size_t j = i;
        while (j >= 1 && a[j-1] > a[j])
        {
            swap(a, j, j-1);
            j--;
        }
    }
}

static void print_array(int a[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

static void swap(int a[], size_t i, size_t j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Test harness sorts numbers given as command line arguments
int main(int argc, char* argv[])
{
    size_t input_count = argc - 1;
    char** input_array = &argv[1];

    printf("input_count: %zu\n", input_count);

    int* input = malloc(input_count * sizeof(int));

    assert(input != NULL);

    for (size_t i = 0; i < input_count; i++)
    {
        input[i] = atoi(input_array[i]);
    }

    insertion_sort(input, input_count);
    print_array(input, input_count);

    free(input);

    return 0;
}
