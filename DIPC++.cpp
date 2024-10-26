class IICEngine{
	public:
			//pure virtual method;
			virtual void crank()=0;
			virtual void halt()=0;
}

//Low Level Module, Service
//VericoreEngine implemets contract i.e IICEngine
class VericoreEngine:public IICEngine{
	public:
		void crank(){}
		void halt(){}

};
//High Level Module , consumer,client
class TataCar{
	IICEngine* engine;
	public:
		void start(){
			engine->crank();
		}	
		void stop(){
			engine->halt();
		}

};

int main(){
		TataCar _hexaIstance;
		_hexaIstance.start();
		_hexaIstance.stop();
}
