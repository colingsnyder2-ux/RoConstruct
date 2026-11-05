// from server: 26% by colin
// roc 2007-08 004e2cb0  unit: PBBBuilder  size: 794 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e2cb0

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct PBBBuilder {
    char pad0[0x10];
    unsigned int flags;
    int method(int a, int b, int c);
};

extern "C" int __stdcall sub_5b9990(void*, void*);
extern "C" Vec3* __stdcall sub_50b010(Vec3* out, Vec3* in);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e2030(void*, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

int PBBBuilder::method(int a, int b, int c)
{
    float fbuf[16];
    short sbuf[8];
    int ibuf[8];
    Vec3 v1, v2;
    float f0, f1, f2, f3;
    int n, i, m;
    unsigned int t;

    t = (this->flags >> 3) & 7;
    sub_5b9990(&this->pad0[0], &fbuf[0]);

    f0 = (float)ceil((double)(fbuf[0] < 0 ? -fbuf[0] : fbuf[0]));
    (void)f0;

    n = c;
    i = 0;

    f1 = fbuf[0] < 0 ? -fbuf[0] : fbuf[0];
    f2 = fbuf[1] < 0 ? -fbuf[1] : fbuf[1];
    f3 = fbuf[2] < 0 ? -fbuf[2] : fbuf[2];

    if (n == 0 && f3 == f2) {
        m = 1;
    } else {
        m = 1;
    }

    if (n == 0 && t != 0) {
        float tmp = fbuf[0] * (float)g_795b48;
        tmp = (float)ceil((double)tmp);
        n = (int)tmp;
    } else {
        n = 1;
    }

    sbuf[0] = 0;
    sbuf[1] = 0;

    {
        short val = *(short*)((char*)sbuf + 2 - (i + i));
        int q = (int)val / n;
        ibuf[0] = 1;
        unsigned short uq = (unsigned short)q;
        if ((short)uq > 1) {
            ibuf[0] = uq;
        }
        *(short*)((char*)sbuf + (i + i)) = (short)ibuf[0];
    }

    v1 = *(Vec3*)&fbuf[0];
    v1.x = -v1.x;
    v1.y = -v1.y;
    v2 = v1;
    sub_50b010(&v2, &v1);

    f0 = 0.0f;
    f1 = 0.0f;
    f2 = 0.0f;
    f3 = 0.0f;

    switch (c) {
    case 0:
        if (t == 0) {
            f0 = g_787050;
            f1 = g_797e9c;
            f2 = f1;
            f3 = f1;
        } else {
            f0 = 0.0f;
            f1 = sub_4de980(t);
            f2 = f1 + f1;
            f3 = g_797e9c;
            if (i == 1) {
                f2 = -f2;
            }
        }
        break;
    case 1:
        f0 = 0.0f;
        f1 = v1.z;
        f2 = v1.y;
        f3 = -v1.z;
        break;
    case 2:
        f0 = 0.0f;
        f1 = 0.0f;
        f2 = 0.0f;
        f3 = 0.0f;
        break;
    default:
        break;
    }

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            f0 = fbuf[0];
            fbuf[4] = f0;
            if (c == 0 && ibuf[0] != 0) {
                f0 = f0 - fbuf[1];
                f0 = f0 * (float)g_79f348;
                f0 = f0 * fbuf[2];
                fbuf[2] = f0;
            }
        } else {
            f0 = fbuf[1] + (float)g_79f340;
            fbuf[4] = f0;
        }

        sub_4e0180(&v2, &v1, &f0, &f1, &f2, &f3, &fbuf[0], &fbuf[1], &fbuf[2]);
        sub_4e2030(&v2, a);
        fbuf[1] = fbuf[4];
    }

    return 0;
}
