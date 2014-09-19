/**
 * 简单工厂模式
 */ 

#include <iostream>
using std::cout; using std::endl;
#include <cassert>

enum CarType {
	BENZ=0, BMW=1
};

class iCar {
	public:
		virtual void run() = 0;
};

class BenzCar : public iCar {
	public:
		void run() {
			cout<<"BenzCar running."<<endl;
		}
};

class BmwCar : public iCar {
	public:
		void run() {
			cout<<"BmwCar running."<<endl;
		}
};

class Factory {
	public:
		iCar *createCar( CarType type ) {
			switch( type ) {
				case 0:
					return new BenzCar();
				case 1:
					return new BmwCar();
				default:
					return NULL;
			}
		}
};

//======================================== 
//增加一辆车
class AudiCar : public iCar {
	public:
		void run() {
			cout<<"AudiCar running."<<endl;
		}
}; 

//==========================================
//需要增加新的 enum 类别
enum CarType2 {
	AUDI=2 													// new 
};
//========================================
//需要改变原来的 Factory 类
class Factory2 {
	public:
		iCar *createCar( CarType2 type ) {
			switch( type ) {
				case 0:
					return new BenzCar();
				case 1:
					return new BmwCar();
				case 2:										// new
					return new AudiCar();					// new
				default:
					return NULL;
			}
		}
}; 


int main() {
	Factory *fac = new Factory();
	iCar *car = fac->createCar(BENZ);
	assert( car!=NULL );
	car->run();
	delete fac;
	delete car;
	cout<<"========================================="<<endl;
//==========================================
//客户代码的改变
	Factory2 *fac2 = new Factory2();
	car = fac2->createCar(AUDI);							//changed!!!
	assert( car!=NULL );
	car->run();
	delete fac2;
	delete car; 
//==========================================
//客户代码需要做更改！客户需要对汽车类别有认识，而且在代码中出现了 AUDI 的标识！ 
	return 0; 
}
