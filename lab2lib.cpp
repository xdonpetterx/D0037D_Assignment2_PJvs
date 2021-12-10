#include "lab2lib.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;

bool is_sorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool is_palindrome(char arr[])
{
    int j = strlen(arr) - 1;
    for (int i = 0; i < j; i++)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        j--;
    }
    return true;
}

void array_rows_cols(int* arr2d, int rows, int columns)
{
    srand(time(0));
    vector<int>c_sums;
    vector<int>r_sums;
    int total_c_sum = 0;
    int total_r_sum = 0;

    for (int i = 0; i < rows; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < columns; j++)
        {
            *(arr2d + i * columns + j) = rand() % 10;
            cout << *(arr2d + i * columns + j) << "  ";
            row_sum += *(arr2d + i * columns + j);
        }
        cout << " " << row_sum << endl;
        r_sums.push_back(row_sum);
    }
    for (int i = 0; i < columns; i++) {
        int column_sum = 0;
        for (int j = 0; j < rows; j++) {
            column_sum += *(arr2d + j * rows + i); //hopefully this works
        }
        c_sums.push_back(column_sum);
    }
    for (int item : c_sums) {
        cout << item << " ";
        total_c_sum += item;
    }
    for (int item : r_sums) {
        total_r_sum += item;
    }
    cout << " " << total_r_sum + total_c_sum << endl << endl;
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap_sort(int& a, int& b, int& c, bool& order)
{
    if (order == 1)
    {
        while (a > b || b > c)
        {
            if (a > b)
            {
                swap(a, b);
            }
            else if (b > c)
            {
                swap(b, c);
            }
        }
    }
    else if (order == 0)
    {
        while (a < b || b < c)
        {
            if (a < b)
            {
                swap(a, b);
            }
            else if (b < c)
            {
                swap(b, c);
            }
        }
    }
    else
    {
        cout << "Incorrect input for sorting! Please input a correct value." << endl;
        cout << "Sort ascending/descending (1/0): ";
        cin >> order;
        swap_sort(a, b, c, order);
    }
}

void shrink_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        arr[i] = arr[i] + arr[i + 1];
        //delete arr[i + 1];
        for (int j = i + 1; j < size + (size / 2) - 1; j++)
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}