// from server: 22% by colin
// roc 2007-08 004e5e80  unit: WedgeBuilder  size: 799 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e5e80

extern "C" double __stdcall ceil(double);
extern "C" float __cdecl fabsf(float);

struct Vec3 {
    float x, y, z;
};

struct WedgeBuilder {
    char pad[0x10];
    int field_10;
    void build(int a, int b, int c, int d);
};

extern "C" void __stdcall sub_5b9970(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4e4ea0(void*, void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void WedgeBuilder::build(int a, int b, int c, int d)
{
    float v38, v3c, v40, v44, v48, v4c;
    float v18, v1c, v10, v20, v24, v28, v2c, v30;
    int v5c;
    short v10w, v12w;
    int ebx, ebp, esi, edi;
    int i;

    sub_5b9970(&field_10, &v3c);

    v18 = fabsf(v48);
    v1c = v18;
    v10 = fabsf(v3c);
    v18 = v10;
    v10 = fabsf(v38);
    v44 = v10;

    ebx = field_10 & 7;
    ebp = d;
    edi = 0;

    {
        float fa = v18;
        float fc = v44;
        int eq;
        if (ebp == 0) {
            eq = (fa == fc);
        } else {
            eq = 0;
        }
        esi = eq ? 0 : 1;
    }

    if (ebp == 0 && ebx != 0) {
        float t = (&v44)[esi] * (float)g_795b48;
        ebp = (int)ceil((double)t);
    } else {
        ebp = 1;
    }

    v10w = 0;
    v12w = 0;

    {
        short* p = (short*)((char*)&v10w + 0x4e - esi * 2);
        short val = *p;
        int q = (int)val / ebp;
        int one = 1;
        short qs = (short)q;
        v5c = qs;
        if (qs > 1) {
            *(short*)((char*)&v10w + esi * 2) = *(short*)&v5c;
        } else {
            *(short*)((char*)&v10w + esi * 2) = *(short*)&one;
        }
        *(short*)((char*)&v12w - esi * 2) = val;
    }

    v18 = v4c;

    sub_50b010(&v38, &v48);
    v5c = (int)(-v48);
    v20 = -v4c;
    v3c = v5c;
    v40 = v20;

    sub_50b010(&v38, &v30);

    v28 = 0.0f;
    v2c = 0.0f;
    v1c = 0.0f;
    v20 = 0.0f;

    switch (c) {
    case 0:
        if (ebx == 0) {
            v28 = g_787050;
            v2c = g_797e9c;
            *(float*)((char*)&v1c + esi * 4) = v28;
            *(float*)((char*)&v1c + esi * 4) = v2c;
        } else {
            *(float*)((char*)&v2c + esi * 4) = 0.0f;
            v2c = sub_4de980(ebx);
            *(float*)((char*)&v20 + esi * 4) = v2c * 2.0f;
            *(float*)((char*)&v1c + esi * 4) = g_797e9c;
            if (esi == 1) {
                v1c = -v1c;
            }
        }
        break;
    case 1:
        v2c = *(float*)((char*)&field_10 + 0x1c);
        v1c = *(float*)((char*)&field_10 + 0x18);
        v20 = -v2c;
        break;
    case 2:
        break;
    }

    for (i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            v5c = (int)(&v44)[esi];
            *(float*)((char*)&v30 + esi * 4) = (float)v5c;
            if (c == 0 && v24 != 0) {
                *(float*)((char*)&v1c + esi * 4) =
                    ((float)v5c - *(float*)((char*)&v38 + esi * 4)) *
                    (float)g_79f348 * *(float*)((char*)&v1c + esi * 4);
            }
        } else {
            *(float*)((char*)&v30 + esi * 4) =
                *(float*)((char*)&v38 + esi * 4) + (float)g_79f340;
        }

        sub_4e0180(&v1c, &v20, &v30, &v3c, &v40, &v10w);
        sub_4e4ea0(&v10w, &v3c, &v40);
        *(float*)((char*)&v38 + esi * 4) = *(float*)((char*)&v30 + esi * 4);
    }
}
