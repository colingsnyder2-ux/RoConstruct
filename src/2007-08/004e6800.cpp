// from server: 29% by colin
// roc 2007-08 004e6800  unit: WedgeBuilder  size: 802 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e6800

extern "C" double __stdcall ceil(double);

struct WedgeBuilder {
    char pad[0x10];
    unsigned int flags;
    void build(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern double g_79f340;
extern double g_79f348;

extern "C" void __cdecl sub_5b99d0(void*, void*);
extern "C" void __cdecl sub_50b010(void*, void*);
extern "C" float __cdecl sub_4de980(unsigned int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4e5830(void*, void*, void*);

void WedgeBuilder::build(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int v = (this->flags >> 9) & 7;
    float f0, f1, f2;
    sub_5b99d0(&f0, &this->pad[4]);
    float t0 = f0;
    if (t0 < 0) t0 = -t0;
    float t1 = t0;
    float t2 = f1;
    if (t2 < 0) t2 = -t2;
    float t3 = t2;
    float t4 = f2;
    if (t4 < 0) t4 = -t4;
    float t5 = t4;

    int esi;
    if (d != 0 && t3 == t5) {
        esi = 1;
    } else {
        esi = 0;
    }

    int ebp;
    if (d == 0 && v != 0) {
        float tmp = (esi ? t5 : t3) * g_795b48;
        ebp = (int)ceil((double)tmp);
    } else {
        ebp = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;
    short val = *(short*)((char*)&arr[0] + (esi * 2));
    int q = (int)val / ebp;
    short qs = (short)q;
    short one = 1;
    short* p = (qs > 1) ? &qs : &one;
    arr[esi] = *p;

    float fv = t5;
    float fv2 = t3;

    float v1x, v1y, v1z;
    sub_50b010(&v1x, &f0);
    float n1x = -v1x;
    float n1y = -v1y;
    float n1z = v1z;
    float v2x, v2y, v2z;
    sub_50b010(&v2x, &f0);
    float n2x = v2x;
    float n2y = v2y;
    float n2z = v2z;

    float r0 = 0, r1 = 0, r2 = 0, r3 = 0;
    if (c == 0) {
        if (v == 0) {
            r0 = g_787050;
            r1 = g_797e9c;
            r2 = 0;
            r3 = 0;
        } else {
            r0 = 0;
            r1 = 0;
            r2 = 0;
            r3 = 0;
            r1 = sub_4de980(v);
            r2 = g_797e9c;
            if (esi == 1) {
                r2 = -r2;
            }
        }
    } else if (c == 1) {
        r0 = 0;
        r1 = *(float*)&this->pad[0x1c];
        r2 = *(float*)&this->pad[0x18];
        r3 = -r1;
    } else if (c == 2) {
        r0 = 0;
        r1 = 0;
        r2 = 0;
        r3 = 0;
    }

    int i = 0;
    while (i < ebp) {
        float cur = t5;
        if (i == ebp - 1) {
            if (d == 0 && r0 != 0) {
                cur = (cur - r1) * g_79f348 * r2;
            }
        } else {
            cur = r1 + g_79f340;
        }

        float args[2];
        args[0] = r2;
        args[1] = r3;
        float args2[2];
        args2[0] = r0;
        args2[1] = r1;
        sub_4e0180(&args2, &args, &cur, &esi, &a, &b);
        sub_4e5830(&a, &b, &c);
        r1 = cur;
        i++;
    }
}
