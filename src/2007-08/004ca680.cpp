// from server: 100% by colin
struct SHA1Context {
    int field_0;
    unsigned int state[5];
    unsigned int count[2];

    void SHA1Init();
};

void SHA1Context::SHA1Init() {
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
    state[4] = 0xc3d2e1f0;
    count[0] = 0;
    count[1] = 0;
}
