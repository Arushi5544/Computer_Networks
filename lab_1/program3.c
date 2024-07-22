#include <stdio.h>

int main() {
    unsigned int number;
    char byte1, byte2, byte3, byte4;

    // Assign a number
    number = 0x12345678; // Example number

    // Extract each byte
    byte1 = (number >> 24) & 0xFF; // Extracting the highest byte
    byte2 = (number >> 16) & 0xFF; // Extracting the second highest byte
    byte3 = (number >> 8) & 0xFF;  // Extracting the second lowest byte
    byte4 = number & 0xFF;         // Extracting the lowest byte

    // Print the bytes
    printf("Number: 0x%X\n", number);
    printf("Byte 1: 0x%X\n", byte1);
    printf("Byte 2: 0x%X\n", byte2);
    printf("Byte 3: 0x%X\n", byte3);
    printf("Byte 4: 0x%X\n", byte4);

    return 0;
}
