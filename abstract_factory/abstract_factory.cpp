/**
 * 抽象工厂模式
 */
 
#include <iostream>
using std::cout; using std::endl;
#include <cassert>

class iEngine {
	public:
		virtual void start() = 0;
}; 

class BenzEngine : public iEngine {
	public:
		void start() {
			cout<<"BenzEngine started."<<endl;
		}
};

class BmwEngine : public iEngine {
	public:
		void start() {
			cout<<"BmwEngine started."<<endl;
		}
};

class iDoor {
	public:
		virtual void close() = 0;
};

class BenzDoor : public iDoor {
	public:
		void close() {
			cout<<"BenzDoor closed."<<endl;
		}
};

class BmwDoor : public iDoor {
	public:
		void close() {
			cout<<"BmwDoor closed."<<endl;
		}
};

class iFactory {
	public:
		virtual iEngine *createEngine() = 0;
		virtual iDoor *createDoor() = 0;
};

class BenzFactory : public iFactory {
	public:
		iEngine *createEngine() {
			return new BenzEngine();
		}
		iDoor *createDoor() {
			return new BenzDoor();
		}
};

class BmwFactory : public iFactory {
	public:
		iEngine *createEngine() {
			return new BmwEngine();
		}
		iDoor *createDoor() {
			return new BmwDoor();
		}
};

class Car {
	private:
		iDoor 		*door;
		iEngine		*engine;
	public:
		Car(iDoor *adoor=NULL, iEngine *aengine=NULL) 
			: door(adoor), engine(aengine) {
			}
		~Car() {
			if(door) delete door;
			if(engine) delete engine;
		}
	public:
		void run() {
			assert(door!=NULL);
			door->close();
			assert(engine!=NULL);
			engine->start();
			cout<<"Car running."<<endl;
		}
};

//============================================
//增加一个部件
class iBelt {
	public:
		virtual void fasten() = 0;
}; 

class BenzBelt : public iBelt {
	public:
		void fasten() {
			cout<<"BenzBelt fastened."<<endl;
		}
};

class BmwBelt : public iBelt {
	public:
		void fasten() {
			cout<<"BmwBelt fastened."<<endl;
		}
};

//============================================
//增加的工厂代码（一） 
class iFactory2 {
	public:
		virtual iEngine *createEngine() = 0;
		virtual iDoor *createDoor() = 0;
		virtual iBelt *createBelt() = 0;						// new
};

class BenzFactory2 : public iFactory2 {
	public:
		iEngine *createEngine() {
			return new BenzEngine();
		}
		iDoor *createDoor() {
			return new BenzDoor();
		}
		iBelt *createBelt() {									// new
			return new BenzBelt();								// new
		}
};

class BmwFactory2 : public iFactory2 {
	public:
		iEngine *createEngine() {
			return new BmwEngine();
		}
		iDoor *createDoor() {
			return new BmwDoor();
		}
		iBelt *createBelt() {									// new
			return new BmwBelt();								// new
		}
};

//=============================================
//用户代码的改变（一） 
class Car2 {
	private:
		iDoor 		*door;
		iEngine		*engine;
		iBelt       *belt; 
	public:
		Car2(iDoor *adoor=NULL, iBelt *abelt=NULL, iEngine *aengine=NULL) 
			: door(adoor), belt(abelt), engine(aengine) {
			}
		~Car2() {
			if(door) delete door;
			if(belt) delete belt;
			if(engine) delete engine;
		}
	public:
		void run() {
			assert(door!=NULL);
			door->close();
			assert(belt!=NULL);
			belt->fasten();
			assert(engine!=NULL);
			engine->start();
			cout<<"Car running."<<endl;
		}
};

//================================================
//增加新的一辆车（二） 
class AudiDoor : public iDoor {
	public:
		void close() {
			cout<<"AudiDoor closed."<<endl;
		}
};

class AudiEngine : public iEngine {
	public:
		void start() {
			cout<<"AudiEngine started."<<endl;
		}
};  

//================================================
//工厂代码更改（二） 
class AudiFactory : public iFactory {
	public:
		iDoor *createDoor() {
			return new AudiDoor();
		}
		iEngine *createEngine() {
			return new AudiEngine();
		}
}; 

int main() {
	iFactory *fac = new BenzFactory();
	iDoor *door = fac->createDoor();
	iEngine *engine = fac->createEngine();
	Car *car = new Car( door, engine );
	assert(car!=NULL);
	car->run();
	delete fac;
	delete car;
	cout<<"========================================="<<endl;
//================================================= 
//用户代码的改变 （一） 
	iFactory2 *fac2 = new BmwFactory2();
	iDoor *door2 = fac2->createDoor();
	iBelt *belt = fac2->createBelt();
	iEngine *engine2 = fac2->createEngine();
	Car2 *car2 = new Car2(door2,belt,engine2);
	assert(car2!=NULL);
	car2->run();
	delete fac2;
	delete car2;
	cout<<"========================================="<<endl;
//=================================================
//增加一个新的部件（一） ，Car 的定义发生改变，也是可以理解的；但对于抽象工厂来说，需要改变接口，结果导致大量原有代码都需要改变！！！ 

//==================================================
//用户代码的改变（二） 
	fac = new AudiFactory();
	door = fac->createDoor();
	engine = fac->createEngine();
	car = new Car( door, engine );
	assert( car!=NULL );
	car->run();
	delete fac;
	delete car;
//===================================================
//增加一辆新车（二），可以看到客户代码不需要做任何改变

	return 0; 
}
