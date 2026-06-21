void setup()
{
    Serial.begin(9600);
}

int last0 = -50;
int last1 = -50;

void loop()
{

    int aZero = analogRead(A0);
    int aOne = analogRead(A1);

    if((aZero > last0 + 12 || aZero < last0 - 12) || (aOne > last1 + 12 || aOne < last1 - 12)){

        byte x_tam = aZero / 256;
        byte x_mod = aZero % 256;

        byte y_tam = aOne / 256;
        byte y_mod = aOne % 256;

        Serial.write(255);

        Serial.write(x_tam);
        Serial.write(x_mod != 255 ? x_mod : 254);

        Serial.write(y_tam);
        Serial.write(y_mod != 255 ? y_mod : 254);

        last0 = aZero;
        last1 = aOne;

    }

    delay(11);

}