// libraries

// globals

// initialization
int  n = 0;


void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.print(n);
	Serial.println();
	n++;
}
