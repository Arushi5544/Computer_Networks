#include <stdio.h>
#include <string.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt packet;
    unsigned int number;
    printf("Enter a number: ");
    scanf("%u", &number);

    // Storing the number across the structure members
    packet.ch1 = (number >> 24) & 0xFF;
    packet.ch2[0] = (number >> 16) & 0xFF;
    packet.ch2[1] = (number >> 8) & 0xFF;
    packet.ch3 = number & 0xFF;
    printf("Content of structure members:\n");
    printf("ch1: 0x%X\n", packet.ch1 & 0xFF); // & 0xFF is used to print as unsigned
    printf("ch2[0]: 0x%X\n", packet.ch2[0] & 0xFF);
    printf("ch2[1]: 0x%X\n", packet.ch2[1] & 0xFF);
    printf("ch3: 0x%X\n", packet.ch3 & 0xFF);

    // Aggregating the members to form the original number
    unsigned int reconstructed_number = (packet.ch1 << 24) |
                                        (packet.ch2[0] << 16) |
                                        (packet.ch2[1] << 8) |
                                        packet.ch3;

    // Printing the original number
    printf("Reconstructed number: %u\n", reconstructed_number);

    return 0;
}
