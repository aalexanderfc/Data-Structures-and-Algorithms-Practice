#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


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

int main()
{
	vector<SensorData> sensorData;
	FillData(sensorData);

	//SKRIV DIN KOD HÄR!!!!
	time_t startOfDay = CreateTime(2012, 1, 2, 0, 0, 0);
    time_t startOfNextDay = CreateTime(2012, 1, 3, 0, 0, 0);

    int count = std::count_if(sensorData.begin(), sensorData.end(),
        [startOfDay, startOfNextDay](const SensorData& sd) {
             return sd.GetSensorType() == SensorType::Altitude && 
                   sd.GetTime() >= startOfDay && 
                   sd.GetTime() < startOfNextDay;
        });

    cout << "Antal altituder 2012-01-02: " << count << endl;

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
	std::cout << "fuelconsumption ökade med 75%" << std::endl;

	vector<SensorData>::iterator indx2 = std::find_if(sensorData.begin(), sensorData.end(),
		[](SensorData& sd) {
		return sd.GetSensorType() == SensorType::FuelConsumption;
	});
	if(indx != sensorData.end())
		cout << "Först record on fuelcosnumption: " << indx2->GetValue()<<" liter" << endl;
	else
		cout << "Inga records on fuelcosnumption" << endl;

}

void FillData(vector<SensorData>& v)
{
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

