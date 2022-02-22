/*
    Design Pattern: Factory Method
*/
#include <iostream>

using namespace std;

/*
    Products:
        - Car is a generic abstract product
        - BMW/Fiat is a concrete product
*/

class Car{
    public:
        virtual void printInfo() = 0;
};

class BMW : public Car{
    public:
        void printInfo() override{
            cout << "This is a BMW" << endl;
        }  
};

class Fiat : public Car{
    public:
        void printInfo() override{
            cout << "This is a Fiat" << endl;
        }  
};

/*
    Factory:
        - CarFactory is a generic abstract factory
        - BMWFactory/FiatFactory
*/

class CarFactory{
    public:
        virtual Car* factory() = 0;
        virtual void processProduct() = 0;
        void printNObj(){
            cout << "Number of created instances are "<< nObject << endl;
        }
    protected:
        int nObject = 0;
};

class BMWFactory : public CarFactory{
    public:
        BMW* factory() override{
            BMW* instance = new BMW();
            ++nObject;
            return instance;
        }

        void processProduct() override{
            BMW* i = this->factory();
            i->printInfo();
            delete i;
        }
};

class FiatFactory : public CarFactory{
    public:
        Fiat* factory() override{
            Fiat* instance = new Fiat();
            ++nObject;
            return instance;
        }

        void processProduct() override{
            Fiat* i = this->factory();
            i->printInfo();
            delete i;
        }
};

void ClientFunction(Car* c){
    //Processing stuff indipendent from which type of car is
    c->printInfo();
}

int main(int argc, char* argv[]){
    CarFactory *ff = new FiatFactory();
    ff->processProduct();
    Car* f = ff->factory(); //this car will be a Fiat;
    ff->printNObj();

    CarFactory *bf = new BMWFactory();
    bf->processProduct();
    Car* b = bf->factory();
    bf->printNObj();

    ClientFunction(f);

    return EXIT_SUCCESS;
}