#ifndef SIGIL_XOR_CIPHER
#define SIGIL_XOR_CIPHER

#include <stdint.h>
#include <stddef.h>
#define KEY_LEN 32


 int xor_cipher(const uint8_t *in,size_t len,const uint8_t *key,uint8_t *out );
  

#endif