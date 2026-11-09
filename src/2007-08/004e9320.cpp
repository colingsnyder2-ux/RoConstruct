// from server: 24% by colin
// roc 2007-08 004e9320  unit: TorsoBuilder  size: 791 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e9320

extern "C" __declspec(dllimport) double __stdcall ceil(double);
extern "C" __declspec(dllimport) double __stdcall fabs(double);

struct Vec3 { float x, y, z; };

struct TorsoBuilder {
    char pad[0x10];
    unsigned int flags;
    void build(int a, int b, int c);
};

extern "C" void __stdcall sub_5b9970(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e7ee0(void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void TorsoBuilder::build(int a, int b, int c)
{
    float v44, v48, v4c;
    float v10, v18, v1c;
    float v28, v2c, v20;
    float v30, v38;
    unsigned short w10, w12;
    int i, n;
    int idx;
    float f;
    int mode;

    sub_5b9970(&this->flags, &v44);

    v18 = (float)fabs(v48);
    v1c = v18;
    v10 = (float)fabs(v44);
    v18 = v10;
    v10 = (float)fabs(v4c);
    v44 = v10;

    v48 = v18;
    v4c = v1c;

    if (b == 0) {
        if (v44 == v18) {
            idx = 1;
        } else {
            idx = 0;
        }
    } else {
        idx = 0;
    }

    if (b == 0 && this->flags != 0) {
        f = v44;
        f = (float)(f * g_795b48);
        f = (float)ceil(f);
        n = (int)f;
    } else {
        n = 1;
    }

    w10 = 0;
    w12 = 0;

    {
        short s = *(short*)((char*)&w10 + idx * 2);
        int q = s / n;
        int r = (q > 1) ? q : 1;
        *(short*)((char*)&w10 + idx * 2) = (short)r;
    }

    v18 = v4c;

    sub_50b010(&v44, &v28);
    v28 = -v28;
    v2c = -v2c;

    sub_50b010(&v44, &v20);

    v28 = 0.0f;
    v2c = 0.0f;
    v1c = 0.0f;
    v20 = 0.0f;

    mode = c;
    if (mode == 0) {
        if (this->flags == 0) {
            v28 = g_787050;
            v2c = g_797e9c;
            v1c = v28;
        } else {
            v2c = sub_4de980(this->flags);
            v20 = v1c * 2.0f;
            v1c = g_797e9c;
            if (idx == 1) {
                v1c = -v1c;
            }
        }
    } else if (mode == 1) {
        v2c = this->pad[0x1c];
        v1c = this->pad[0x18];
        v20 = -this->pad[0x1c];
    } else if (mode == 2) {
        v28 = 0.0f;
        v2c = 0.0f;
        v1c = 0.0f;
        v20 = 0.0f;
    }

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            v30 = v44;
            if (c == 0 && v20 != 0.0f) {
                v1c = (v30 - v38) * (float)g_79f348 * v1c;
            }
        } else {
            v30 = v38 + (float)g_79f340;
        }

        sub_4e0180(&v1c, &v20, &v28, &v2c, &v30, &v38);
        sub_4e7ee0(&v30, &v38);
        v38 = v30;
    }
}
