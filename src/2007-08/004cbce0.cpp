// from server: 100% by colin
struct CSHA1 {
    unsigned int vtable;
    unsigned int state[5];
    unsigned int count[2];
    void Reset();
    CSHA1(unsigned int flag);
};

void CSHA1::Reset() {
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
    state[4] = 0xc3d2e1f0;
    count[0] = 0;
    count[1] = 0;
}

CSHA1::CSHA1(unsigned int flag) {
    vtable = 0x79efcc;
    Reset();
    if (flag & 1) {
        extern void __cdecl sub_62FC62(CSHA1*);
        sub_62FC62(this);
    }
}
