#include <HardwareSerial.h>

void setup()
{
	Serial.begin(9600);
	Serial.println();

	Serial1.begin(9600, SERIAL_8N1, 18, 19);
	Serial2.begin(9600);
}

void loop()
{
	redirectSerial(0, 1);
	redirectSerial(1, 0);
}

HardwareSerial* serials[2] = { &Serial1, &Serial2 };
int srcPrinted = -1;

void redirectSerial(int src, int dst)
{
	if (serials[src]->available())
	{
		if (srcPrinted != src)
		{
			Serial.println();
			Serial.print("#");
			Serial.print(src + 1);
			Serial.print(" -> ");
			Serial.print("#");
			Serial.print(dst + 1);
			Serial.println();
			srcPrinted = src;
		}

		int c = serials[src]->read();
		serials[dst]->write(c);
		Serial.write(c);
	}
}
