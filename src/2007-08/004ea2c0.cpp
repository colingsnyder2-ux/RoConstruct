// from server: 25% by colin
// roc 2007-08 004ea2c0  unit: TorsoMesh  size: 794 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ea2c0

extern "C" __declspec(dllimport) double __stdcall ceil(double);

struct TorsoBuilder {
    char pad[0x10];
    unsigned int flags;
    void build(int a, int b, int c);
};

extern "C" void __stdcall sub_5b9a10(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, int, int);
extern "C" void __stdcall sub_4e8fc0(void*, int);

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern float g_79f340;
extern float g_79f348;

void TorsoBuilder::build(int a, int b, int c)
{
    float v38, v3c, v44, v48, v4c;
    float f18, f1c, f10;
    float f28, f2c, f1c2, f20;
    float f30[2], f38[2];
    short s10[2];
    int n1c;
    int ebp;
    int esi;
    int i;
    int tmp;

    sub_5b9a10(&this->flags, &v3c);

    f18 = *(float*)((char*)&a + 0);
    if (f18 < 0.0f) f18 = -f18;
    f1c = f18;
    f10 = v3c;
    if (f10 < 0.0f) f10 = -f10;
    f18 = f10;
    f10 = v38;
    if (f10 < 0.0f) f10 = -f10;
    v44 = f10;

    v48 = f18;
    v4c = f1c;

    if (b == 0) {
        if (v44 == f18) {
            esi = 1;
        } else {
            esi = 0;
        }
    } else {
        esi = 0;
    }

    if (b == 0 && this->flags != 0) {
        float t = v44 * g_795b48;
        t = (float)ceil(t);
        ebp = (int)t;
    } else {
        ebp = 1;
    }

    s10[0] = 0;
    s10[1] = 0;

    tmp = (short)((short)((short*)&v48)[-esi] / ebp);
    n1c = 1;
    if ((short)tmp > 1) {
        ((short*)s10)[esi] = (short)tmp;
    } else {
        ((short*)s10)[esi] = 1;
    }

    f18 = v4c;

    sub_50b010(&v3c, &v38);
    f28 = -v38;
    f2c = -v3c;
    f1c2 = f28;
    f20 = f2c;

    sub_50b010(&v3c, &v38);

    if (c == 0) {
        if (this->flags == 0) {
            f28 = g_787050;
            f2c = g_797e9c;
            f1c2 = f2c;
        } else {
            f2c = sub_4de980(this->flags);
            f1c2 = f2c * 2.0f;
            f20 = g_797e9c;
            if (esi == 1) {
                f1c2 = -f1c2;
            }
        }
    } else if (c == 1) {
        f28 = 0.0f;
        f2c = *(float*)((char*)&a + 0x1c);
        f1c2 = *(float*)((char*)&a + 0x18);
        f20 = -*(float*)((char*)&a + 0x1c);
    } else if (c == 2) {
        f28 = 0.0f;
        f2c = 0.0f;
        f1c2 = 0.0f;
        f20 = 0.0f;
    }

    for (i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            f30[esi] = v44;
            if (c == 0 && f28 != 0.0f) {
                f1c2 = (f30[esi] - f38[esi]) * g_79f348 * f1c2;
            }
        } else {
            f30[esi] = f38[esi] + g_79f340;
        }

        sub_4e0180(&f1c2, &f20, &f28, &f2c, esi, s10[0]);
        sub_4e8fc0(&v3c, s10[0]);
        f38[esi] = f30[esi];
    }
}
