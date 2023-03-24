#include <iostream>
#include "../include/listops.h"

using namespace std;

void quicksort(MyList *p_list, int lo, int hi);
int partition(MyList *p_list, int lo, int hi);

// Adds an item to the end of the list 
// Returns 0 if the element is successfully added
// Returns -1 otherwise: 1) if the list is full, or 2) the item is negative
int append(MyList *p_list, int item)
{
    // return -1 for the two cases
    if (p_list->len >= LIST_CAPACITY) return -1; 
    if (item < 0) return -1;

    // add the item to the list and increase the length
    p_list->items[p_list->len] = item;
    p_list->len++;

    return 0;
}

// Adds an item to the specific position (index) of the list
// Returns 0 if the element is successfully added
// Returns -1 otherwise: 1) the list is full, 2) the item is negative, 3) the index is negative, or 4) the index is bigger than the length
int insert(MyList *p_list, int item, int index)
{
    // return -1 for the four cases
    if (p_list->len >= LIST_CAPACITY) return -1; 
    if (item < 0) return -1;
    if (index < 0) return -1;
    if (p_list->len < index) return -1;

    // empty the position by moving the elements right
    for (int i_arr = p_list->len; i_arr > index; i_arr--)
    {
        p_list->items[i_arr] = p_list->items[i_arr - 1];
    }

    // insert the item to the position and increase the length
    p_list->items[index] = item;
    p_list->len++;

    return 0;
}

// Returns the biggest item in the list
// Returns -1 if the list is empty
int max(MyList *p_list)
{
    int max_val = -1;

    // loop for the list and find the maximum value
    for (int i_arr = 0; i_arr < p_list->len; i_arr++)
    {
        if (p_list->items[i_arr] > max_val)
        {
            max_val = p_list->items[i_arr];
        }
    }

    return max_val;
}

// Removes and returns an item from the specific position (index) of the list
// Returns -1 if 1) the index is negative 2) the index is not smaller than the length
int pop(MyList *p_list, int index)
{
    // return -1 for the two cases
    if (index < 0) return -1;
    if (p_list->len <= index) return -1;

    int pop_val = p_list->items[index];

    for (int i_arr = index; i_arr < p_list->len; i_arr++)
    {
        p_list->items[i_arr] = p_list->items[i_arr + 1];
    }
    p_list->len--;
    
    return pop_val;
}

// Sorts the list in ascending order 
// Returns 0
int sort(MyList *p_list)
{
    bool quick = true;

    if (quick) // quick sort
    {
        if (p_list->len > 1) quicksort(p_list, 0, p_list->len - 1);
    }
    else // bubble sort
    {
        int temp;
        
        for (int i_arr = 0; i_arr < p_list->len; i_arr++)
        {
            for (int j_arr = 1; j_arr < p_list->len; j_arr++)
            {
                if (p_list->items[j_arr - 1] > p_list->items[j_arr])
                {
                    temp = p_list->items[j_arr - 1];
                    p_list->items[j_arr - 1] = p_list->items[j_arr];
                    p_list->items[j_arr] = temp;
                }
            }
        }
    }
    
    return 0;
}

// Displays the list 
void display(MyList *p_list)
{
    cout << "[ ";
    for (int i_arr = 0; i_arr < p_list->len; i_arr++)
    {
        cout << p_list->items[i_arr] << ", ";
    }
    cout << "]" << endl << endl;
}

// Functions for quicksort

void quicksort(MyList *p_list, int lo, int hi)
{
    int part;
    
    if (lo >= 0 & hi > lo)
    {
        part = partition(p_list, lo, hi);
        quicksort(p_list, lo, part);
        quicksort(p_list, part + 1, hi);
    }
}

int partition(MyList *p_list, int lo, int hi)
{
    int pivot, i_arr, j_arr, temp;
    
    pivot = p_list->items[(lo + hi) / 2];
    i_arr = lo - 1;
    j_arr = hi + 1;

    while (true)
    {
        do i_arr++; while (p_list->items[i_arr] < pivot);
        do j_arr--; while (p_list->items[j_arr] > pivot);
        if (i_arr >= j_arr) return j_arr;
        temp = p_list->items[i_arr];
        p_list->items[i_arr] = p_list->items[j_arr];
        p_list->items[j_arr] = temp;
    }
}