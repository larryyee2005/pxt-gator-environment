/**
* Andy England @ SparkFun Electronics
* September 6, 2018
* https://github.com/sparkfun/pxt-light-bit
*
* Development environment specifics:
* Written in Microsoft PXT
* Tested with a SparkFun temt6000 sensor and micro:bit
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/


#include "pxt.h"
#include <cstdint>
#include <math.h>
#include "SparkFunEnvironment.h"

using namespace pxt;

namespace gatorEnvironment {
	MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);
	environment *gatorEnvironmentCombo; //BME280 handles our Temp, pressure, and humidity
	
	/*
	* Initializes the particle sensor
	*/
	//%
	void begin()
	{
		gatorEnvironmentCombo->begin();
	}
	
	//%
	float getMeasurement(uint8_t type)
	{
		switch (type)
		{
			case 1:
				return gatorEnvironmentCombo->readTempC();
				break;
			case 2:
				return gatorEnvironmentCombo->readFloatHumidity();
				break;
			case 3:
				return gatorEnvironmentCombo->readFloatPressure();
				break;
			case 4:
				return gatorEnvironmentCombo->getCO2();
				break;
			case 5:
				return gatorEnvironmentCombo->getTVOC();
				break;
			default:
				return 0;
				break;
		}
	}
}