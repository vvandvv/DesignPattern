/**
 * 工厂方法模式
 */
 
#include <iostream>
using std::cout; using std::endl;
#include <cassert>

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

class iFactory {
	public:
		virtual iCar *createCar() = 0;
};

class BenzCarFactory : public iFactory {
	public:
		iCar *createCar() {
			return new BenzCar();
		}
};

class BmwCarFactory : public iFactory {
	public:
		iCar *createCar() {
			return new BmwCar();
		}
};

//============================================================
// 如果新增加一辆车
class AudiCar : public iCar {
	public:
		void run() {
			cout<<"AudiCar running."<<endl;
		}
}; 

//============================================================
// 对应的是增加一个 factory 类，而不是修改以前的代码 
class AudiCarFactory : public iFactory {
	public:
		iCar *createCar() {
			return new AudiCar();
		}
};

int main() {
	iFactory *fac = new BenzCarFactory();
	iCar *car = fac->createCar();
	car->run();
	delete fac;
	delete car;
	cout<<"========================================="<<endl;
//============================================================
//客户代码的改变。 
	fac = new AudiCarFactory();
	car = fac->createCar();
	car->run(); 
	delete fac;
	delete car;
//============================================================
//可以看到，如果客户通过接口调用 Car 的方法，代码根本无需改变 
	return 0; 
}
