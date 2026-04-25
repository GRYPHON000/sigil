/* sigil — core/xor_cipher.c
 * XOR cipher — bitwise encryption demonstration
 * WARNING: NOT secure with reused key. For learning only.
 * sigil uses WOTS+ and ML-DSA for real cryptography.
 */
 #include <stdio.h>
 #include <stddef.h>
 #include <stdint.h>
 #include "xor_cipher.h"
 #define KEY_LEN 32

 
  int xor_cipher(const uint8_t *in,size_t len,const uint8_t *key,uint8_t *out){
    if(in==NULL || len==0 || key==NULL || out==NULL) return -1;
   
    for(size_t i=0;i<len;i++){
     *(out+i)=*(in+i)^*(key+(i%KEY_LEN));
   }
        return 0;


  }