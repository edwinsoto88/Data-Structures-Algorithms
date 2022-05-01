#include <iostream> //input and output
#include <vector>   //library to use vectors
#include <fstream>  //library for file read and write
#include <sstream>  //library for sstream
#include <ctime>    //library for time functionalities
#include <iomanip>
#include <algorithm>

using namespace std;

/*
    Swap function to swap two elements
*/
void swap(int *elem1, int *elem2)
{
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

/******************* Insertion Sort START *******************************/
void InsertionSort(vector<int> &vec)
{

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        auto const insert = upper_bound(vec.begin(), it, *it);

        rotate(insert, it, it + 1);
    }

    /*
        for (size_t i = 1; i < vec.size(); i++)
        {
            int value = vec[i];
            int j = i-1;

            while (j >= 0 && vec[j] > value)
            {
                vec[j + 1] = vec[j]; //shift the element
                j--;
            }
            vec[j + 1] = value;
        }
    */
}
/******************* Insertion Sort END *********************************/

/******************* Selection Sort START *******************************/
void SelectionSort(vector<int> &vec)
{
    // Traverse through vector array
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t min_val = i;

        for (size_t j = i + 1; j < vec.size(); j++)
        {
            // Find the smallest element in the array
            if (vec[j] < vec[min_val])
            {
                // Exchange it with the element in the first pos.
                min_val = j;
            }
        }
        // swap the smallest element with the second pos.
        swap(&vec[min_val], &vec[i]);
    }
}
/******************* Selection Sort END ********************************/

/******************* HEAP SORT START ***********************************/
void Heapify(vector<int> &vec, int num, int i)
{
    int largest = i; // initialize max as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left child is larger than root
    if (left < num && vec[left] > vec[largest])
        largest = left;

    // if right child is larger than max
    if (right < num && vec[right] > vec[largest])
        largest = right;

    // if max is not root
    if (largest != i)
    {
        // swapping
        swap(&vec[i], &vec[largest]);

        // recursive heapify
        Heapify(vec, num, largest);
    }
}

void HeapSort(vector<int> &vec)
{
    int size = vec.size();

    // build heapSort
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(vec, size, i);
    }

    // one by one extract an element from heapSort
    for (int i = size - 1; i >= 0; i--)
    {
        // Swapping
        swap(&vec[0], &vec[i]);

        // recursive heapify
        Heapify(vec, i, 0);
    }
}
/******************* HEAP SORT END ************************************/

/******************* MERGE SORT START ************************************/

void Merge(vector<int> &vec, vector<int> &temp, int left, int middle, int right)
{
    // Declare variables
    int i;
    int left_end;
    int size;
    int temp_pos;

    left_end = middle - 1;   // set our variable to the left end of our first half of the vector array
    temp_pos = left;         // create a temprary variable and start at the beggining
    size = right - left + 1; // calculates the size of the vector array

    while ((left <= left_end) && (middle <= right))
    {
        if (vec[left] <= vec[middle])
        {
            temp[temp_pos] = vec[left];
            temp_pos++;
            left++;
        }
        else
        {
            temp[temp_pos] = vec[middle];
            temp_pos++;
            middle++;
        }
    }

    while (left <= left_end)
    {
        temp[temp_pos] = vec[left];
        left++;
        temp_pos++;
    }

    while (middle <= right)
    {
        temp[temp_pos] = vec[middle];
        middle++;
        temp_pos++;
    }

    for (int i = 0; i < size; i++)
    {
        vec[right] = temp[right];
        right--;
    }
}

void MergeSort(vector<int> &vec, vector<int> &temp, int left, int right)
{
    int middle;
    if (right > left)
    {
        middle = (right + left) / 2;               // calculates the middle of the unsorted array
        MergeSort(vec, temp, left, middle);        // recursive call to sort the left half of the vector array
        MergeSort(vec, temp, middle + 1, right);   // recursive call to sort the right half of the vector array
        Merge(vec, temp, left, middle + 1, right); // merges the two halves together
    }
}
/******************* MERGE SORT END ************************************/

/******************* Quick Sort START *********************************/
int partition(vector<int> &vec, int low, int high)
{
    int pivot = high;

    int i = low;

    for (int j = low; j < high; ++j)
    {
        if (vec[j] <= vec[pivot])
        {
            swap(&vec[i], &vec[j]);
            ++i;
        }
    }
    swap(&vec[i], &vec[pivot]);

    return (i);
}

void QuickSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        // Split the vector array
        int par = partition(vec, low, high);

        // Sort the left part of the vector array
        QuickSort(vec, low, par - 1);

        // Sort the right part of the vector array
        QuickSort(vec, par + 1, high);
    }
}
/******************* Quick Sort END ***********************************/

void printMenu()
{
    cout << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|             M E N U              |" << endl;
    cout << "|                                  |" << endl;
    cout << "|   (1) Insertion Sort             |" << endl;
    cout << "|   (2) Selection Sort             |" << endl;
    cout << "|   (3) Heap Sort                  |" << endl;
    cout << "|   (4) Merge Sort                 |" << endl;
    cout << "|   (5) Quick Sort                 |" << endl;
    cout << "|   (6) Exit                       |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << endl;
    cout << "Please select from the following: ";
}

int main()
{
    // variables
    int choice, size_n;
    string line;
    vector<int> arr;
    vector<int> temp;
    clock_t quickSort_start, quickSort_end, insert_start, insert_end, heap_start, heap_end, select_start, select_end, merge_start, merge_end;
    double time_spent;

    ifstream fileIn("data_sort1.txt"); // opens data_sort.txt

    // checks if the file fails to open
    if (fileIn.fail())
    {
        cout << "[Error] File failed to open." << endl;
        exit(0);
    }

    // Gets all the data from the data file and stores it into the vector arr
    while (getline(fileIn, line))
    {
        stringstream is(line);
        while (is >> size_n)
        {
            arr.push_back(size_n);
            temp.push_back(0); // pushes
        }
    }

    // Print the menu for the user to see, and ask for a choice
    printMenu();
    cin >> choice;

    while (choice != 6)
    {

        if (choice == 1)
        {
            cout << "[INFO] You have choosen Insertion Sort option." << endl;
            insert_start = clock();
            InsertionSort(arr);
            insert_end = clock();

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            time_spent = 1000.0 * (insert_end - insert_start) / CLOCKS_PER_SEC;

            cout << "-------------------------------------------" << endl;
            cout << "|                | Random Vector          |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|  Insertion Sort    |     " << setprecision(5) << time_spent << " ms               |" << endl;
            cout << "-------------------------------------------" << endl;

            printMenu();
            cin >> choice;
        }
        else if (choice == 2)
        {
            cout << "[INFO] You have choosen Selection Sort option." << endl;
            select_start = clock();
            SelectionSort(arr);
            select_end = clock();

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            time_spent = 1000.0 * (select_end - select_start) / CLOCKS_PER_SEC;

            cout << "-------------------------------------------" << endl;
            cout << "|                | Random Vector          |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|  Selection Sort    |     " << setprecision(5) << time_spent << " ms               |" << endl;
            cout << "-------------------------------------------" << endl;

            printMenu();
            cin >> choice;
        }
        else if (choice == 3)
        {
            cout << "[INFO] You have choosen Heap Sort option." << endl;
            heap_start = clock();
            HeapSort(arr);
            heap_end = clock();

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            time_spent = 1000.0 * (heap_end - heap_start) / CLOCKS_PER_SEC;

            cout << "-------------------------------------------" << endl;
            cout << "|                | Random Vector          |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|  Heap Sort    |     " << setprecision(5) << time_spent << " ms               |" << endl;
            cout << "-------------------------------------------" << endl;

            printMenu();
            cin >> choice;
        }
        else if (choice == 4)
        {
            cout << "[INFO] You have choosen Merge Sort option." << endl;
            merge_start = clock();
            MergeSort(arr, temp, 0, arr.size() - 1);
            merge_end = clock();

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            time_spent = 1000.0 * (merge_end - merge_start) / CLOCKS_PER_SEC;

            cout << "-------------------------------------------" << endl;
            cout << "|                | Random Vector          |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|  Heap Sort    |     " << setprecision(5) << time_spent << " ms               |" << endl;
            cout << "-------------------------------------------" << endl;

            printMenu();
            cin >> choice;
        }
        else if (choice == 5)
        {
            cout << "[INFO] You have choosen Quick Sort option." << endl;
            quickSort_start = clock();
            QuickSort(arr, 0, arr.size() - 1);
            quickSort_end = clock();

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            time_spent = 1000.0 * (quickSort_end - quickSort_start) / CLOCKS_PER_SEC;

            cout << "-------------------------------------------" << endl;
            cout << "|                | Random Vector          |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|  Quick Sort    |     " << setprecision(5) << time_spent << " ms               |" << endl;
            cout << "-------------------------------------------" << endl;

            printMenu();
            cin >> choice;
        }
        else if (choice == 6)
        {
            cout << "[INFO] You have exited out of the program." << endl;
            exit(0);
        }
        else
        {
            cout << "[ERROR] You chose a wrong option, now exiting program." << endl;
            exit(0);
        }
    }

    return 0;
}
