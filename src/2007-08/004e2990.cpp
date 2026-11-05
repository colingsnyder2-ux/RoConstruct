// from server: 32% by colin
extern "C" __declspec(dllimport) double __stdcall ceil(double);

struct PBBBuilder {
    char pad[0x10];
    unsigned int flags;
    void Build(int a, int b, int c, int d);
};

extern "C" void __cdecl sub_5B9970(void* out, const void* in);
extern "C" void* __cdecl sub_50B010(void* out, const void* in);
extern "C" float __cdecl sub_4DE980(int count);
extern "C" void __cdecl sub_4E0180(void* a, void* b, void* c, float d, float e, int f, int g);
extern "C" void __cdecl sub_4E1D20(void* self, int a, int b);

extern float g_787050;
extern float g_797E9C;
extern double g_795B48;
extern double g_79F340;
extern double g_79F348;

void PBBBuilder::Build(int a, int b, int c, int d)
{
    float v44, v48, v4C;
    float v10, v18, v1C;
    float v28, v2C, v30, v38;
    float v5C;
    float v3C, v40;
    float f20;
    int ebp;
    int esi;
    int edi;
    int ebx;
    int i;
    float f;
    unsigned short w10;
    unsigned short w12;
    unsigned short w5C;
    unsigned short w1C;

    ebx = this->flags & 7;

    sub_5B9970(&v44, (char*)this + 4);

    v18 = (float)ceil((double)(v44 < 0 ? -v44 : v44));
    v1C = v18;
    v10 = (float)ceil((double)(v48 < 0 ? -v48 : v48));
    v18 = v10;
    v10 = (float)ceil((double)(v4C < 0 ? -v4C : v4C));
    v44 = v10;

    v48 = v18;
    v4C = v1C;

    if (d != 0) {
        if (v44 == v18) {
            esi = 0;
        } else {
            esi = 1;
        }
    } else {
        esi = 1;
    }

    if (d == 0 && ebx != 0) {
        f = v44 * (float)g_795B48;
        ebp = (int)ceil((double)f);
    } else {
        ebp = 1;
    }

    w10 = 0;
    w12 = 0;

    edi = *(short*)((char*)&w10 + esi * 2);
    w5C = (unsigned short)((short)edi / ebp);
    if ((short)w5C > 1) {
        w1C = w5C;
    } else {
        w1C = 1;
    }
    *(unsigned short*)((char*)&w10 + esi * 2) = w1C;

    v18 = v4C;

    sub_50B010(&v3C, &v44);
    v5C = -v3C;
    f20 = -v40;
    v3C = v5C;
    v40 = f20;

    sub_50B010(&v3C, &v44);

    v28 = 0.0f;
    v2C = 0.0f;
    v1C = 0.0f;
    v30 = 0.0f;

    switch (c) {
    case 0:
        if (ebx == 0) {
            v28 = g_787050;
            v2C = g_797E9C;
            v1C = g_797E9C;
        } else {
            v2C = sub_4DE980(ebx);
            v1C = v2C * 2.0f;
            v30 = g_797E9C;
            if (esi == 1) {
                v1C = -v1C;
            }
        }
        break;
    case 1:
        v28 = 0.0f;
        v2C = v3C;
        v1C = v40;
        v30 = -v3C;
        break;
    case 2:
        break;
    }

    for (i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            v38 = v44;
            v30 = v44;
            if (d == 0 && v1C != 0.0f) {
                v1C = (v44 - v48) * (float)g_79F348 * v1C;
            }
        } else {
            v30 = v48 + (float)g_79F340;
        }

        sub_4E0180(&w10, &v48, &v44, v30, v1C, v28, esi);
        sub_4E1D20(this, w10, ebx);
        v38 = v30;
    }
}
