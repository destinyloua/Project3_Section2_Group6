#include "CppUnitTest.h"
#include "../SWAMP-Greenhouse/CO2.h"
#include "../SWAMP-Greenhouse/SoilMoisture.h"

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

		TEST_METHOD(Soil_Unit_Req01)
		{
			//SoilMoisture s;
			//s.readData();
			//s.control();
			//Assert::IsTrue(s.GetIrrigation());

		}

		TEST_METHOD(Soil_Unit_Req02)
		{
			SoilMoisture s;
			s.SetIrrigationStatus();
			Assert::IsFalse(s.GetIrrigation());
		}
	};
}
