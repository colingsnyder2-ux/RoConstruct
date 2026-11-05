// from server: 11% by colin
// roc 2007-08 004e64d0  unit: WedgeBuilder  size: 802 bytes
// library rbxgs-view/WedgeMesh.cpp

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct WedgeBuilder {
    char pad0[0x10];
    unsigned int flags;
    void buildSide(int a, int b, int c, int d);
};

extern "C" int __stdcall sub_5b99b0(void*, void*);
extern "C" void* __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e54f0(void*, int, int);

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern float g_79f340;
extern float g_79f348;

void WedgeBuilder::buildSide(int a, int b, int c, int d)
{
    float fbuf[8];
    short sbuf[8];
    int ibuf[8];
    float fv1, fv2, fv3, fv4;
    int n, i, j;
    unsigned int mode;
    float fa, fb, fc;
    float tmp;

    mode = (this->flags >> 6) & 7;

    sub_5b99b0(&this->pad0[4], &fbuf[0]);

    fa = fbuf[0];
    if (fa < 0) fa = -fa;
    fb = fbuf[1];
    if (fb < 0) fb = -fb;
    fc = fbuf[2];
    if (fc < 0) fc = -fc;

    fv1 = fa;
    fv2 = fb;
    fv3 = fc;

    n = 1;
    if (d == 0) {
        if (fv3 == 0.0f && fv1 == 0.0f) {
            n = 1;
        } else {
            n = 1;
        }
    }

    if (d == 0 && mode != 0) {
        tmp = (float)ceil((double)(fv1 * g_795b48));
        n = (int)tmp;
    } else {
        n = 1;
    }

    sbuf[0] = 0;
    sbuf[1] = 0;

    {
        int idx = (int)(short)((short*)&fbuf[0])[0];
        int q = idx / n;
        short qs = (short)q;
        if (qs > 1) {
            sbuf[0] = qs;
        } else {
            sbuf[0] = 1;
        }
    }

    fv4 = fv3;

    {
        Vec3 v;
        Vec3* pv;
        sub_50b010(&fbuf[0], &v);
        pv = &v;
        fbuf[4] = -pv->x;
        fbuf[5] = -pv->y;
        fbuf[6] = fv4;
        fbuf[7] = -pv->y;
    }

    {
        float z0 = 0.0f;
        float z1 = 0.0f;
        float z2 = 0.0f;
        float z3 = 0.0f;

        if (c == 0) {
            if (mode == 0) {
                z0 = g_787050;
                z1 = g_797e9c;
                z2 = z1;
                z3 = z1;
            } else {
                z0 = 0.0f;
                z1 = sub_4de980(mode);
                z2 = fbuf[4] * 2.0f;
                z3 = g_797e9c;
                if (n == 1) {
                    z2 = -z2;
                }
            }
        } else if (c == 1) {
            z0 = 0.0f;
            z1 = fbuf[5];
            z2 = fbuf[4];
            z3 = -fbuf[5];
        } else if (c == 2) {
            z0 = 0.0f;
            z1 = 0.0f;
            z2 = 0.0f;
            z3 = 0.0f;
        }

        fbuf[0] = z0;
        fbuf[1] = z1;
        fbuf[2] = z2;
        fbuf[3] = z3;
    }

    for (i = 0; i < n; i++) {
        float top, bot;
        if (i == n - 1) {
            top = fv1;
            fbuf[4] = top;
            if (d == 0 && fbuf[0] != 0.0f) {
                fbuf[0] = (top - fbuf[2]) * g_79f348 * fbuf[0];
            }
        } else {
            top = fbuf[2] + g_79f340;
            fbuf[4] = top;
        }

        {
            float p0 = fbuf[0];
            float p1 = fbuf[1];
            float p2 = fbuf[2];
            float p3 = fbuf[3];
            sub_4e0180(&p0, &p1, &p2, &p3, &fbuf[4]);
        }

        sub_4e54f0(&fbuf[0], a, b);
        fbuf[2] = fbuf[4];
    }
}
