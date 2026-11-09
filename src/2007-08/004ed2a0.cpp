// from server: 21% by colin
// roc 2007-08 004ed2a0  unit: CylinderBuilder  size: 802 bytes
// library rbxgs-view/CylinderMesh.cpp

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct CylinderBuilder {
    char pad0[0x10];
    unsigned int flags;
    char pad1[0x1c - 0x14];
    float f18;
    float f1c;
    char pad2[0x30 - 0x20];
    float f30;
    float f34;
    float f38;
    char pad3[0x44 - 0x3c];
    float f44;
    float f48;
    float f4c;
    char pad4[0x58 - 0x50];
    int i58;
    char pad5[0x60 - 0x5c];
    int i60;

    void func(float a, float b, int c, int d);
};

extern "C" void __stdcall sub_5b99d0(void*, void*);
extern "C" void* __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(float, int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4ebf20(void*, int, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void CylinderBuilder::func(float a, float b, int c, int d)
{
    float v38, v3c, v40, v44, v48, v4c;
    float v10, v14, v18, v1c, v20, v24, v28, v2c;
    float v30, v34;
    short s10, s12;
    int v5c;
    int v1c_i;
    int i, n;
    int ebx;
    float fa, fb;

    sub_5b99d0(&v3c, &this->flags);

    ebx = (this->flags >> 9) & 7;

    v18 = a;
    if (v18 < 0) v18 = -v18;
    v1c = v18;
    v10 = v3c;
    if (v10 < 0) v10 = -v10;
    v18 = v10;
    v10 = v38;
    if (v10 < 0) v10 = -v10;
    v44 = v10;

    v48 = v18;
    v4c = v1c;

    {
        int eq;
        if (d == 0) {
            eq = (v44 == v18);
        } else {
            eq = 0;
        }
        int esi = (eq == 0) ? 1 : 0;

        if (d == 0 && ebx != 0) {
            float t = v44;
            t = (float)(t * g_795b48);
            t = (float)ceil((double)t);
            v1c = (int)t;
            n = v1c;
        } else {
            n = 1;
        }

        s10 = 0;
        s12 = 0;
        {
            short* p = (short*)((char*)&v48 + 0x16);
            p = (short*)((char*)p - esi * 2);
            short sv = *p;
            int q = (int)sv;
            q = q / n;
            v5c = (unsigned short)q;
            if ((short)q > 1) {
                s10 = *(short*)&v5c;
            } else {
                v1c_i = 1;
                s10 = *(short*)&v1c_i;
            }
            *(short*)((char*)&esi + s10 * 2) = sv;
        }

        v18 = v4c;

        {
            Vec3 tmp;
            sub_50b010(&v3c, &v38);
            v5c = -v3c;
            v20 = -v3c;
            v3c = v5c;
            v40 = v20;
            sub_50b010(&v3c, &v38);
        }

        v28 = 0; v2c = 0; v1c = 0; v20 = 0;

        if (c == 0) {
            if (ebx == 0) {
                v28 = g_787050;
                v2c = g_797e9c;
                *(float*)((char*)&v20 + esi * 4) = v2c;
            } else {
                v2c = 0;
                v2c = sub_4de980(v2c, ebx);
                v20 = v2c * 2.0f;
                *(float*)((char*)&v1c + esi * 4) = g_797e9c;
                if (esi == 1) {
                    v1c = -v1c;
                }
            }
        } else if (c == 1) {
            v28 = 0;
            v2c = this->f1c;
            v1c = this->f18;
            v20 = -this->f1c;
        } else if (c == 2) {
            v28 = 0; v2c = 0; v1c = 0; v20 = 0;
        } else {
            v28 = 0; v2c = 0; v1c = 0; v20 = 0;
        }

        for (i = 0; i < n; i++) {
            if (i == n - 1) {
                v5c = v44;
                v30 = v5c;
                if (d == 0 && v24 != 0) {
                    v1c = (v1c - v34) * (float)g_79f348 * v1c;
                }
            } else {
                v30 = v34 + (float)g_79f340;
            }

            {
                float p1 = v1c;
                float p2 = v28;
                float p3 = v2c;
                float p4 = v20;
                float p5 = v3c;
                sub_4e0180(&v3c, &v38, &p1, &p2, &p3, &p4);
            }

            sub_4ebf20((void*)this->i58, c, d);

            v34 = v30;
        }
    }
}
