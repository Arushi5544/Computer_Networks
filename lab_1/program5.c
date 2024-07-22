#include <stdio.h>

void checkEndian() {
    unsigned int test = 1;
    char *byte = (char*)&test;

    if (*byte) {
        printf("The machine is Little Endian.\n");
    } else {
        printf("The machine is Big Endian.\n");
    }
}

// Function to print the content of each byte of a number
void printBytes(unsigned int number) {
    unsigned char *bytes = (unsigned char*)&number;
    printf("Content of each byte:\n");
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: 0x%X\n", i, bytes[i]);
    }
}

// Function to convert endianness
unsigned int convertEndian(unsigned int number) {
    unsigned int byte0, byte1, byte2, byte3;
    unsigned int result;

    byte0 = (number & 0x000000FF) >> 0;
    byte1 = (number & 0x0000FF00) >> 8;
    byte2 = (number & 0x00FF0000) >> 16;
    byte3 = (number & 0xFF000000) >> 24;

    result = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0);

    return result;
}

void main() {
    unsigned int number;
    checkEndian();
    printf("Enter a number (0-4294967295): ");
    scanf("%u", &number);
    printBytes(number);
    unsigned int convertedNumber = convertEndian(number);
    printf("After converting endianness:\n");
    printBytes(convertedNumber);
}
