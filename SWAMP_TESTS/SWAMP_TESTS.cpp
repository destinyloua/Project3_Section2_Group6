#include "CppUnitTest.h"
#include "../SWAMP-Greenhouse/SoilMoisture.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWAMPTESTS
{
	TEST_CLASS(SWAMPTESTS)
	{
	public:
		TEST_METHOD(Soil_UnitTest01_REQ01)
		{
			SoilMoisture s;
			s.readData();
			s.control();
			Assert::IsTrue(s.GetIrrigation());
		}
		TEST_METHOD(Soil_UnitTest01_REQ02)
		{
			SoilMoisture s;
			s.SetIrrigationStatus();
			Assert::IsTrue(s.GetIrrigation());
		}
		TEST_METHOD(Soil_UnitTest01_REQ03)
		{
			SoilMoisture s;
			s.readData();
			s.control();
			Assert::IsTrue(s.GetIrrigation());
		}
		TEST_METHOD(Soil_UnitTest01_REQ04)
		{
			SoilMoisture s;
			s.readData();
			s.control();
			Assert::IsTrue(s.GetIrrigation());
		}
		TEST_METHOD(Soil_UnitTest01_REQ05)
		{
			SoilMoisture s;
			s.IncreaseThreshold();
			Assert::AreEqual(31.00,s.GetThreshold());
		}
		TEST_METHOD(Soil_UnitTest02_REQ05)
		{
			SoilMoisture s;
			s.DecreaseThreshold();
			Assert::AreEqual(29.00, s.GetThreshold());
		}
		TEST_METHOD(Soil_UnitTest01_REQ06)
		{
			SoilMoisture s;
			Assert::AreEqual(30.00, s.GetThreshold());
		}
	};
}
