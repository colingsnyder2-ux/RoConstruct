// from server: 25% by colin
// roc 2007-08 004e9c80  unit: TorsoMesh.cpp  size: 794 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" double __stdcall ceil(double);
extern "C" float __cdecl fabsf(float);

struct Vec3 {
    float x, y, z;
};

struct TorsoBuilder {
    char pad[0x10];
    unsigned int flags;
    void buildLeft(int a, int b, int c);
};

extern "C" void __stdcall sub_5b99d0(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e8900(void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void TorsoBuilder::buildLeft(int a, int b, int c)
{
    unsigned int v = this->flags;
    unsigned int ebx = (v >> 9) & 7;

    float f1;
    sub_5b99d0(&f1, &this->pad[4]);

    float fabs_a = fabsf(*(float*)&a);
    float fabs_b = fabsf(f1);
    float fabs_c = fabsf(*(float*)&b);

    float arr[2];
    arr[0] = fabs_b;
    arr[1] = fabs_a;

    bool cond;
    if (c == 0) {
        cond = (fabs_c == fabs_a);
    } else {
        cond = false;
    }
    int esi = cond ? 0 : 1;

    int ebp;
    if (c == 0 && ebx != 0) {
        float t = arr[esi] * (float)g_795b48;
        ebp = (int)ceil((double)t);
    } else {
        ebp = 1;
    }

    short s1 = 0;
    short s2 = 0;
    short s3 = 0;

    short val = (short)((signed short)s1 / ebp);
    if (val <= 1) {
        val = 1;
    }
    s3 = val;

    float f2 = fabs_c;
    float f3 = fabs_a;

    Vec3 v1;
    sub_50b010(&v1, &f2);
    float n1 = -v1.x;
    float n2 = -v1.y;

    Vec3 v2;
    sub_50b010(&v2, &f3);

    float zero = 0.0f;
    float r1 = zero, r2 = zero, r3 = zero, r4 = zero;

    if (c == 0) {
        if (ebx == 0) {
            r1 = g_787050;
            r2 = g_797e9c;
            r3 = r2;
            r4 = r1;
        } else {
            r1 = zero;
            r2 = sub_4de980(ebx);
            r3 = r2 * 2.0f;
            r4 = g_797e9c;
            if (esi == 1) {
                r3 = -r3;
            }
        }
    } else if (c == 1) {
        r1 = zero;
        r2 = *(float*)((char*)&v2 + 0x1c);
        r3 = *(float*)((char*)&v2 + 0x18);
        r4 = -r2;
    } else if (c == 2) {
        r1 = zero;
        r2 = zero;
        r3 = zero;
        r4 = zero;
    }

    int i = 0;
    while (i < ebp) {
        float fv;
        if (i == ebp - 1) {
            fv = arr[esi];
            if (c == 0 && r1 != 0.0f) {
                fv = (fv - r2) * (float)g_79f348 * r3;
            }
        } else {
            fv = r2 + (float)g_79f340;
        }

        float tmp1 = r3;
        float tmp2 = r4;

        Vec3 out;
        sub_4e0180(&out, &tmp1, &tmp2, &fv, &esi);

        sub_4e8900(&out, &a);

        r2 = r3;
        i++;
    }
}
