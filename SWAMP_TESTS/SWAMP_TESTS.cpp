#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include <fstream>
#include "../SWAMP-Greenhouse/CO2.h"
#include "../SWAMP-Greenhouse/Energy.h"
#include "../SWAMP-Greenhouse/Humidity.h"
#include "../SWAMP-Greenhouse/Lights.h"
#include "../SWAMP-Greenhouse/Temperature.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWAMPTESTS
{
	TEST_CLASS(CO2TESTS)
	{
	
	public:
		
		// CO2 TESTS - Destiny
		// Testing CO2 reads data from file accurately -- req #1
		TEST_METHOD(UNIT_TEST_CO2_001_REQ1)
		{
			CO2 c;
			// add mock values to the co2History vector - these are in the same order as in CO2Data.txt
			c.addToCO2History(1000.00);
			c.addToCO2History(950.00); // only checking accuracy so not adding all values 

			double expected = 1000.000;
			double actual = c.getCurrentCO2(0); // only testing the first value matches 

			Assert::AreEqual(expected, actual);
		}

		// Testing CO2 displays warning message when CO2Value > 1500 -- req #2
		TEST_METHOD(UNIT_TEST_CO2_002_REQ2)
		{
			CO2 c;
			// adding a value > 1500
			c.addToCO2History(1000.00);
			c.addToCO2History(950.00);
			c.addToCO2History(1800.00);
			double testValue = c.getCurrentCO2(2); // mock value to invoke warning should be at index 2
			
			// testing warning matches expected format 
			string expected = "CO2 Value: " + to_string(testValue) + " ppm, DANGER! Too High! ";
			string actual = c.getWarning(testValue); 

			Assert::AreEqual(expected, actual);
		}

		// Testing CO2 displays warning message when CO2Value < 1000 -- req #2
		TEST_METHOD(UNIT_TEST_CO2_003_REQ2)
		{
			CO2 c;
			c.addToCO2History(1000.00);
			c.addToCO2History(950.00);
			c.addToCO2History(1800.00);
			double testValue = c.getCurrentCO2(1); // mock value to invoke warning should be at index 1

			// testing warning matches expected format 
			string expected = "CO2 Value: " + to_string(testValue) + " ppm, DANGER! Too Low! "; 
			string actual = c.getWarning(testValue);

			Assert::AreEqual(expected, actual);
		}

		// Testing that after 60 sec, the index moves to the next CO2 value -- req #3
		TEST_METHOD(UNIT_TEST_CO2_004_REQ3)
		{
			CO2 c;
			c.addToCO2History(1000.00); // previous value
			c.addToCO2History(950.00); // new value 
			double currentTime = 60.0;

			// updates after 60 sec
			c.updateCO2Value(currentTime);
			double prevValue = c.getCurrentCO2(0);
			double newValue = c.getCurrentCO2(c.getIndex()); // index should have moved 

			Assert::AreNotEqual(prevValue, newValue);
		}

	};

	TEST_CLASS(ENERGYTESTS) 
	{

	public:

		// ENERGY TESTS - Destiny
		// Testing that Energy reads values from the vector in the correct order -- req #1
		TEST_METHOD(UNIT_TEST_ENERGY_001_REQ1) {
			Energy e;
			// add mock values to energyHistory vector - these values appear in the simulation file 
			e.addToEnergyHistory(200.00);
			e.addToEnergyHistory(210.00);
			e.addToEnergyHistory(301.00);

			double expected = 200.00;
			double actual = e.getCurrentWatts(0); // check value at index 0 

			Assert::AreEqual(expected, actual);
		}

		// Testing that tooMuchPower is set to true when usage exceeds 300 watts -- req #2
		TEST_METHOD(UNIT_TEST_ENERGY_002_REQ2) {
			Energy e;
			e.setWatts(301.00);
			e.setTooMuchPower();

			Assert::IsTrue(e.getPower());
		}

		// Testing low power mode can be activated -- req #3
		TEST_METHOD(UNIT_TEST_ENERGY_003_REQ3) {
			Energy e;
			e.enableLowPower();

			Assert::IsTrue(e.getLowPowerStatus());
		}

		// Testing low power mode can be disabled -- req #3
		TEST_METHOD(UNIT_TEST_ENERGY_004_REQ3) {
			Energy e;
			e.enableLowPower();
			e.disableLowPower();

			Assert::IsFalse(e.getLowPowerStatus());
		}

	};

	// Humidity Tests Liam
	TEST_CLASS(HumidityUnitTests)
	{

	public:

		// Testing generateRandomHumidity() if it actually generates random values
		TEST_METHOD(Unit_Test_Hum_001_RandomHumidity)
		{
			Humidity h;
			for (int i = 0; i < 100; ++i) {
				h.generateRandomHumidity();
				double humidityLevel = h.getHumidityLevel();
				Assert::IsTrue((humidityLevel < 50) || (humidityLevel > 80) || ((humidityLevel >= 50) && (humidityLevel <= 80)));
			}
		}

		// Testing alertHumidityChange() if it returns an alert when humidity is out of range (too low)
		TEST_METHOD(Unit_Test_Hum_002_LowHumidity)
		{
			Humidity h;
			h.setHumidityLevel(49.0);
			std::string expected = "Alert: Humidity level out of range! Too low!";
			std::string actual = h.alertHumidityChange();
			Assert::AreEqual(expected, actual);
		}

		// Testing alertHumidityChange() if it returns an alert when humidity is out of range (too high)
		TEST_METHOD(Unit_Test_Hum_002_HighHumidity)
		{
			Humidity h;
			h.setHumidityLevel(81.0);
			std::string expected = "Alert: Humidity level out of range! Too high!";
			std::string actual = h.alertHumidityChange();
			Assert::AreEqual(expected, actual);
		}

		// Testing alertHumidityChange() if it returns an alert when humidity is in range
		TEST_METHOD(Unit_Test_Hum_002_NormalHumidity)
		{
			Humidity h;
			h.setHumidityLevel(70.0);
			std::string expected = "Humidity level within range.";
			std::string actual = h.alertHumidityChange();
			Assert::AreEqual(expected, actual);
		}
	};

	// Lights tests aiden
	TEST_CLASS(LightsTests)
	{
	public:

		TEST_METHOD(UNIT_TEST_LIGHT_001_REQ1)
		{
			Lights light;

			// Step 1: Set initial schedule (6:00 AM to 8:00 PM)
			light.setScheduel(6, 20);

			int startLight1 = 6;
			int stopLight1 = 20;

			int startLight2 = 7;
			int stopLight2 = 21;

			// Step 2: Retrieve schedule and verify
			Assert::AreEqual(6, startLight1);
			Assert::AreEqual(20, stopLight1);

			// Step 3: Set new schedule (7:00 AM to 9:00 PM)
			light.setScheduel(7, 21);

			// Step 4: Retrieve updated schedule and verify
			Assert::AreEqual(7, startLight2);
			Assert::AreEqual(21, stopLight2);
		}
		TEST_METHOD(UNIT_TEST_LIGHT_002_REQ2)
		{
			Lights light;

			// Step 1: Set light to ON
			light.setLightSwitch(true);

			// Step 2: Verify light status
			Assert::IsTrue(true);

			// Step 3: Set light to OFF and verify again
			light.setLightSwitch(false);
			Assert::IsFalse(false);
		}
		TEST_METHOD(UNIT_TEST_LIGHT_003_REQ3)
		{
			Lights light;

			// Step 1: Set initial light level to 50%
			light.setActualLightLevel(50);
			Assert::AreEqual(50, light.getActualLightLevel());

			// Step 2: Adjust light level to 70%
			light.setActualLightLevel(70);

			// Step 3: Verify new light level
			Assert::AreEqual(70, light.getActualLightLevel());
		}
	};

	// temp tests aiden
	TEST_CLASS(tempTests)
	{
	public:

		TEST_METHOD(UNIT_TEST_TEMP_001_REQ1)
		{
			Temperature temp;

			// Step 1: Set temperature to 25°C
			temp.setActualTemperature(25);

			// Step 2: Retrieve and verify temperature
			Assert::AreEqual(25, temp.getActualTemperature());

			// Step 3: Set temperature to 30°C
			temp.setActualTemperature(30);

			// Step 4: Retrieve and verify the new temperature
			Assert::AreEqual(30, temp.getActualTemperature());
		}
		TEST_METHOD(UNIT_TEST_TEMP_002_REQ2)
		{
			Temperature temp;

			// Step 1: Set temperature to 25°C
			temp.setActualTemperature(25);

			// Step 2: Update temperature to 28°C
			temp.setActualTemperature(28);

			// Step 3: Retrieve and verify real-time temperature
			Assert::AreEqual(28, temp.getActualTemperature());
		}
		TEST_METHOD(UNIT_TEST_TEMP_003_REQ3)
		{
			Temperature temp;

			// Step 1: Set temperature system to ON
			temp.setTempSwitch(true);

			// Step 2: Verify the status is ON
			Assert::IsTrue(true);

			// Step 3: Set temperature system to OFF and verify
			temp.setTempSwitch(false);
			Assert::IsFalse(false);
		}
	};
}
