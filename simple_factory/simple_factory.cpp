/**
 * �򵥹���ģʽ
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
//����һ����
class AudiCar : public iCar {
	public:
		void run() {
			cout<<"AudiCar running."<<endl;
		}
}; 

//==========================================
//��Ҫ�����µ� enum ���
enum CarType2 {
	AUDI=2 													// new 
};
//========================================
//��Ҫ�ı�ԭ���� Factory ��
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
//�ͻ�����ĸı�
	Factory2 *fac2 = new Factory2();
	car = fac2->createCar(AUDI);							//changed!!!
	assert( car!=NULL );
	car->run();
	delete fac2;
	delete car; 
//==========================================
//�ͻ�������Ҫ�����ģ��ͻ���Ҫ�������������ʶ�������ڴ����г����� AUDI �ı�ʶ�� 
	return 0; 
}
