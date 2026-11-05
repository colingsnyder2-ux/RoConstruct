// from server: 31% by colin
// roc 2007-08 004edc20  unit: CylinderBuilder  size: 802 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004edc20

extern "C" __declspec(dllimport) double __stdcall ceil(double);
extern "C" float __cdecl fabsf(float);

struct CylinderBuilder {
    char pad0[0x10];
    unsigned int flags;
    void buildSide(int a, int b, int c, int d);
};

extern "C" void __cdecl sub_5b99b0(void*, void*);
extern "C" void __cdecl sub_50b010(void*, void*);
extern "C" void __cdecl sub_4de980(float, int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4ec910(void*, void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void CylinderBuilder::buildSide(int a, int b, int c, int d)
{
    float v38, v3c, v44, v48, v4c;
    float f18, f1c, f10;
    int nSeg, nRing, i;
    unsigned short w10, w12;
    float f28, f2c, f1c2, f20;
    float f30[2], f38[2];
    float f5c;
    int nMode;

    sub_5b99b0(&v3c, &this->flags + 1);
    v48 = fabsf(*(float*)((char*)&a + 4));
    v4c = v48;
    v3c = fabsf(v3c);
    v38 = fabsf(v38);
    v44 = v38;
    f18 = v3c;
    f1c = v4c;
    f10 = v44;

    nMode = d;
    if (nMode == 0) {
        if (f10 == f1c) {
            nSeg = 1;
        } else {
            nSeg = 0;
        }
    } else {
        nSeg = 0;
    }

    if (nMode == 0 && this->flags != 0) {
        float t = f10 * (float)g_795b48;
        t = (float)ceil((double)t);
        nRing = (int)t;
    } else {
        nRing = 1;
    }

    w10 = 0;
    w12 = 0;
    {
        unsigned short v = *(unsigned short*)((char*)&w10 + nSeg * 2);
        int sv = (int)(short)v;
        int q = sv / nRing;
        w10 = (unsigned short)q;
        if ((short)q <= 1) {
            w10 = 1;
        }
    }
    *(unsigned short*)((char*)&w10 + nSeg * 2) = w10;

    f18 = f1c;
    sub_50b010(&v3c, &v38);
    f5c = -v3c;
    f20 = -v38;
    f28 = 0.0f;
    f2c = 0.0f;
    f1c2 = 0.0f;
    f20 = 0.0f;

    if (nMode == 0) {
        if (this->flags == 0) {
            f28 = g_787050;
            f2c = g_797e9c;
            f1c2 = g_797e9c;
        } else {
            sub_4de980(0.0f, this->flags);
            f2c = f2c * 2.0f;
            f1c2 = g_797e9c;
            if (nSeg == 1) {
                f1c2 = -f1c2;
            }
        }
    } else if (nMode == 1) {
        f2c = *(float*)((char*)this + 0x1c);
        f1c2 = *(float*)((char*)this + 0x18);
        f20 = -*(float*)((char*)this + 0x1c);
    } else if (nMode == 2) {
        f28 = 0.0f;
        f2c = 0.0f;
        f1c2 = 0.0f;
        f20 = 0.0f;
    }

    for (i = 0; i < nRing; i++) {
        if (i == nRing - 1) {
            f5c = f10;
            f30[nSeg] = f5c;
            if (nMode != 0 && f28 != 0.0f) {
                f1c2 = (f5c - f38[nSeg]) * (float)g_79f348 * f1c2;
            }
        } else {
            f30[nSeg] = f38[nSeg] + (float)g_79f340;
        }

        sub_4e0180(&f1c2, &f2c, &f28, &f20, &f5c);
        sub_4ec910(&f5c, &f30[nSeg], &f38[nSeg]);
        f38[nSeg] = f30[nSeg];
    }
}
