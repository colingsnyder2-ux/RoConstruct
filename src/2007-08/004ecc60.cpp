// from server: 25% by colin
// roc 2007-08 004ecc60  unit: CylinderBuilder  size: 794 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ecc60

extern "C" double __stdcall ceil(double);

struct Vec3 {
    float x, y, z;
};

struct CylinderBuilder {
    char pad[0x10];
    unsigned int flags;
    void buildRight(int purpose, float a, float b, int c, int d, int e, int f);
};

extern "C" void __stdcall sub_5b9990(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, int, int, int);
extern "C" void __stdcall sub_4eb8a0(void*, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void CylinderBuilder::buildRight(int purpose, float a, float b, int c, int d, int e, int f)
{
    unsigned int v = (this->flags >> 3) & 7;
    float local3c;
    float local38;
    sub_5b9990(&local3c, &this->pad[4]);

    float fa = a < 0.0f ? -a : a;
    float fb = local3c < 0.0f ? -local3c : local3c;
    float fc = local38 < 0.0f ? -local38 : local38;

    float f1 = fa;
    float f2 = fb;
    float f3 = fc;

    int eq = (f1 == f3) ? 1 : 0;
    int ne = eq ? 0 : 1;

    int count;
    if (purpose == 0 && v != 0) {
        float tmp = f2 * (float)g_795b48;
        count = (int)ceil(tmp);
    } else {
        count = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;

    short val = *(short*)((char*)&local3c + 0x1e);
    int q = (int)val / count;
    short qs = (short)q;
    if (qs <= 1) {
        qs = 1;
    }
    arr[ne] = qs;

    float fv = f3;
    float fw = f2;

    Vec3 v1;
    Vec3 v2;
    sub_50b010(&v1, &local38);
    v1.x = -v1.x;
    v1.y = -v1.y;
    sub_50b010(&v2, &local3c);

    float f0 = 0.0f;
    float fA = f0, fB = f0, fC = f0, fD = f0;

    int mode = e;
    if (mode == 0) {
        if (v == 0) {
            fA = g_787050;
            fB = g_797e9c;
            fC = fB;
        } else {
            fB = sub_4de980(v);
            fA = fB * 2.0f;
            fC = g_797e9c;
            if (ne == 1) {
                fC = -fC;
            }
        }
    } else if (mode == 1) {
        fA = f0;
        fB = *(float*)((char*)this + 0x1c);
        fC = *(float*)((char*)this + 0x18);
        fD = -*(float*)((char*)this + 0x1c);
    } else if (mode == 2) {
        fA = f0;
        fB = f0;
        fC = f0;
        fD = f0;
    } else {
        fA = f0;
        fB = f0;
        fC = f0;
        fD = f0;
    }

    int i = 0;
    while (i < count) {
        float fv2;
        if (i == count - 1) {
            fv2 = f2;
            if (e == 0 && d != 0) {
                fv2 = (fv2 - f3) * (float)g_79f348 * fC;
            }
        } else {
            fv2 = f3 + (float)g_79f340;
        }

        float args[2];
        args[0] = fC;
        args[1] = fD;

        Vec3 vv;
        vv.x = fA;
        vv.y = fB;

        sub_4e0180(&vv, &vv, &vv, &vv, &vv, purpose, ne, 0);
        sub_4eb8a0(&vv, f);
        f3 = fv2;
        i++;
    }
}
