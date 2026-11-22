#include <stdio.h>
#include <stdint.h>

unsigned int set_bit(unsigned int reg, int N);
unsigned int clear_bit(unsigned int reg, int N);
unsigned int toggle_bit(unsigned int reg, int N);
int check_bit(unsigned int reg, int N);
void print_binary(unsigned int reg);

 unsigned int set_bit(unsigned int reg, int N) {
    return reg | (1u << N);
}

unsigned int clear_bit(unsigned int reg, int N) {
    return reg & ~(1u << N);
}


unsigned int toggle_bit(unsigned int reg, int N) {
    return reg ^ (1u << N);
}


int check_bit(unsigned int reg, int N){
     return (reg >> N) & 1u;
}

void print_binary(unsigned int reg){
    for(int i = 31; i >= 0; i--){
        printf("%d", (reg >> i) & 1u);
        if(i % 4 == 0) printf(" ");
    }
    printf("\n");
}


int main(void) {
    unsigned int reg = 1u << 9;
    print_binary(reg);

    reg = set_bit(reg, 2);
    print_binary(reg);

    reg = clear_bit(reg, 9);
    print_binary(reg);

    reg = toggle_bit(reg, 16);
    print_binary(reg);

    printf("Bit 24: %d\n", check_bit(reg, 24));

    return 0;
}