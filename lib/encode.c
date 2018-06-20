#define TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "0123456789+/"
#define PADDING '='

void encode(const char *in, char *out) {
    out[0] = TABLE[in[0] >> 2];
    out[1] = TABLE[(in[0] & 0x03) << 4 | in[1] >> 4];
    out[2] = in[1] ? TABLE[(in[1] & 0x0f) << 2 | in[2] >> 6] : PADDING;
    out[3] = in[2] ? TABLE[in[2] & 0x3f] : PADDING;
}