#include <iostream>
#include <string>
using namespace std;

int main() {
    // Array of city names
    std::string cities[4] = {"New york", "los angles", "chicago", "New jersey"};

    // Loop through the array and find cities that start with "New"
    cout << "Cities that start with 'N' are:" << endl;
    for(int i = 0; i < 4; i++) {
        if(cities[i].substr(0, 1) == "N") {
            cout << cities[i] << endl;
        }
    }

    return 0;
}
