// from server: 19% by colin
// roc 2007-08 004e2fd0  unit: PBBBuilder  size: 802 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e2fd0

extern "C" double __stdcall ceil(double);
extern "C" void __cdecl func_5b99d0(void*, void*);
extern "C" void __cdecl func_50b010(void*, void*);
extern "C" float __cdecl func_4de980(int);
extern "C" void __cdecl func_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl func_4e2330(void*, void*, void*);

struct PBBBuilder {
    char pad[0x10];
    unsigned int flags;
    void buildTop(float, float, int, int, int, int);
};

void PBBBuilder::buildTop(float a, float b, int c, int d, int e, int f) {
    unsigned int v = flags;
    unsigned int ebx = (v >> 9) & 7;
    float fabs_a = (a < 0.0f) ? -a : a;
    float fabs_b = (b < 0.0f) ? -b : b;
    float fabs_c = (c < 0.0f) ? -(float)c : (float)c;
    float fabs_d = (d < 0.0f) ? -(float)d : (float)d;
    float fabs_e = (e < 0.0f) ? -(float)e : (float)e;
    float fabs_f = (f < 0.0f) ? -(float)f : (float)f;

    float tmp1 = fabs_a;
    float tmp2 = fabs_b;
    float tmp3 = fabs_c;
    float tmp4 = fabs_d;
    float tmp5 = fabs_e;
    float tmp6 = fabs_f;

    int esi;
    if (d != 0) {
        if (fabs_c == fabs_d) {
            esi = 0;
        } else {
            esi = 1;
        }
    } else {
        esi = 1;
    }

    int ebp;
    if (d == 0 && ebx != 0) {
        float val = (esi == 0) ? fabs_c : fabs_d;
        double dval = (double)val * 0.0174532925199433;
        double cval = ceil(dval);
        ebp = (int)cval;
    } else {
        ebp = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;

    short val = *(short*)((char*)&arr[0] + (esi * 2));
    int div = (int)val / ebp;
    int cmp = (div > 1) ? div : 1;
    arr[esi] = (short)cmp;

    float f1 = fabs_e;
    float f2 = fabs_f;

    float vec1[3];
    float vec2[3];
    func_50b010(&fabs_c, vec1);
    vec1[0] = -vec1[0];
    vec1[1] = -vec1[1];
    vec1[2] = fabs_c;
    func_50b010(&fabs_d, vec2);

    float zero = 0.0f;
    float r1 = zero, r2 = zero, r3 = zero, r4 = zero;

    int mode = e;
    if (mode == 0) {
        if (ebx == 0) {
            r1 = *(float*)0x787050;
            r2 = *(float*)0x797e9c;
            r3 = r1;
            r4 = r2;
        } else {
            r1 = zero;
            r2 = func_4de980(ebx);
            r3 = r2 * 2.0f;
            r4 = *(float*)0x797e9c;
            if (esi == 1) {
                r3 = -r3;
            }
        }
    } else if (mode == 1) {
        r1 = zero;
        r2 = *(float*)((char*)this + 0x1c);
        r3 = *(float*)((char*)this + 0x18);
        r4 = -*(float*)((char*)this + 0x1c);
    } else if (mode == 2) {
        r1 = zero;
        r2 = zero;
        r3 = zero;
        r4 = zero;
    }

    int i = 0;
    while (i < ebp) {
        float fv;
        if (i == ebp - 1) {
            fv = fabs_e;
            vec1[esi] = fv;
            if (e == 0 && d != 0) {
                fv = fv - vec2[esi];
                fv = fv * 0.5f;
                fv = fv * r3;
                r3 = fv;
            }
        } else {
            fv = vec2[esi] + 0.5f;
            vec1[esi] = fv;
        }

        func_4e0180(&r3, &r4, &r1, &r2, &fabs_e, &fabs_f);
        func_4e2330(this, &r1, &r2);
        vec2[esi] = vec1[esi];
        i++;
    }
}
