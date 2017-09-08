/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/578b4f9b7c77f535fc00002f

"Constructing a car #1 - Engine and Fuel Tank"
*/

#include <iostream>
#include <cmath>

// Interface
class ICar
{
public:
    virtual void EngineStart() = 0;
    virtual void EngineStop() = 0;
    virtual void Refuel(double liters) = 0;
    virtual void RunningIdle() = 0;
protected:
    bool engineIsRunning = false;
};

class IEngine
{
public:
    virtual void Consume(double liters) = 0;
    virtual void Start() = 0;
    virtual void Stop() = 0;
protected:
    bool isRunning = false;
};

class IFuelTank
{
public:
    virtual void Consume(double liters) = 0;
    virtual void Refuel(double liters) = 0;
protected:
    double fillLevel = 0.0;
    bool isOnReserve = false;
    bool isComplete = false;
};

class IFuelTankDisplay
{
protected:
    double fillLevel = 0.0;
    bool isOnReserve = false;
    bool isComplete = false;
};

// Solução
class Engine : public IEngine
{
public:
	Engine(){}// std::cout << "Engine On..." << std::endl; }
	~Engine(){}// std::cout << "Engine Off." << std::endl; }
  void Consume(double liters) {}
  void Start() { isRunning = true; }
  void Stop() { isRunning = false; }

// protected:
//     bool isRunning = false;
};

class FuelTank : public IFuelTank
{
public:
	FuelTank(double liters) {
        setFillLevel(liters);
        // std::cout << "FuelTank On..." << std::endl; 
    }
	~FuelTank(){}// std::cout << "Engine Off." << std::endl; }
  void Consume(double liters) { setFillLevel(fillLevel - liters);}
  void Refuel(double liters) { setFillLevel(fillLevel + liters);}

  void setFillLevel(double liters){
    if (liters >= 60) {
			fillLevel = 60.0;
			isComplete = true;
		} else {
			if (liters < 0) fillLevel = 0;
            else fillLevel = liters;
		}
		if (liters < 5) isOnReserve = true;
    }
  double getFillLevel(){ return round(fillLevel * 100) * 0.01; };
  bool getIsOnReserve(){ return isOnReserve; }
  bool getIsComplete(){ return isComplete; }

// protected:
//     double fillLevel = 0.0;
//     bool isOnReserve = false;
//     bool isComplete = false;
};

class FuelTankDisplay : public IFuelTankDisplay
{
public:
	FuelTank* display;
	FuelTankDisplay(FuelTank* display) {
        this->display = display;
        // std::cout << "Display On..." << std::endl; 
    }
	~FuelTankDisplay(){}// std::cout << "Display Off." << std::endl; }
	double getFillLevel(){ return display->getFillLevel(); }
	bool getIsOnReserve(){ return display->getIsOnReserve(); }
	bool getIsComplete(){ return display->getIsComplete(); }

// protected:
//     double fillLevel = 0.0;
//     bool isOnReserve = false;
//     bool isComplete = false;
};

class Car : public ICar
{
public:
    Engine* engine;
    FuelTank* fuelTank;
    FuelTankDisplay* fuelTankDisplay;

    Car() {
        engine = new Engine;
        fuelTank = new FuelTank(20);
        fuelTankDisplay = new FuelTankDisplay(fuelTank);
        // std::cout << "Built car..." << std::endl; 
    }

    Car(double liters) {
        engine = new Engine;
        fuelTank = new FuelTank(liters);
        fuelTankDisplay = new FuelTankDisplay(fuelTank);
    }

    ~Car()
    {
        delete engine;
        delete fuelTank;
        delete fuelTankDisplay;
        // std::cout << "Destroyed car!" << std::endl;
    }

    void EngineStart() {
        if (fuelTank->getFillLevel() > 0){
            engine->Start();
            engineIsRunning = true;
        }
    }

    void EngineStop() {
        engine->Stop();
        engineIsRunning = false;
    }

    void Refuel(double liters) { fuelTank->Refuel(liters); }
    
    void RunningIdle() {
        if (getEngineIsRunning())
            fuelTank->Consume(0.0003);
        if (fuelTank->getFillLevel() == 0)
            EngineStop();
    }

    bool getEngineIsRunning() { return engineIsRunning; }

// protected:
//     bool engineIsRunning = false;
};

// Teste
int main()
{
    Car car;
    if (!car.getEngineIsRunning()){
    	car.EngineStart();
    	std::cout << "Engine is running..." << std::endl;
    }
    if (car.getEngineIsRunning()){
    	car.EngineStop();
    	std::cout << "Engine Stop." << std::endl;
    }

    car.fuelTank->setFillLevel(1);
    car.EngineStart();
    for(int i = 0; i < 3000; i++)
    	car.RunningIdle();

    // 0.10 liters
    std::cout << "Fuel tank = " << car.fuelTankDisplay->getFillLevel()
        << " liters." << std::endl;

    car.fuelTank->setFillLevel(60);
    if (car.fuelTankDisplay->getIsComplete())
    	std::cout << "Fuel tank is complete." << std::endl;

    car.fuelTank->setFillLevel(4);
    if(car.fuelTankDisplay->getIsOnReserve())
    	std::cout << "Fuel tank is on reserve." << std::endl;
    
    car.fuelTank->setFillLevel(5);
    car.Refuel(40);
    if(car.fuelTankDisplay->getFillLevel() == 45);
    	std::cout << "Fuel tank = 45 liters." << std::endl;

    return 0;
};
