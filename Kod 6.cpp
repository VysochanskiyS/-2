#include <iostream>
#include <string>
using namespace std;

class car
{
public:

	//Constructor's | Destructor's
	car()
	{
		cout << "Constructor of car" << endl;
		this->year = rand()/12;

		numberTransmission = new int;
		*numberTransmission = rand()/10;
	}

	car(const car &other)
	{
		cout << "Constructor of car (copy)" << endl;
		this->numberTransmission = new int;
		
		this->numberTransmission = other.numberTransmission;

		this->year= other.year;
		this->power= other.power;
	}
	
	virtual ~car()
	{
		cout << "Detructor of car" << endl;
		delete numberTransmission;
		numberTransmission = nullptr;
	}

	//Method's
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;


	//Geter's  ||  Setter's
	int GetWaranty()
	{
		return this->year;
	}

	double GetPower()
	{
		return this->power;
	}

	int* GetnumberTransmission()
	{		
		return this->numberTransmission;
	}


	void SetYear(int year)
	{
		this->year=year;
	}

	void SetPower(double power)
	{
		this->power=power;
	}

	void Setnumbertransmission(int value)
	{
		this->numberTransmission=&value;
	}


protected:

	bool state;
	int year;
	double power=1.6;	
	int* numberTransmission;
};

class truck : public car
{
private:
bool state;
	string model;
	int kc;


public:
	//Constructor's | Destructor's

	truck (string model,int kc )
	{
		cout << "Constructor of truck" << endl;
		this->model = model;
		this->kc = kc;

	}

	truck(const truck& other)
	{
		cout << "Constructor of truck (copy)" << endl;
		this->model = other.model;
		this->kc = other.kc;

	
	}


	//Operator
	void operator=(const truck& other)
	{
		this->model = model;
		this->kc = kc;
	}

	//Method's

	void TurnOn()override
	{
		cout <<endl<< "TurnOn truck" << endl;
		this->state = true;
	}
	void TurnOff()override
	{
		cout <<endl<< "TurnOff truck" << endl;
		this->state = false;
	}


	
	
	//Geter's  ||  Setter's
	string GetModel()
	{
		return this->model;
	}

	double Getkc()
	{
		return this->kc;
	}


	void SetModel(string model)
	{
		this->model = model;
	}

	void Setkc(int kc)
	{
		this->kc = kc;
	}

	
};


int main()
{
	
	truck truck1("Man", 16);
	truck1.TurnOn();
	truck1.TurnOff();
	cout << endl << "========================================" << endl;
	return 0;
}