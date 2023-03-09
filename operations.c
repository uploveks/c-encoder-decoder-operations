#include <stdio.h>
#include <stdlib.h>

#define SHORT_BITS 16
#define NUM_BITS 29

int main(void) {
    unsigned int instr = 0;

    /* Read the instruction code from standard input */
    if (scanf("%u", &instr) != 1) {
        fprintf(stderr, "Error: Failed to read instruction code\n");
        return EXIT_FAILURE;
    }

    /* Extract the instruction number and dimension */
    unsigned int instr_num = (instr >> NUM_BITS) + 1;
    unsigned int instr_dim = ((instr << (3 + 2 * instr_num)) >> (NUM_BITS - 1)) + 1;

    /* Calculate the number of operands needed for selected instruction */
    unsigned int read_op = (instr_num + 1) * instr_dim;

    /* Round up to the nearest multiple of SHORT_BITS */
    read_op = (read_op + SHORT_BITS - 1) / SHORT_BITS;

    /* Print the number of needed operands */
    printf("%u\n", read_op);

    return EXIT_SUCCESS;
}
