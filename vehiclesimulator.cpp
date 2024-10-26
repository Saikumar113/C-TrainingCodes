// Online C++ compiler to run C++ program online
#include <iostream>
using  namespace std;
//abstarct class
class Vehicle{
    public:
    virtual void start(){ cout<<"Vehicle Started Using Key"<<endl;}
    virtual void drive()=0;//abstract method
     virtual void stop(){ cout<<"Vehicle Turn-off Using Key"<<endl;}
     void revese(){
         cout<<"Vehicle Reverse"<<endl;
     }
};
class Car:public Vehicle{
    public: void start() override {cout<<"Car Vehicle Started Using push button"<<endl;}
    void drive() override {
        cout<<"Car Front Wheel Drive "<<endl;
    }
     void stop() override {cout<<"Car Vehicle turn-off Using push button"<<endl;}
};
class Bus:public Vehicle{
    public :
    void drive() override {
        cout<<"Bus Rear Wheel Drive "<<endl;
    }
    
};
class Truck:public Vehicle{
    void drive() override {
        cout<<"Truck Rear Wheel Drive "<<endl;
    }
};

class VehicleSimulator{
    Vehicle* _vehicle;
	public:
			void select(Vehicle* vehicle){
			    this->_vehicle=vehicle;
			}
			void start(){
			    this->_vehicle->start();
			}
			void drive(){
			    this->_vehicle->drive();
			}
			void reverse(){
			    this->_vehicle->revese();
			}
			void stop(){
			    this->_vehicle->stop();
			}
};

int main(){
		Car lmv;
		Bus bHtv;
		Truck tHtv;
		
		VehicleSimulator simulator;
		simulator.select(&lmv);
		simulator.start(); 
		simulator.drive();
		simulator.reverse();
		simulator.stop();
		
		simulator.select(&bHtv);
		simulator.start(); 
		simulator.drive();
		simulator.reverse();
		simulator.stop();
		
		simulator.select(&tHtv);
		simulator.start(); 
		simulator.drive();
		simulator.reverse();
		simulator.stop();
		
		
		
		
}
