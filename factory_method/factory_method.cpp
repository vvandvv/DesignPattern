/**
 * ��������ģʽ
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
// ���������һ����
class AudiCar : public iCar {
	public:
		void run() {
			cout<<"AudiCar running."<<endl;
		}
}; 

//============================================================
// ��Ӧ��������һ�� factory �࣬�������޸���ǰ�Ĵ��� 
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
//�ͻ�����ĸı䡣 
	fac = new AudiCarFactory();
	car = fac->createCar();
	car->run(); 
	delete fac;
	delete car;
//============================================================
//���Կ���������ͻ�ͨ���ӿڵ��� Car �ķ����������������ı� 
	return 0; 
}
