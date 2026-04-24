/* sigil — core/pqc_rand.h
 * Interface for Cryptographic random number generation
 */
#ifndef SIGIL_PQC_RAND_H
#define SIGIL_PQC_RAND_H

#include <stdint.h>
#include <stddef.h>

int sigil_rand_bytes(uint8_t *buff, size_t len);

#endif