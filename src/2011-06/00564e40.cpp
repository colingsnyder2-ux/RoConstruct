// from server: 66% by colin
// roc 2011-06 00564e40  unit: G3D::Random  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00564e40

typedef unsigned int uint32;

extern "C" {
    void* __stdcall time64(void* t);
    void __stdcall free(void* p);
}

struct Random {
    uint32* state;
    int index;
    void init(void* p);
};

static uint32 g_state[624];
static int g_index;
static uint32 g_seedA;
static uint32 g_seedB;

void Random::init(void* p) {
    uint32 a = g_seedA;
    uint32 b = g_seedB;
    if ((a | b) == 0) {
        g_state[0] = 0;
        g_state[1] = 0x20;
        g_state[2] = 0x17;
        g_state[3] = 0x18;
        g_state[4] = 0xb;
        g_state[5] = 0x60;
        g_state[6] = 0;
        g_state[7] = 0;
        g_state[8] = 0;
        void* t = time64(0);
        g_seedA = (uint32)(unsigned int)t;
        g_seedB = (uint32)((unsigned int)((unsigned long long)(unsigned int)t >> 32));
    }
    unsigned short* s = (unsigned short*)p;
    s[0] = 0;
    s[1] = 0x14;
    s[2] = 2;
    s[3] = 8;
    *(uint32*)((char*)p + 8) = g_seedA;
    *(uint32*)((char*)p + 0xc) = g_seedB;
    *(unsigned short*)((char*)p + 0x32) = 0;
    *(unsigned short*)((char*)p + 0x34) = 0;
    *(uint32*)((char*)p + 0x38) = 0;
    *(uint32*)((char*)p + 0x3c) = 0;
    free(*(void**)((char*)p + 0x24));
    *(uint32*)((char*)p + 0x24) = 0;
    *(unsigned short*)((char*)p + 0x28) = 0;
    free(*(void**)((char*)p + 0x2c));
    *(uint32*)((char*)p + 0x2c) = 0;
    *(unsigned short*)((char*)p + 0x30) = 0;
}
