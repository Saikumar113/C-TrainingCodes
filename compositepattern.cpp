
#include <iostream>
using namespace std;
class D{
    private:
        int _id;
	public:
		D(int id):_id{id}{
				cout<<"D Constructed"<<endl;
		}
		~D(){
				cout<<"D Destructed"<<endl;
		}
		
};//Device
class P:public   D{
	public:

		P():D(100){
				cout<<"P Constructed"<<endl;
		}
		~P(){
				cout<<"P Destructed"<<endl;
		}
		void pm(){
		    cout<<"Print Method Invoked"<<endl;
		}
}; //Printer
class S:public  D{
	public:
		S():D(200){
				cout<<"S Constructed"<<endl;
		}
		~S(){
				cout<<"S Destructed"<<endl;
		}
		void sm(){
		    	cout<<"Scan Method Invoked"<<endl;
		}
}; //Scanner
class PS:public D{
        private :
        //Dependency
        P pInstance;
        S sInstance;
    
		public:
		PS():D::D(1000){
				cout<<"PS Constructed"<<endl;
		}
		~PS(){
				cout<<"PS Destructed"<<endl;
		}
		void pm(){
		    //delegation
		    pInstance.pm();
		}
	    void sm(){
	        sInstance.sm();
	    }
		


}; //PrinterScanner

int main(){

 PS psInstance;
 psInstance.pm();
 psInstance.sm();
}
