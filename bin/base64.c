#include <stdio.h>
#include <string.h>

void encode(const char *, char *);
void decode(const char *, char *);
void Encode(void);
void Decode(void);

int main(int argc, char *argv[]) {
    if (argc > 1 && (strcmp(argv[1], "-d") || strcmp(argv[1], "--decode")))
        Decode();
    else
        Encode();

    return 0;
}

void Encode(void) {
    char inp[3];
    char out[4];
    int i = 0;

    while ((inp[i++] = getchar()) != EOF) {
        if (i % 3 == 0) {
            i = 0;
            encode(inp, out);
            putchar(out[0]);
            putchar(out[1]);
            putchar(out[2]);
            putchar(out[3]);
        }
    }
    if (--i) {
        while (i < 3) {
            inp[i++] = 0;
        }
        encode(inp, out);
        putchar(out[0]);
        putchar(out[1]);
        putchar(out[2]);
        putchar(out[3]);
    }

    putchar('\n');
}

void Decode(void) {
    char in[4], out[3];
    int i = 0;

    while ((in[i++] = getchar()) != EOF) {
        i %= 4;
        if (!i) {
            decode(in, out);
            int k = 0;
            while (k < 3 && out[k])
                putchar(out[k++]);
        }
    }
}