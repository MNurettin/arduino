#include <stdio.h>
#include <windows.h>

int main(){

    HANDLE hSerial;

    hSerial = CreateFileA(

        "\\\\.\\COM3",
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL

    );

    if(hSerial == INVALID_HANDLE_VALUE){

        puts("com3 connect failed");
        return 0;

    }

    puts("it's ALIVE!");

    char starter;
    DWORD read;

    int posX = 0;
    int posY = 0;

    DCB temp = {0};

    temp.DCBlength = sizeof(temp);
    GetCommState(hSerial, &temp);
    temp.BaudRate = CBR_9600;
    SetCommState(hSerial, &temp);

    while(true){

        if(hSerial == INVALID_HANDLE_VALUE){

            puts("com3 connect failed");
            return 0;

        }

        ReadFile(hSerial, &starter, 1, &read, NULL);

        if((unsigned char)starter == 255 && read > 0){

            char data[4];

            ReadFile(hSerial, data, 4, &read, NULL);

            if (read == 4){

                unsigned char x_int = data[0];
                unsigned char x_mod = data[1];
                unsigned char y_int = data[2];
                unsigned char y_mod = data[3];

                posX = ((x_int * 256) + x_mod) * 1920 / 1023;
                posY = ((y_int * 256) + y_mod) * 1080 / 1023;

                SetCursorPos(posX, posY);

            }

        }

    }

    return 0;

}
