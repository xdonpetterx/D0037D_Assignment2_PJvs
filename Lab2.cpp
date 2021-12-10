#include "lab2lib.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

void main_menu()
{
    cout << "Menu: " << endl;
    cout << "1: Task 1 - SortCheck" << endl;
    cout << "2: Task 2 - Palindrome checker " << endl;
    cout << "3: Task 3 - Print 2D array with rows/columns" << endl;
    cout << "4: Task 4 - Swap sort (pass-by-reference)" << endl;
    cout << "5: Task 5 - Shrink" << endl;
    cout << "6: Task 6 - Vector database" << endl;
    cout << "-1: Exit " << endl;
    cout << "Which task would you like to run? ";
}

void task_1()
{
    cout << "\n***Task 1 - SortCheck***" << endl;
    cout << "This function takes an integer array as a parameter and returns" << endl;
    cout << "true (true = 1) if the array is sorted in an ascending order," << endl;
    cout << "otherwise false (false = 0)." << endl;

    int size;
    cout << "Enter the size of the array: ";
    if (!(cin >> size))
    {
        cout << "Incorrect input.";
        cin.clear();
        (void)cin.ignore(INT64_MAX, '\n');
        task_1();
    }
    cin.clear();
    (void)cin.ignore(INT64_MAX, '\n');
    int arr[50];
    cout << "Time to fill the array. Enter numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cin.clear();
    (void)cin.ignore(INT64_MAX, '\n');
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nReturn value from function (1 = true, 0 = false): ";
    cout << is_sorted(arr, size) << endl << endl;
}

void task_2()
{
    cin.clear();
    (void)cin.ignore(INT64_MAX, '\n');
    cout << "\n***Task 2 - Palindrome checker***" << endl;
    cout << "Palindrome is a character array that remains the same when reversed," << endl;
    cout << "(for example madam or dad)." << endl;
    cout << "This function takes a char array as a parameter and returns" << endl;
    cout << "true (true = 1) if the array is a palindrome, otherwise false (false = 0)." << endl;
    cout << "Time to fill the array. Enter a word: ";
    char arr[50];
    if (!(cin >> arr))
    {
        cout << "Incorrect input.";
        cin.clear();
        (void)cin.ignore(INT64_MAX, '\n');
        task_2();
    }
    else
    {
        cout << "Word: " << arr << endl;
        cout << "Return value from function (1 = true, 0 = false): ";
        cout << is_palindrome(arr) << endl << endl;
    }
    cin.clear();
    (void)cin.ignore(INT64_MAX, '\n');
}

void task_3()
{
    cout << "\n***Task 3 - Print 2D array with rows/columns***" << endl;
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int columns;
    cout << "Enter number of columns: ";
    cin >> columns;
    int* arr2d = new int[rows * columns];
    array_rows_cols((int*)arr2d, rows, columns);
    delete[] arr2d;
    arr2d = nullptr;
}

void task_4()
{
    cout << "\n***Task 4 - Swap sort (pass-by-reference)***" << endl;
    cout << "This function takes three integers (a, b, and c) and then sorts them in" << endl;
    cout << "either ascending or descending order." << endl;
    int a;
    do
    {
        cout << "Give a (0 to quit): ";
        while (!(cin >> a))
        {
            cout << "Incorrect input. Try again: ";
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
        }
        if (a == 0)
        {
            cout << "Bye bye!\n";
            cout << endl;
            break;
        }
        else
        {
            int b; int c; bool order;
            cout << "Give b: ";
            while (!(cin >> b))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            cout << "Give c: ";
            while (!(cin >> c))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            cout << "\nSort ascending/descending (1/0): ";
            while (!(cin >> order))
            {
                cout << "Incorrect input. Try again: ";
                cin.clear();
                (void)cin.ignore(INT64_MAX, '\n');
            }
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            swap_sort(a, b, c, order);
            cout << a << " " << b << " " << c << endl;
        }
    } while (a != 0);
}

void task_5()
{
    cout << "\n***Task 5 - Shrink***" << endl;
    cout << "This function takes an integer array as input and then combines adjacent" << endl;
    cout << "integers and assigns zeroes to the leftover indices. The function will" << endl;
    cout << "then print the input array following by the output array\n" << endl;
    int arr[50]{ 0 };
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    while (size < 1)
    {
        cin.clear();
        (void)cin.ignore(INT64_MAX, '\n');
        cout << "Size has to be 1 or greater. Try again: ";
        cin >> size;
    }
    cin.clear();
    (void)cin.ignore(INT64_MAX, '\n');
    cout << "Enter array elements (integers): ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Input array: ";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << endl;
    shrink_array(arr, size);
    cout << "Output array: ";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << endl;
    cin.clear();
    cin.ignore(INT64_MAX, '\n');
    cout << endl;
}

void database_menu()
{
    cout << "MENU: " << endl;
    cout << "  1. initialize database" << endl;
    cout << "  2. insert" << endl;
    cout << "  3. search" << endl;
    cout << "  4. delete" << endl;
    cout << "  5. print" << endl;
    cout << "  6. quit" << endl;
    cout << endl;
    cout << "Make your choice (1-6): ";
}

void t6_initialize_database(vector<string>& vec)
{
    char input;
    //initialize database
    cout << "Are you sure? (y/n): ";
    cin >> input;
    if (input == 'y')
    {
        vec.clear();
    }
    else if (input != 'y' && input != 'n')
    {
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        (void)cin.ignore(INT64_MAX, '\n');
        t6_initialize_database(vec);
    }
    cout << endl;
}

void t6_insert_names(vector<string>& vec)
{
    string name;
    do
    {
        cout << "Enter name(s) or q to go back to menu: ";
        cin >> name;
        if (name == "q" || name == "Q")
        {
            break;
        }
        else
        {
            // Converts name to lower case
            std::for_each(name.begin(), name.end(), [](char& c) {
                c = ::tolower(c);
                });
            vec.push_back(name);
        }
    } while (name != "q" || name != "Q");
    cout << "Number of names in database: " << vec.size() << endl << endl;
}

void t6_search_string(vector<string>& vec)
{
    //search
    if (vec.empty())
    {
        cout << "Vector is empty. You need to add names to vector before using search." << endl;
    }
    else
    {
        string search_term;
        cout << "Enter search term: ";
        cin >> search_term;

        // Converts search_term to lower case
        std::for_each(search_term.begin(), search_term.end(), [](char& c) {
            c = ::tolower(c);
            });

        for (auto iterator = vec.begin(); iterator != vec.end(); iterator++) {
            if ((*iterator).find(search_term) != std::string::npos) {
                cout << *iterator << " ";
            }
        }
        cout << endl << endl;
    }
}

void t6_delete_name(vector<string>& vec)
{
    //delete;
    if (vec.empty())
    {
        cout << "Vector is empty. You need to add names to vector before using delete." << endl;
    }
    else
    {
        string search_term;
        cout << "Enter term to be deleted: ";
        cin >> search_term;

        auto it = find(vec.begin(), vec.end(), search_term);
        int vec_position;
        if (it != vec.end())
        {
            vec_position = it - vec.begin();
            vec.erase(vec.begin() + vec_position);
        }
    }
    cout << "Number of names in database: " << vec.size() << endl << endl;
}

void t6_print_database(const vector<string>& vec)
{
    //print
    cout << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;
}

void task_6()
{
    cout << "\n***Task 6 - Vector database***" << endl;
    cout << "This is a simple database system that stores names of persons in a vector." << endl;
    int input;
    vector<string> vec;
    do
    {
        database_menu();
        while (!(cin >> input))
        {
            cout << "Incorrect input.\n";
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            main_menu();
        }
        switch (input)
        {
        case 1: t6_initialize_database(vec);
            break;
        case 2: t6_insert_names(vec);
            break;
        case 3: t6_search_string(vec);
            break;
        case 4: t6_delete_name(vec);
            break;
        case 5: t6_print_database(vec);
            break;
        case 6: cout << "Goodbye!" << endl;
            break;
        default: cout << "Sorry, there is no such task!" << endl;
            break;
        }
    } while (input != 6);
}

int main()
{
    int input;
    do
    {
        main_menu();
        while (!(cin >> input))
        {
            cout << "Incorrect input.\n";
            cin.clear();
            (void)cin.ignore(INT64_MAX, '\n');
            main_menu();
        }
        switch (input)
        {
        case 1: task_1();
            break;
        case 2: task_2();
            break;
        case 3: task_3();
            break;
        case 4: task_4();
            break;
        case 5: task_5();
            break;
        case 6: task_6();
            break;
        case -1: cout << "Goodbye!" << endl;
            break;
        default: cout << "Sorry, there is no such task!" << endl;
            break;
        }
    } while (input != -1);
}