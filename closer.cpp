
#include <iostream>
#include <functional>
using namespace std;
std::function<void()>  test(int arg){
	
			//Lamda
			std::function<void()> callBack=[arg]()-> void {
													cout<<arg<<endl;
												 };
			return callBack;
}


int main(){
 std::function<void()>  callback=test(10);
 callback();
 
 callback=test(20);
 callback();
 
 callback=test(30);
 callback();
 }
