#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../core/pqc_rand.h"

/* The TEST Macro: A simple "Latin" tool to verify logic */
#define TEST(name, cond) printf("Test %s: %s\n", name, (cond) ? "PASSED" : "FAILED")

int main() {
    uint8_t buff1[32];
    uint8_t buff2[32];

    /* Test 1: Returns 0 on success */
    int res1 = sigil_rand_bytes(buff1, 32);
    TEST("1 — Returns 0 on success", res1 == 0);

    /* Test 2: Output not all zeros */
    /* We check if at least one byte is non-zero to prove the siphon worked */
    int all_zeros = 1;
    for(int i = 0; i < 32; i++) {
        if(buff1[i] != 0) {
            all_zeros = 0;
            break;
        }
    }
    TEST("2 — Output not all zeros", all_zeros == 0);

    /* Test 3: Two separate calls differ */
    /* Cryptographic entropy should never repeat the same sequence */
    sigil_rand_bytes(buff2, 32);
    TEST("3 — Two calls differ", memcmp(buff1, buff2, 32) != 0);

    /* Test 4: NULL buffer returns -1 */
    /* Ensuring the "Gatekeeper" prevents a program crash */
    int res4 = sigil_rand_bytes(NULL, 32);
    TEST("4 — NULL returns -1", res4 == -1);

    /* Test 5: Zero length returns -1 */
    /* Verifying the "Picky Translator" logic for numeric counts */
    int res5 = sigil_rand_bytes(buff1, 0);
    TEST("5 — Zero length returns -1", res5 == -1);

    return 0;
}