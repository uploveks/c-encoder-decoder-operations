#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 8
#define MAX_DIM 16
#define FAIL_ENCODE 0
#define NUM_BITS 29
#define OP_BITS 2
#define DIM_BITS 4
#define INT_BITS 32

unsigned int encode_instr(void) {
    unsigned int instr_num, instr_dim, encode_ans = 0;
    char op;

    if (scanf(" %u %u", &instr_num, &instr_dim) != 2) {
        return FAIL_ENCODE;
    }

    if (instr_num < 1 || instr_num > MAX_NUM || instr_dim < 1 || instr_dim > MAX_DIM) {
        return FAIL_ENCODE;
    }

    encode_ans |= (instr_num - 1);

    for (unsigned int i = 0; i < instr_num; ++i) {
        if (scanf(" %c", &op) != 1) {
            return FAIL_ENCODE;
        }

        switch (op) {
            case '+':
                encode_ans |= 0;
                break;
            case '-':
                encode_ans |= 1;
                break;
            case '*':
                encode_ans |= 2;
                break;
            case '/':
                encode_ans |= 3;
                break;
            default:
                return FAIL_ENCODE;
        }

        encode_ans <<= OP_BITS;
    }

    encode_ans <<= DIM_BITS;
    encode_ans |= (instr_dim - 1);
    encode_ans <<= (NUM_BITS - OP_BITS * instr_num - DIM_BITS);

    return encode_ans;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Wrong number of files\n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open file for reading encode\n");
        exit(EXIT_FAILURE);
    }

    unsigned int encode = encode_instr();
    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Could not open file for writing encode\n");
        exit(EXIT_FAILURE);
    }

    fprintf(output_file, "%u\n", encode);
    fclose(output_file);

    return 0;
}
