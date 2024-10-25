#include <iostream>
#include <cstring> // For string manipulation
using namespace std;

// Custom Dictionary class using pointers for keys and values
template <typename K, typename V>
class Dictionary {
private:
    K* keys;         // Pointer to the array of keys
    V* values;       // Pointer to the array of values
    int size;        // Number of elements in the dictionary
    int capacity;    // Maximum size of the dictionary

public:
    // Constructor to initialize the dictionary with a specified capacity
    Dictionary(int cap = 10) {
        size = 0;
        capacity = cap;
        keys = new K[capacity];         // Dynamically allocate memory for keys
        values = new V[capacity];       // Dynamically allocate memory for values
    }

    // Destructor to free dynamically allocated memory
    ~Dictionary() {
        delete[] keys;   // Free the memory for keys
        delete[] values; // Free the memory for values
    }

    // Method to add key-value pairs to the dictionary
    void add(const K& key, const V& value) {
        if (size < capacity) {
            keys[size] = key;       // Store the key in the dynamically allocated array
            values[size] = value;   // Store the value in the dynamically allocated array
            size++;  // Increment the size
        } else {
            cout << "Dictionary is full!" << endl;
        }
    }

    // Overloaded subscript operator for accessing values by key
    V operator[](const K& key) const {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return values[i];  // Return the value associated with the key
            }
        }
        throw out_of_range("Key not found!");  // Handle case where key is not found
    }

    // Friend function to overload the output stream operator for printing
    friend ostream& operator<<(ostream& os, const Dictionary& dict) {
        os << "Key : Value" << endl;
        for (int i = 0; i < dict.size; i++) {
            os << "   " << dict.keys[i] << " : " << dict.values[i] << endl;  // Print key-value pairs
        }
        return os;
    }
};

int main() {
    // Create a Dictionary object and add key-value pairs
    Dictionary<int, string> deviceCodeMap(4);
    deviceCodeMap.add(1, "D1");
    deviceCodeMap.add(2, "D2");
    deviceCodeMap.add(3, "D3");
    deviceCodeMap.add(4, "D4");

    // Access and print the value for key 2
    string deviceName = deviceCodeMap[2];
    cout << deviceName << endl;  // Output: D2

    // Dump all the items from the dictionary
    cout << deviceCodeMap;

    return 0;
}
