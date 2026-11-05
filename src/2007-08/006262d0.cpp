// from server: 43% by colin
struct Humanoid;
struct Running {
    char pad0[4];
    Humanoid* humanoid;
    char pad8[0x14];
    int field1c;
    int onComputeForceImpl(float);
};

struct Humanoid {
    char pad0[0x60];
    void* field60;
    char pad64[0x20];
    void* field84;
};

struct Vec3 { float x, y, z; };

extern "C" {
    int __stdcall sub_5A6250(void*);
    void* __stdcall sub_5A61F0(void*);
    void* __stdcall sub_5A6210(void*);
    void* __stdcall sub_5A6230(void*);
    void __stdcall sub_530100(void*);
    void __stdcall sub_4731A0(void*, void*, void*);
    void* __stdcall sub_51D890(void*, void*, void*);
    int __stdcall sub_5FFD30(void*, void*, void*, void*, void*, void*, void*);
    int __stdcall sub_573D40(void*);
}

extern float g_797e9c;
extern float g_797b34;
extern float g_7c4a50;
extern float g_793760;
extern int g_8bfbf4;
extern float g_8bfbe8;
extern float g_8bfbec;
extern float g_8bfbf0;

int Running::onComputeForceImpl(float arg) {
    if (!sub_5A6250(humanoid))
        return 0;

    Humanoid* h = (Humanoid*)sub_5A61F0(humanoid);
    void* p = h->field84;
    sub_530100(p);

    Humanoid* h2 = (Humanoid*)sub_5A61F0(humanoid);
    float* f = (float*)h2->field60;
    float a = f[1];
    float b = f[2];
    float c = f[3];

    float scale = g_797e9c;
    float v1 = a * scale;
    float v2 = b * scale;
    float v3 = c * scale;

    float w = 1.0f;
    float t;
    if (*(char*)&arg) {
        t = g_797b34;
    } else {
        t = g_7c4a50;
    }

    if (sub_5A6210(humanoid)) {
        Humanoid* h3 = (Humanoid*)sub_5A6210(humanoid);
        float* f3 = (float*)h3->field60;
        w = f3[2] * t + g_793760;
    } else if (sub_5A6230(humanoid)) {
        Humanoid* h4 = (Humanoid*)sub_5A6230(humanoid);
        float* f4 = (float*)h4->field60;
        w = f4[2] * t + g_793760;
    }

    float negv2 = -v2;
    float zero = 0.0f;
    float tmp[3];
    tmp[0] = negv2;
    tmp[1] = zero;
    tmp[2] = zero;
    float tmp2[3];
    sub_4731A0(p, tmp, tmp2);

    if (!(g_8bfbf4 & 1)) {
        g_8bfbf4 |= 1;
        g_8bfbe8 = 0.0f;
        g_8bfbec = 1.0f;
        g_8bfbf0 = 0.0f;
    }

    float n1 = -g_8bfbe8;
    float n2 = -g_8bfbec;
    float n3 = -g_8bfbf0;
    float tmp3[3];
    tmp3[0] = n1;
    tmp3[1] = n2;
    tmp3[2] = n3;
    float tmp4[3];
    sub_51D890(tmp3, tmp2, tmp4);

    float out[3];
    out[0] = v1;
    out[1] = tmp4[0];
    out[2] = tmp4[1];

    int r = this->onComputeForceImpl(0);
    if (r != 0)
        return r;

    float fv = v1;
    int i = -1;
    int j = -1;
    float fv2 = fv;

    while (true) {
        float fi = (float)i;
        float fv3 = fi * v2;
        float fv4 = fv2;

        while (true) {
            float fj = (float)j;
            float fv5 = fj * v3;

            if (!(g_8bfbf4 & 1)) {
                g_8bfbf4 |= 1;
                g_8bfbe8 = 0.0f;
                g_8bfbec = 1.0f;
                g_8bfbf0 = 0.0f;
            }

            float m00 = *(float*)((char*)p + 0);
            float m01 = *(float*)((char*)p + 4);
            float m02 = *(float*)((char*)p + 8);
            float m10 = *(float*)((char*)p + 0xc);
            float m11 = *(float*)((char*)p + 0x10);
            float m12 = *(float*)((char*)p + 0x14);
            float m20 = *(float*)((char*)p + 0x18);
            float m21 = *(float*)((char*)p + 0x1c);
            float m22 = *(float*)((char*)p + 0x20);
            float t0 = *(float*)((char*)p + 0x24);
            float t1 = *(float*)((char*)p + 0x28);
            float t2 = *(float*)((char*)p + 0x2c);

            float x = m00 * fv4 + m01 * fv3 + m02 * fv5 + t0;
            float y = m10 * fv4 + m11 * fv3 + m12 * fv5 + t1;
            float z = m20 * fv4 + m21 * fv3 + m22 * fv5 + t2;

            float pos[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;

            float n1b = -g_8bfbe8;
            float n2b = -g_8bfbec;
            float n3b = -g_8bfbf0;
            float tmp5[3];
            tmp5[0] = n1b;
            tmp5[1] = n2b;
            tmp5[2] = n3b;
            float tmp6[3];
            sub_51D890(tmp5, pos, tmp6);

            float* res = (float*)sub_51D890(tmp5, pos, tmp6);
            float r0 = res[1];
            float r1 = res[2];
            float r2 = res[3];
            float r3 = res[4];
            float r4 = res[5];
            float r5 = res[6];

            float out2[3];
            out2[0] = w;
            out2[1] = r0;
            out2[2] = r1;

            void* edx = *(void**)((char*)humanoid + 0x198);
            void* ecx = *(void**)((char*)edx + 0x30);

            int rr = sub_5FFD30(ecx, out2, &out2[1], &this->field1c, &this->humanoid, 0, 0);
            if (rr != 0) {
                if (sub_573D40((void*)rr) != 0)
                    return 0;
            }

            i += 2;
            if (i > 1) {
                j += 2;
                if (j > 1)
                    break;
                i = -1;
                fv2 = fv;
                continue;
            }
            fv2 = fv;
        }
        break;
    }

    return 0;
}
