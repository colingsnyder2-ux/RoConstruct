// from server: 32% by colin
// roc 2007-08 004ed8f0  unit: CylinderBuilder  size: 802 bytes
// library rbxgs-view/CylinderMesh.cpp

extern "C" double __stdcall ceil(double);

struct CylinderBuilder {
    char pad0[4];
    void* field4;
    char pad8[8];
    unsigned int field10;
    char pad14[0x40];
    void buildTop(int purpose, float a, float b, float c, int d);
};

extern "C" void __stdcall sub_5b9a10(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4ec5c0(void*, void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void CylinderBuilder::buildTop(int purpose, float a, float b, float c, int d)
{
    float v38, v3c, v44, v48, v4c;
    float f18, f1c, f10;
    int ebx, ebp, esi;
    unsigned short w10, w12;
    float arr30[2];
    float arr38[2];
    float arr1c[2];
    float arr20[2];
    float arr28[2];
    float arr2c[2];
    float arr44[2];
    float arr48[2];
    float arr4c[2];
    float tmp;
    int i;

    ebx = (this->field10 >> 15) & 7;

    sub_5b9a10(&this->field4, &v3c);

    f18 = a;
    if (f18 < 0) f18 = -f18;
    f1c = f18;

    ebp = d;
    f10 = v3c;
    if (f10 < 0) f10 = -f10;
    v44 = f10;

    f10 = v38;
    if (f10 < 0) f10 = -f10;
    v48 = f10;

    v4c = f1c;

    if (ebp == 0) {
        if (v48 == v44) {
            esi = 0;
        } else {
            esi = 1;
        }
    } else {
        esi = 1;
    }

    if (ebp == 0 && ebx != 0) {
        tmp = arr44[esi] * (float)g_795b48;
        ebp = (int)ceil((double)tmp);
    } else {
        ebp = 1;
    }

    w10 = 0;
    w12 = 0;

    {
        unsigned short val = *(unsigned short*)((char*)&w10 + 2 - esi*2);
        int q = (int)(short)val / ebp;
        unsigned short qq = (unsigned short)q;
        if ((short)qq > 1) {
            w10 = qq;
        } else {
            w10 = 1;
        }
    }

    arr1c[esi] = v4c;

    {
        float t;
        sub_50b010(&v3c, &t);
        arr4c[esi] = -t;
        arr48[esi] = -v48;
        arr44[esi] = v48;
    }

    {
        float t2;
        sub_50b010(&v3c, &t2);
        arr2c[esi] = -t2;
        arr28[esi] = -v48;
        arr20[esi] = -v48;
    }

    switch (purpose) {
    case 0:
        if (ebx == 0) {
            arr28[esi] = g_787050;
            arr2c[esi] = g_797e9c;
            arr1c[esi] = arr2c[esi];
        } else {
            arr2c[esi] = 0.0f;
            arr2c[esi] = sub_4de980(ebx);
            arr28[esi] = arr2c[esi] * 2.0f;
            arr1c[esi] = g_797e9c;
            if (esi == 1) {
                arr1c[esi] = -arr1c[esi];
            }
        }
        break;
    case 1:
        arr28[esi] = 0.0f;
        arr2c[esi] = 0.0f;
        arr1c[esi] = 0.0f;
        arr20[esi] = 0.0f;
        break;
    case 2:
        arr28[esi] = 0.0f;
        arr2c[esi] = 0.0f;
        arr1c[esi] = 0.0f;
        arr20[esi] = 0.0f;
        break;
    default:
        break;
    }

    for (i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            arr30[esi] = arr44[esi];
            if (d == 0 && arr20[esi] != 0.0f) {
                arr1c[esi] = (arr30[esi] - arr38[esi]) * (float)g_79f348 * arr1c[esi];
            }
        } else {
            arr30[esi] = arr38[esi] + (float)g_79f340;
        }

        {
            float p1 = arr1c[esi];
            float p2 = arr28[esi];
            float p3 = arr2c[esi];
            float p4 = arr20[esi];
            float p5 = arr30[esi];
            sub_4e0180(&p1, &p2, &p3, &p4, &p5);
        }

        sub_4ec5c0(this->field4, (void*)purpose, (void*)esi);
        arr38[esi] = arr30[esi];
    }
}
