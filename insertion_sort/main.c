#include <stdio.h>
#include <stdint.h>

void insertion_sort(int a[], size_t count);
static void print_array(int a[], size_t count);
static void swap(int a[], size_t i, size_t j);

void insertion_sort(int a[], size_t count)
{
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

int main(int argc, char* argv[])
{
    int test_array[] = {1, 0, -10, -20, 100};

    printf("Unsorted:\n");
    print_array(test_array, sizeof(test_array)/sizeof(*test_array));

    printf("Sorted:\n");
    insertion_sort(test_array, sizeof(test_array)/sizeof(*test_array));
    print_array(test_array, sizeof(test_array)/sizeof(*test_array));
    return 0;
}
