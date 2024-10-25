
#include <iostream>
using namespace std;
template<typename T>
void bubbleSort(T arr[], int n) {
    // Loop through all elements of the array
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place, so no need to check them
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Sensor{
        int _cost;
        public:
            Sensor(int cost ){
                this->_cost=cost;
            }
            int getCost()const { return this->_cost;} 
            bool operator>(const Sensor& s2) const{
                cout<<"Sensore operator> invoked"<<endl;
	           return this->getCost() > s2.getCost();
	        }
	        friend ostream& operator<<(ostream& out,const Sensor& sensor){
	            
	            out<<sensor.getCost()<<endl;
	            return out;
	        }
	        
};
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    printArray(arr, n);

    bubbleSort<int>(arr, n);

    cout << "Sorted array: \n";
    printArray<int>(arr, n);
	Sensor s1(100);
	Sensor s2(300);
	Sensor s3(50);
	Sensor s4(150);
	
	Sensor sensors[4]= {s1,s2,s3,s4};
	bubbleSort<Sensor>(sensors,4);
	printArray<Sensor>(sensors,4);
    return 0;
}

	
