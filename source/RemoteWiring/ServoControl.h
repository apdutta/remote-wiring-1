/*
    Copyright(c) Microsoft Open Technologies, Inc. All rights reserved.

    The MIT License(MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions :

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#pragma once

namespace Microsoft {
namespace Maker {
namespace RemoteWiring {

ref class RemoteDevice;

namespace Servo {

public ref class ServoControl sealed
{
public:
	friend ref class RemoteDevice;

	void
	attach(
		uint8_t pin_,
		uint16_t minPulse_,
		uint16_t maxPulse_
	);

	void
	write(
		uint8_t value_
		);
	
	int
	read();

	bool
	attached();
	

private:

	//singleton pattern w/ friend class to instantiate
	ServoControl(
		Firmata::UwpFirmata ^ firmata_,
		RemoteWiring::RemoteDevice ^ device_
		) :
		_firmata( firmata_ ),
		_device( device_ )
	{
	}
	
	//a reference to the UAP firmata interface
	Firmata::UwpFirmata ^_firmata;
	RemoteWiring::RemoteDevice ^ _device;

	uint8_t _pin;
	uint8_t _lastWrite;
};

} // namespace Servo
} // namespace RemoteWiring
} // namespace Maker
} // namespace Microsoft