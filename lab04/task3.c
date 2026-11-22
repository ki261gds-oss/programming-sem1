#include <stdio.h>
#include <stdint.h>

 uint32_t pack_time(int hours, int minutes, int seconds, int dst);
  
 void unpack_time(uint32_t packed_time, int *hours, int *minutes, int *seconds, int *dst);


 uint32_t pack_time(int hours, int minutes, int seconds, int dst) {
    
    uint32_t packed_time = 0;
    packed_time |= (hours & 0x1F) << 12; 
    packed_time |= (minutes & 0x3F) << 6; 
    packed_time |= (seconds & 0x3F) << 0; 
    packed_time |= (dst & 0x01) << 17; 
    return packed_time;


 }
 void unpack_time(uint32_t packed_time, int *hours, int *minutes, int *seconds, int *dst) {
    *hours = (packed_time >> 12) & 0x1F; 
    *minutes = (packed_time >> 6) & 0x3F; 
    *seconds = (packed_time >> 0) & 0x3F; 
    *dst = (packed_time >> 17) & 0x01; 
 }

 int main(void){
    printf("Packed time: 12 34 56 1\n");
printf("0x%08X\n", pack_time(12, 34, 56, 1));
uint32_t packed = pack_time(12, 34, 56, 1);
int h, m, s, d;
unpack_time(packed, &h, &m, &s, &d);
printf("%d %d %d %d\n", h, m, s, d);
return 0;
 }