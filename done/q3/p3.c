#include <stdio.h>
#include <ctype.h>

// function to sort an array using insertion sort algorithm
void insertion_sort(int array[], size_t size);

// function to shift elements of an array by 'places'
void shift(int array[], size_t marker, size_t places);

int main(void)
{
    // getting input
    size_t size;
    printf("Size of array: ");
    scanf("%zu", &size);
    getchar();

    // array to be sorted
    int array[size];

    printf("Enter the elements:\n");
    for (size_t i = 0; i < size; i++)
        scanf("%i", &array[i]);
    getchar();

    // sorting using insertion sort
    insertion_sort(array, size);

    // printing the sorted array
    printf("\nSorted: \n");
    for (size_t i = 0; i < size; i++)
        printf("%i%s", array[i], (i != size - 1) ? ", " : "");
    printf("\n");

    // deleting an element from array
    int del_in, val;
    char i_v;

    printf("\nDo you want to delete by index or by value (i/v): ");
    scanf("%c", &i_v);
    getchar();

    if (tolower(i_v) == 'i')
    {
        printf("Enter index at which element is to be deleted: ");
        scanf("%i", &del_in);
        if (del_in > size - 1 || del_in < 0)
        {
            printf("\nIndex out of range\n");
            return -1;
        }

        // shifting the elements
        for (int i = del_in; i < size; i++)
            array[i] = array[i + 1];
        
        // decreasing the size
        size--;
    }
    else
    {
        printf("Enter the value of element to be deleted: ");
        scanf("%i", &val);
        // searching for element
        for (int i = 0; i < size; i++)
        {
            if (array[i] == val)
            {
                for (int j = i; j < size; j++)
                    array[j] = array[j + 1];
                break;
            }
            else if (i == size - 1)
            {
                printf("\nElement having value: %i not found\n", val);
                return -1;
            }
        }
        size--;
    }

    printf("\nAfter Deletion: \n");
    for (size_t i = 0; i < size; i++)
        printf("%i%s", array[i], (i != size - 1) ? ", " : "");
    printf("\n");

    return 0;
}

void insertion_sort(int array[], size_t size)
{
    // for the marker between sorted and unsorted arrays
    for (size_t marker = 1; marker < size; marker++)
    {
        // number of places to shift the element that is currently being sorted
        size_t places = 1;
        // comparing the ussorted and sorted
        if (array[marker - 1] > array[marker])
        {
            for (long j = marker - 2; j >= 0; j--)
            {
                if (array[j] < array[marker])
                {
                    break;
                }
                places++;
            }
            shift(array, marker, places);
        }
    }
}
void shift(int array[], size_t marker, size_t places)
{
    int temp = array[marker]; // first element of unsorted array

    // index at which the number is just greater than the first element of unsorted array
    long just_larger = marker - places;
    for (long i = marker; i > just_larger; i--)
    {
        array[i] = array[i - 1];
    }
    array[just_larger] = temp;
    return;
}