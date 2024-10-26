#include <iostream>
using namespace std;
class IICEngine{
	public:
			//pure virtual method;
			virtual void crank()=0;
			virtual void halt()=0;
};

//Low Level Module, Service
//VericoreEngine implemets contract i.e IICEngine
class VericoreEngine:public IICEngine{
	public:
		void crank(){ cout<<"Vericore Engine Cranked"<<endl;}
		void halt(){cout<<"Vericore Engine Halted"<<endl;}

};
//High Level Module , consumer,client
class TataCar{
	IICEngine* _engine;
	public:
		TataCar(IICEngine* engine): _engine{engine}{}
		void start(){
			_engine->crank(); //interaction /delegation
		}	
		void stop(){
			_engine->halt();
		}

};

void releaseCode(){
    	VericoreEngine _vericoreEngine;
		TataCar _hexaIstance {&_vericoreEngine};
		_hexaIstance.start();
		_hexaIstance.stop();
}
class MockICEEngine:public IICEngine{
    public:
    int crankCallCount=0;
    int haltCallCount=0;
    void crank(){
        this->crankCallCount+=1;
        cout<<"Mock Engine Cranked"<<endl;}
	void halt(){
	this->haltCallCount++;
	cout<<"Mock Engine Halted"<<endl;
    
}
};
void testCode(){
        MockICEEngine _mockEngine;
        TataCar _hexaInstance{ &_mockEngine};
        _hexaInstance.start();
        //ASSERT_EQ(_mockEngine.crankCallCount,1);
        cout<< (_mockEngine.crankCallCount==1)<<endl;
        
}
int main(){
testCode();	
}
