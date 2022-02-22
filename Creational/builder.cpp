/*
    Design Pattern: Builder
*/

// Build a car and its manual

// =========== PRODUCTS COMPONENTS ===========

class Engine{
    public:
        int power;
        bool isRunning = false;
        void virtual startEngine() = 0;
};

class SportEngine : public Engine{
    public: 
        bool sportMode;
        void startEngine() override{
            isRunning = true;
            sportMode = true;
            power = 1000;
        }

};

class SuvEngine : public Engine{
    public:
        void startEngine() override{
            isRunning = true;
            power = 700;
        }
};

// ============ PRODUCTS ============

class Car{
    public:
        Engine *eng;
        int nSeat;
        float length;
};

class Manual{
    public:
        Engine *engInfo;
        int seat;
        float length;
};

// =============== BUILDERS ===============

class AbstractBuilder{
    public:
        void virtual reset() = 0;
        void virtual setEngine(Engine *) = 0;
        void virtual setSeat(int) = 0;
        void virtual setLength(float) = 0;
};

class CarBuilder : public AbstractBuilder{
    private:
        Car *car;

    public:
        CarBuilder(){
            this->reset();
        }

        void reset() override{
            this->car = new Car();
        }

        void setEngine(Engine * e) override{
            //Some complex stuff
            this->car->eng = e;
        }

        void setSeat(int n) override{
            //Some complex stuff
            this->car->nSeat = n;
        }

        void setLength(float dim) override{
            //Some complex stuff
            this->car->length = dim;
        }

        Car * getResult(){
            Car * res = car;
            reset();
            return res;
        }
};

class ManualBuilder : public AbstractBuilder{
    private:
        Manual *man;

    public:
        ManualBuilder(){
            this->reset();
        }

        void reset() override{
            this->man = new Manual();
        }

        void setEngine(Engine * e) override{
            //Some complex stuff
            this->man->engInfo = e;
        }

        void setSeat(int n) override{
            //Some complex stuff
            this->man->seat = n;
        }

        void setLength(float dim) override{
            //Some complex stuff
            this->man->length = dim;
        }

        Manual * getResult(){
            Manual * res = man;
            reset();
            return res;
        }
};

// =============== DIRECTOR ===============
struct result
{
        Car * car;
        Manual * man;
};

class Director
{
    
    public:
        result* makeSuv(CarBuilder *car_builder, ManualBuilder *man_builder){
            result *res = new result();
            SuvEngine *se = new SuvEngine();
            car_builder->setEngine(se);
            car_builder->setSeat(5);
            car_builder->setLength(100.f);

            res->car = car_builder->getResult();
            
            man_builder->setEngine(se);
            man_builder->setSeat(5);
            man_builder->setLength(100.f);

            res->man = man_builder->getResult();

            return res;
        }

        result* makeSportive(CarBuilder *car_builder, ManualBuilder *man_builder){
            result *res = new result();
            SportEngine *se = new SportEngine();
            car_builder->setEngine(se);
            car_builder->setSeat(2);
            car_builder->setLength(80.f);

            res->car = car_builder->getResult();
            
            man_builder->setEngine(se);
            man_builder->setSeat(2);
            man_builder->setLength(80.f);

            res->man = man_builder->getResult();

            return res;
        }
};

int main(int argc, char *argv[]){
    Director dir;
    CarBuilder *carb = new CarBuilder();
    ManualBuilder *manb = new ManualBuilder();

    result *r = dir.makeSportive(carb, manb);
    r->car;
    r->man;
}
