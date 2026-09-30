#include <stdio.h>

int main(void) {
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("void*: %zu\n", sizeof(void*));

    unsigned char byte_test = 255;
    printf("byte_test = %u (hex: 0x%02X)\n", byte_test, byte_test);

    byte_test = byte_test + 1;
    printf("after +1: %u (hex: 0x%02X)\n", byte_test, byte_test);

    return 0;
}