/*
    Name: Edwin Soto-Villela
    Description: For our open addressing table, all of the elements are stored in the hash table.
    So if we need more keys we would have to increase the size of the table to do so. And in short
    the table may become full.
*/

#include <iostream>
#include <list>
using namespace std;

class hashTable
{
    static const int TableCapacity = 10000;       // Sets the size of the Table size
    list<pair<int, string>> table[TableCapacity]; // initializes the empty table with the table capacity
public:
    bool isEmpty();
    int genHashFunc(int key);
    void insert(int key, string value);
    void remove(int key);
    string search(int key);
    void printHashTable();
};

/*
    Function that checks if the hash map is empty or not
*/
bool hashTable::isEmpty()
{
    int sum{};
    for (int i{}; i < TableCapacity; i++)
    {
        sum += table[i].size();
    }

    if (sum == 0)
    {
        return true;
    }
    return false;
}

/*
    Function that generates a unique hash for each item that is entered.
    This function is using linear
*/
int hashTable::genHashFunc(int key)
{
    return key % TableCapacity; // Key: 95 % 10,000 -> it would return 95
}

/*
    Insert function that inserts a key and value into an empty slot
*/
void hashTable::insert(int key, string value)
{
    int hashVal = genHashFunc(key);
    auto &block = table[hashVal];
    auto beginItr = begin(block);
    bool keyExists = false;

    // if there is a key that already exists, replace it with a new value
    for (; beginItr != end(block); beginItr++)
    {
        if (beginItr->first == key)
        {
            keyExists = true;
            beginItr->second = value;
            cout << "The value has been replaced" << endl;
            break;
        }
    }

    // if the key doesn't match with the key that was entered, insert the value in the hash table
    if (!keyExists)
    {
        block.emplace_back(key, value);
    }
    return;
}

/*
    Function that removes data based on the given key entered and
    returns 'The item wasn't in the list' if it wasn't found.
*/
void hashTable::remove(int key)
{
    int hashVal = genHashFunc(key);
    auto &block = table[hashVal];
    auto beginItr = begin(block);
    bool keyExists = false;

    // if there is a key that already exists, erase the value that was found
    for (; beginItr != end(block); beginItr++)
    {
        if (beginItr->first == key)
        {
            keyExists = true;
            beginItr = block.erase(beginItr);
            cout << "Item has been removed." << endl;
            break;
        }
    }
    // if the key entered doesn't exist, return "The item wasn't in the list"
    if (!keyExists)
    {
        cout << "The item wasn't in the list" << endl;
    }
    return;
}

/*
    Function that searches for the key, and if the entered key matches
    with the key in the table, return the vlaue associated with that key.
    Else, return "The key isn't in the list"
*/
string hashTable::search(int key)
{
    int hashVal = genHashFunc(key);
    auto &block = table[hashVal];
    auto beginItr = begin(block);
    bool keyExists = false;

    // if there is a key that already exists, return the vlaue associated with that key
    for (; beginItr != end(block); beginItr++)
    {
        if (beginItr->first == key)
        {
            keyExists = true;
            return beginItr->second;
            break;
        }
    }
    // otherwise, return that the key entered doesn't exist
    if (!keyExists)
    {
        cout << "The item wasn't in the list" << endl;
        exit(0);
    }
}

/*
    Function to print out the keys and values in our closed addressing hash table
*/
void hashTable::printHashTable()
{
    for (int i{}; i < TableCapacity; i++)
    {
        if (table[i].size() == 0)
            continue;

        auto beginItr = table[i].begin();
        for (; beginItr != table[i].end(); beginItr++)
        {
            cout << "Key: " << beginItr->first << " | Value: " << beginItr->second << endl;
            cout << "----------------------" << endl;
        }
    }
    return;
}

int main()
{
    hashTable ht; // Create a hash object

    if (ht.isEmpty())
    {
        cout << "Hash Table is empty, All good!" << endl;
    }
    else
    {
        cout << "There's an error that occured, double check you entered the correct key/string!!!" << endl;
    }

    ht.insert(904, "Bob");
    ht.insert(206, "Jim");
    ht.insert(555, "Edwin");
    ht.insert(940, "Soto");
    ht.insert(216, "David");
    ht.insert(867, "Jose");

    cout << endl;

    ht.printHashTable();

    ht.remove(216);
    ht.remove(665);

    if (ht.isEmpty())
    {
        cout << "There's an error that occured, double check you entered the correct key/string!!!" << endl;
    }
    else
    {
        cout << "Hash Table is not empty, All good!" << endl;
    }

    int keySearch;
    cout << "Enter the key you want to search for: ";
    cin >> keySearch;

    string searchedItem = ht.search(keySearch);

    cout << "The item searched for is " << searchedItem << endl;

    return 0;
}
