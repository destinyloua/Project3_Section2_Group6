#include "pch.h"
#include "CppUnitTest.h"
#include "../SWAMP-Greenhouse/CO2.h"
#include "../SWAMP-Greenhouse/Humidity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWAMPTESTS
{
	TEST_CLASS(SWAMPTESTS)
	{
	public:
		
		// Testing CO2 reads data from file accurately -- req #1
		TEST_METHOD(CO2_Test01_Req01)
		{
			CO2 c;
	
			
		}
	};

	TEST_CLASS(HumidityUnitTests)
	{
	public:
		// Testing generateRandomHumidity() if it actually generates random values
		TEST_METHOD(Unit_Test_Hum_001_RandomHumidity)
		{
			Humidity h;
			for (int i = 0; i > 100; ++i) {
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
}
