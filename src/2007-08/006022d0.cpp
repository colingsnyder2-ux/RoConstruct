// from server: 34% by colin
struct Running {
    char pad0[4];
    int field4;
    char pad8[0x34];
    float f3c;
    float f40;
    float f44;
    char pad48[0x150];
    int field198;
    bool onComputeForceImpl();
};

extern "C" int __stdcall sub_5a61f0(int);
extern "C" int __stdcall sub_5a6210(int);
extern "C" int __stdcall sub_5a6230(int);
extern "C" void __stdcall sub_530100(int);
extern "C" void __stdcall sub_51d890(int, int, int);
extern "C" int __stdcall sub_5ffd30(int, int, int, int, int, int);

extern float g_7b54f0;
extern float g_7c2b6c;
extern int g_8bfbf4;
extern float g_8bfbe8;
extern float g_8bfbec;
extern float g_8bfbf0;

bool Running::onComputeForceImpl() {
    int ebx = sub_5a61f0(field4);
    if (ebx != 0) return false;

    if (sub_5a6210(field4) == 0) {
        sub_5a6230(field4);
    }

    float len = f3c * f3c + f40 * f40 + f44 * f44;
    float sq = 0.0f;
    float one = 1.0f;
    float zero = 0.0f;
    (void)len;
    (void)sq;
    (void)one;
    (void)zero;

    if ((g_8bfbf4 & 1) == 0) {
        g_8bfbf4 |= 1;
        g_8bfbe8 = 0.0f;
        g_8bfbec = 1.0f;
        g_8bfbf0 = 0.0f;
    }

    float nx = -g_8bfbe8;
    float ny = -g_8bfbec;
    float nz = -g_8bfbf0;

    int edi = *(int*)(ebx + 0x64);
    int eax = *(int*)(ebx + 0x60);

    float scale = *(float*)(eax + 0xc);
    float vx = f3c * scale;
    float vy = f40 * scale;
    float vz = f44 * scale;

    float w = *(float*)(eax + 8) * g_7b54f0;

    float a0 = nx;
    float a1 = ny;
    float a2 = nz;

    sub_530100(edi);

    float px = *(float*)(edi + 0xa8) + a0;
    float py = *(float*)(edi + 0xac) + a1;
    float pz = *(float*)(edi + 0xb0) + a2;

    float out0, out1, out2;
    sub_51d890((int)&out0, (int)&out1, (int)&out2);

    float fz = 0.0f;
    (void)fz;

    int e2 = sub_5a6210(field4);
    float h;
    if (e2 != 0) {
        int p = sub_5a6210(field4);
        h = *(float*)(*(int*)(p + 0x60) + 8);
    } else {
        int p = sub_5a6230(field4);
        if (p != 0) {
            h = *(float*)(*(int*)(p + 0x60) + 8);
        } else {
            h = 0.0f;
        }
    }

    float hh = h * h;
    float hz = h * g_7c2b6c;

    float r0 = hh;
    float r1 = hh;
    float r2 = hh;

    int edx = field4;
    int e3 = *(int*)(edx + 0x198);
    int ecx = *(int*)(e3 + 0x30);

    int res = sub_5ffd30((int)&r0, 0, (int)&r1, (int)&r2, (int)&hz, (int)&hh);
    if (res == 0) return false;

    if (!(r0 <= hz)) return false;

    return true;
}
