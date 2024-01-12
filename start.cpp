#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>



using namespace std;

enum class SensorType
{
	Altitude,
	SpeedInKmh,
	FuelConsumption
};

class SensorData
{
	float value;
	SensorType sensorType;
	time_t time;
public:
	SensorType GetSensorType() const { return sensorType; }
	float GetValue()const { return value; }
	void SetValue(float v) { value = v; }
	time_t GetTime() const { return time; }
	SensorData(SensorType sensorType, float value, time_t time)
	{
		this->value = value;
		this->sensorType = sensorType;
		this->time = time;
	}
};


void FillData(vector<SensorData> &v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);
//Del 4:

class Customer
{
	int number;
	string name;
	time_t time;
public:
	Customer(int number, string name, time_t time)
	{
		this->number = number;
		this->name = name;
		this->time = time;
	}
	int GetNumber() const { return number; }
	string GetName() const { return name; }
	time_t GetTime() const { return time; }
};


void FillData(vector<Customer> &v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);

//Del 5:
std::map<int, double> bank;

void createAccount(int accountNumber) {
    bank[accountNumber] = 0.0;
}

void login(int accountNumber) {
    if (bank.find(accountNumber) != bank.end()) {
        std::cout << "Logged in to account: " << accountNumber << "\n";
        std::cout << "Current balance: " << bank[accountNumber] << "\n";
    } else {
        std::cout << "Account not found.\n";
    }
}

void deposit(int accountNumber, double amount) {
    if (bank.find(accountNumber) != bank.end()) {
        bank[accountNumber] += amount;
        std::cout << "Deposit successful. New balance: " << bank[accountNumber] << "\n";
    } else {
        std::cout << "Account not found.\n";
    }
}

void withdraw(int accountNumber, double amount) {
    if (bank.find(accountNumber) != bank.end()) {
        if (bank[accountNumber] >= amount) {
            bank[accountNumber] -= amount;
            std::cout << "Withdrawal successful. New balance: " << bank[accountNumber] << "\n";
        } else {
            std::cout << "Insufficient balance.\n";
        }
    } else {
        std::cout << "Account not found.\n";
    }
}
//del 4
void vardcentralSimulator(){
		queue <Customer> q;
	
	while (true)
	{
		cout << "1. Add customer" << endl;
		cout << "2. Call next customer" << endl;
		cout << "0. Exit" << endl;
		cout << "Choice: " << endl;
		cout << "Queue size: " << q.size() << endl;
		
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter name: ";
			string name;
			cin >> name;
			q.push(Customer(q.size(), name, time(NULL)));
		}
		else if (choice == 2)
		{
			Customer c = q.front();
			q.pop();
			std::cout << "Next customer is: " << c.GetName() << endl;
			std::cout << "Customer has waited: " << time(NULL) - c.GetTime() << " seconds" << endl;
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
		
	}

}
//del 5
void bankomatMenu(){
	int choice, accountNumber;
    double amount;
	
	
	while (true) {
        std::cout << "1. Create account\n2. Login\n3. Deposit\n4. Withdraw\n0. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                createAccount(accountNumber);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                login(accountNumber);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                deposit(accountNumber, amount);
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                withdraw(accountNumber, amount);
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}


int main()
{
	vector<SensorData> sensorData;
	FillData(sensorData);


	//SKRIV DIN KOD HÄR!!!!
	time_t startOfDay = CreateTime(2012, 1, 2, 0, 0, 0);
    time_t startOfNextDay = CreateTime(2012, 1, 3, 0, 0, 0);

	cout << "Del 1: " << std::endl;

    int count = std::count_if(sensorData.begin(), sensorData.end(),
        [startOfDay, startOfNextDay](const SensorData& sd) {
             return sd.GetSensorType() == SensorType::Altitude && 
                   sd.GetTime() >= startOfDay && 
                   sd.GetTime() < startOfNextDay;
        });

    cout << "Antal altituder 2012-01-02: " << count << endl;
	
	cout << "Del 2: " << std::endl;

	vector<SensorData>::iterator indx = std::find_if(sensorData.begin(), sensorData.end(),
	[](const SensorData& sd) {
		return sd.GetSensorType() == SensorType::SpeedInKmh && 
			sd.GetValue() > 99.9;
	});
	if(indx != sensorData.end())
		cout << "Maxhastighet uppnådd: " << indx->GetValue()<<" Km/h" << endl;
	else{
		cout << "Ingen maxhastighet uppnådd" << endl;
	};
//del3
	cout << "Del 3: " << std::endl;
	vector<SensorData>::iterator indx1 = std::find_if(sensorData.begin(), sensorData.end(),
		[](SensorData& sd) {
		return sd.GetSensorType() == SensorType::FuelConsumption;
	});
	if(indx != sensorData.end())
		cout << "Först record on fuelcosnumption: " << indx1->GetValue()<<" liter" << endl;
	else
		cout << "Inga records on fuelcosnumption" << endl;

	//Skriv kod som uppdaterar alla såna poster så att FuelConsumption ökas med 75%.
	std::for_each(sensorData.begin(), sensorData.end(),
		[](SensorData& sd) {
		if (sd.GetSensorType() == SensorType::FuelConsumption)
			sd.SetValue(sd.GetValue() * 1.75f);
	});
	cout << "fuelconsumption ökade med 75%:" << std::endl;

	vector<SensorData>::iterator indx2 = std::find_if(sensorData.begin(), sensorData.end(),
		[](SensorData& sd) {
		return sd.GetSensorType() == SensorType::FuelConsumption;
	});
	if(indx != sensorData.end())
		cout << "Först record on fuelcosnumption: " << indx2->GetValue()<<" liter" << endl;
	else
		cout << "Inga records on fuelcosnumption" << endl;

	//del 4
	cout << "Del 4: " << std::endl;
	vardcentralSimulator();


//del 5
cout << "Del 5: " << endl;
bankomatMenu();

	return 0;
}



void FillData(vector<SensorData>& v){
	srand(time(NULL));

	time_t tid = CreateTime(2012, 1, 1, 1, 1, 1 );
	for (int i = 0; i < 100000; i++)
	{
		SensorType type = static_cast<SensorType>(rand() % 3);
		float value = 0.0f;
		if (type == SensorType::Altitude)
			value = rand() % 1000;
		else if (type == SensorType::FuelConsumption)
			value = rand() * 3.0f;
		else if (type == SensorType::SpeedInKmh)
			value = rand() % 110;
		else
		{
			value = 99;
		}
		v.push_back(SensorData(type,value,tid));
		tid = tid + rand() % 10 + 1;
	}
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second)
{
	struct tm tid = { 0 };
	tid.tm_year = year-1900;
	tid.tm_mon = month - 1;
	tid.tm_mday = day;
	tid.tm_hour = hour;
	tid.tm_min = minute;
	tid.tm_sec = second;
	return mktime(&tid);
}

