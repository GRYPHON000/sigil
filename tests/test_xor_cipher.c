#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include<string.h>
#include "../core/xor_cipher.h"

int main(){
         
    const uint8_t in[32]={"what happened"};
    const uint8_t key[KEY_LEN]="0x42";
    size_t len=13;

     uint8_t out[32]={0};
     uint8_t verif[32]={0};

     //len with strlen
     xor_cipher(in,32,key,out);

     xor_cipher(out,32,key,verif);

      //if(out=)
    if (memcmp(in, verif,len) == 0) {
        printf("PASS: decrypt(encrypt(x)) == x\n");
    } else {
        printf("FAIL: decryption did not match\n");
    }

    return 0;
}
