// Sensor Ultrassonico
const int TRIG = 13;
const int ECHO = 12;
const int obstaculo_distancia = 20;

//Buzzer
const int buzzer = 11;
const int freqP = 2000;
const int freqM = 500;

// LEDS Avulsos
const int ledR = 2;
const int ledY = 3;
const int ledG = 4;


void setup()
{
	Serial.begin(9600);
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(buzzer, OUTPUT);
	pinMode(ledR, OUTPUT);
	pinMode(ledY, OUTPUT);
	pinMode(ledG, OUTPUT);
}

void loop()
{
	int distancia = sensor_morcego(TRIG, ECHO);
		if(distancia < obstaculo_distancia && distancia > 6){
			Serial.print("Com obstaculo: ");
			Serial.print(distancia);
			Serial.println("cm");
			digitalWrite(ledR, LOW);
			digitalWrite(ledY, HIGH);
			digitalWrite(ledG, LOW);
			tone(buzzer, freqM);
		}else if(distancia < 6) {
			Serial.print("PERIGO obstáculo próximo: ");
			Serial.print(distancia);
			Serial.println("cm");
			digitalWrite(ledR, HIGH);
			digitalWrite(ledY, LOW);
			digitalWrite(ledG, LOW);
			tone(buzzer, freqP);

		}else {
			Serial.print("Sem obstáculo: ");
			Serial.print(distancia);
			Serial.println("cm");
			digitalWrite(ledR, LOW);
			digitalWrite(ledY, LOW);
			digitalWrite(ledG, HIGH);
			noTone(buzzer);
		}
}

int sensor_morcego(int trig, int echo){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	return pulseIn(echo, HIGH)/58;
}