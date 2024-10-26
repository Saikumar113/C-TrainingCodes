
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
class P:public virtual  D{
	public:

		P():D(100){
				cout<<"P Constructed"<<endl;
		}
		~P(){
				cout<<"P Destructed"<<endl;
		}
}; //Printer
class S:public virtual D{
	public:
		S():D(200){
				cout<<"S Constructed"<<endl;
		}
		~S(){
				cout<<"S Destructed"<<endl;
		}
}; //Scanner
class PS:public P,public S{
		public:
		PS():D::D(1000){
				cout<<"PS Constructed"<<endl;
		}
		~PS(){
				cout<<"PS Destructed"<<endl;
		}


}; //PrinterScanner

int main(){

 PS psInstance;
}
