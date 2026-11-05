// from server: 24% by atomic.potato
struct CSHA1 {
    char pad0[0x240];
    char state[0x9c4 - 0x240];
    int count;
    void transform();
    void update(const void* data, unsigned int len);
    void final();
    unsigned char rand_byte();
};

struct Buf {
    unsigned int size;
    char data[1];
};

extern "C" void* __stdcall memmove(void* dst, const void* src, unsigned int n);
extern "C" void* __stdcall malloc(unsigned int n);

void CSHA1::transform() {
    unsigned int i;
    unsigned int j;
    unsigned int t;
    unsigned char* p;
    unsigned int a, b, c, d, e;
    (void)i; (void)j; (void)t; (void)p; (void)a; (void)b; (void)c; (void)d; (void)e;
}

void CSHA1::update(const void* data, unsigned int len) {
    (void)data; (void)len;
}

void CSHA1::final() {
}

unsigned char CSHA1::rand_byte() {
    return 0;
}

struct RakPeer {
    char pad0[0x240];
    CSHA1 sha;
    void func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
};

void RakPeer::func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    unsigned int* out = (unsigned int*)a;
    unsigned int p1 = b;
    unsigned int p2 = c;
    unsigned int p3 = d;
    unsigned int p4 = e;
    unsigned char* buf;
    unsigned int total;
    unsigned int i;
    unsigned int remaining;
    unsigned char* ptr;
    unsigned int off;
    unsigned int n;
    unsigned int j;
    unsigned char tmp[16];
    unsigned char* src;
    unsigned int k;
    unsigned int m;

    tmp[0] = 0x71;
    tmp[1] = 0xd9;
    tmp[2] = 0x6d;
    tmp[3] = 0xce;
    tmp[4] = 0xbf;
    tmp[5] = 0x58;
    tmp[6] = 0;
    tmp[7] = 0;

    unsigned char r1 = sha.rand_byte();
    unsigned char r2 = sha.rand_byte();
    unsigned char bl = 0x0f - ((unsigned char)(r2 + 5) & 0x0f);
    unsigned char r3 = sha.rand_byte();
    unsigned char val = (unsigned char)((r3 << 4) | bl);

    unsigned int esi = bl;
    unsigned int sz = esi + p1 + 6;
    *out = sz;

    if (p1 == p2) {
        buf = (unsigned char*)malloc(esi + p2 + 6);
    } else {
        buf = (unsigned char*)memmove((void*)(esi + p2 + 6), (const void*)p1, p1);
    }

    buf[4] = (unsigned char)p4;
    buf[5] = val;

    for (i = 0; i < esi; i++) {
        buf[6 + i] = sha.rand_byte();
    }

    unsigned int sz2 = esi + p1 + 2;
    {
        unsigned char* dst = buf + 4;
        unsigned int* src = (unsigned int*)&sz2;
        (void)dst; (void)src;
    }

    *(unsigned int*)buf = sz2;

    sha.update(buf, 0x10);
    sha.update(buf, 0x10);

    unsigned int* pOut = (unsigned int*)p3;
    unsigned int total2 = *pOut;
    unsigned int rem = total2 - 0x10;
    unsigned int idx = 0;

    if (rem >= 0x10) {
        unsigned char* base = buf + rem;
        do {
            unsigned int t = idx - rem;
            unsigned char* q = base;
            unsigned char* s = buf + idx + 2;
            unsigned int c2 = 0;
            do {
                q[0] ^= *(unsigned char*)(t + (unsigned int)q);
                q[1] ^= s[c2 - 1];
                q[2] ^= s[c2];
                q[3] ^= s[c2 + 1];
                c2 += 4;
                q += 4;
            } while (c2 < 0x10);
            sha.update(base, 0x10);
            idx = rem;
            rem -= 0x10;
            base -= 0x10;
        } while (rem >= 0x10);
    }
}
