// from server: 32% by colin
// roc 2007-08 004e61a0  unit: WedgeBuilder  size: 802 bytes
// library rbxgs-view/WedgeMesh.cpp

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct WedgeBuilder {
    char pad0[0x10];
    int field10;
    void buildSide(int a, int b, int c, int d);
};

extern "C" int __stdcall sub_5b9990(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e51b0(void*, int, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void WedgeBuilder::buildSide(int a, int b, int c, int d)
{
    int v10 = this->field10;
    int ebx = (v10 >> 3) & 7;

    float f38;
    float f3c;
    sub_5b9990(&f3c, &f38);

    float fa = f38;
    float fb = f3c;

    float absA = (float)(fa < 0 ? -fa : fa);
    float absB = (float)(fb < 0 ? -fb : fb);

    float f44 = absA;
    float f48 = absB;
    float f4c = absB;

    int esi;
    {
        bool eq = (absA == absB);
        esi = eq ? 0 : 1;
    }

    int ebp;
    if (d == 0 && ebx != 0) {
        float t = f44 * (float)g_795b48;
        t = (float)ceil((double)t);
        ebp = (int)t;
    } else {
        ebp = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;

    short val = *(short*)((char*)arr + (esi * 2));
    int q = (int)val / ebp;
    short qs = (short)q;
    int one = 1;
    short* psel = (qs > 1) ? &qs : (short*)&one;
    short sel = *psel;
    *(short*)((char*)arr + (esi * 2)) = sel;

    float f18 = f4c;

    Vec3 v1;
    Vec3 v2;
    sub_50b010(&f38, &v1);
    v1.x = -v1.x;
    v1.y = -v1.y;
    sub_50b010(&f38, &v2);

    float f28 = 0.0f;
    float f2c = 0.0f;
    float f1c = 0.0f;
    float f20 = 0.0f;

    int mode = c;
    if (mode == 0) {
        if (ebx == 0) {
            f28 = g_787050;
            f2c = g_797e9c;
            f1c = g_797e9c;
        } else {
            f2c = sub_4de980(ebx);
            f1c = f2c + f2c;
            f20 = g_797e9c;
            if (esi == 1) {
                f1c = -f1c;
            }
        }
    } else if (mode == 1) {
        f2c = this->field10;
        f1c = this->field10;
        f20 = -this->field10;
    } else if (mode == 2) {
        // keep zeros
    }

    int i = 0;
    if (ebp > 0) {
        int ebx2 = a;
        do {
            if (i == ebp - 1) {
                float f5c = f44;
                float f30 = f5c;
                if (d == 0 && f20 != 0.0f) {
                    f1c = (f5c - f20) * (float)g_79f348 * f1c;
                }
            } else {
                float f30 = f20 + (float)g_79f340;
                f30 = f30;
            }

            float f1c_val = f1c;
            float f30_val = f20;
            float f2c_val = f2c;

            Vec3 vv;
            sub_4e0180(&vv, &v1, &v2, &f1c_val, &f30_val, &f2c_val);

            sub_4e51b0((void*)c, ebx2, (int)&vv);

            f20 = f30_val;
            i++;
        } while (i < ebp);
    }
}
