#include <ctype.h>
#define ALPHA_NUM 26 // 字母个数
int getIdx(char ch);

void decode(const char *in, char *out) {
    out[0] = getIdx(in[0]) << 2 | getIdx(in[1]) >> 4;
    out[1] = in[2] == '=' ? 0 : (getIdx(in[1]) & 0x0f) << 4 | getIdx(in[2]) >> 2;
    out[2] = in[3] == '=' ? 0 : (getIdx(in[2]) & 0x03) << 6 | getIdx(in[3]);
}

int getIdx(char ch) {
    int i;

    if (isupper(ch)) {
        i = ch - 'A';
    } else if (islower(ch)) {
        i = ch - 'a' + ALPHA_NUM;
    } else if (isdigit(ch)) {
        i = ch - '0' + ALPHA_NUM * 2;
    } else if (ch == '+') {
        i = 62;
    } else if (ch == '/') {
        i = 63;
    } else {
        i = -1;
    }

    return i;
}