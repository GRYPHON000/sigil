/* sigil — core/pqc_rand.c
 * Cryptographic random bytes from /dev/urandom
 * Used by all key generation in sigil
 */
#include <stdio.h>
#include <stdint.h>
#include<stddef.h>
#include"pqc_rand.h"

int sigil_rand_bytes(uint8_t *buff, size_t len) {
    if(buff==NULL || len==0) return -1;
    FILE *f=fopen("/dev/urandom","rb");
    if(f==NULL) return -1;

    uint8_t byte_size=fread(buff,1,len,f);
    fclose(f);
    if(byte_size!=len)return -1;
    
    return 0;
}