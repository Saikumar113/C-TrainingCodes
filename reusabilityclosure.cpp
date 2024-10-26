#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;


std::function<bool(const string&)> checkStringStartWithAny(const string& startWith){
    std::function<bool(const string&)> predicate=[startWith](const string& item){
		return  !item.empty() && item.substr(0, 1) ==startWith;
    };
    return predicate;
}

vector<string> filter(vector<string> source,std::function<bool(const string&)> predicateFunObj){
       std::vector<std::string> filteredStrings;
		for (const string& item : source) {
        // Check if the city starts with "New"
			if (predicateFunObj(item)) {
            filteredStrings.push_back(item);
		}
    }
    return filteredStrings;
}


int main() {
    // Create an array of cities
    vector<std::string> cities = {"New York", "Los Angeles", "Chicago", "New Jersey"};

    // Create a vector to hold cities that start with "New"
    std::function<bool(const string&)> predicate=checkStringStartWithAny("N");
  vector<string> newCities=filter(cities,predicate);
  std::cout << "Cities that start with 'New':" << std::endl;
    for (const string& newCity : newCities) {
        std::cout << newCity << std::endl;
    }
    
     predicate=checkStringStartWithAny("C");
     
     newCities=filter(cities,predicate);
  std::cout << "Cities that start with 'New':" << std::endl;
    for (const string& newCity : newCities) {
        std::cout << newCity << std::endl;
    }

    return 0;
}
