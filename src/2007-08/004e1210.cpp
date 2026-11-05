// from server: 40% by colin
struct Vec3 { float x, y, z; };

struct Level {
    char pad0[0x10];
    unsigned int flags;
    void func(float a, float b, float c, float d, int e);
};

extern "C" {
    double __stdcall ceil(double);
    void __stdcall sub_5b99b0(void*, void*);
    void __stdcall sub_50b010(void*, void*);
    void __stdcall sub_4de980(int);
    void __stdcall sub_4dfdc0(void*, void*);
    void __stdcall sub_4e0180(void*, void*, void*, void*, void*, void*);
}

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern float g_79f340;
extern float g_79f348;

void Level::func(float a, float b, float c, float d, int e)
{
    unsigned int ebx = (flags >> 6) & 7;
    float v38, v3c;
    sub_5b99b0(&v38, &flags + 1);

    float f18 = a < 0 ? -a : a;
    float f1c = f18;
    float f10 = v38 < 0 ? -v38 : v38;
    float f18b = f10;
    float f10b = b < 0 ? -b : b;
    float f44 = f10b;
    float f48 = f18b;
    float f4c = f1c;

    int esi;
    if (e == 0 && f44 == f1c) {
        esi = 0;
    } else {
        esi = 1;
    }

    int ebp;
    if (e == 0 && ebx != 0) {
        float t = (esi ? f4c : f44);
        t = (float)(t * g_795b48);
        t = (float)ceil(t);
        ebp = (int)t;
    } else {
        ebp = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;
    short* p = (short*)((char*)&arr + 2 - esi * 2);
    short val = *p;
    int q = (int)val / ebp;
    int one = 1;
    unsigned short uq = (unsigned short)q;
    unsigned int cmpv = uq;
    short* sel;
    if ((short)uq > 1) {
        sel = (short*)&cmpv;
    } else {
        sel = (short*)&one;
    }
    short chosen = *sel;
    float f18c = f4c;
    *(short*)((char*)arr + esi * 2) = chosen;
    *(short*)((char*)&arr + 2 - esi * 2) = val;

    Vec3 tmp;
    sub_50b010(&tmp, &v38);
    float f60 = -tmp.x;
    float f20 = -tmp.y;
    float f3c = f60;
    float f40 = f20;
    Vec3 tmp2;
    sub_50b010(&tmp2, &v38);

    float f28 = 0, f2c = 0, f1c2 = 0, f20b = 0;
    int mode = e;
    if (mode == 0) {
        if (ebx == 0) {
            f28 = g_787050;
            f2c = g_797e9c;
            *(float*)((char*)&f20b - esi * 4) = f28;
            *(float*)((char*)&f1c2 + esi * 4) = f2c;
        } else {
            *(float*)((char*)&f2c - esi * 4) = f20b;
            sub_4de980(ebx);
            *(float*)((char*)&f2c + esi * 4) = 0;
            float t2 = *(float*)((char*)&f4c - esi * 4);
            t2 = t2 + t2;
            *(float*)((char*)&f20b - esi * 4) = t2;
            *(float*)((char*)&f1c2 + esi * 4) = g_797e9c;
            if (esi == 1) {
                f1c2 = -f1c2;
            }
        }
    } else if (mode == 1) {
        f2c = *(float*)((char*)&flags + 0x1c);
        f1c2 = *(float*)((char*)&flags + 0x18);
        f20b = -*(float*)((char*)&flags + 0x1c);
    } else if (mode == 2) {
        f28 = 0;
        f2c = 0;
        f1c2 = 0;
        f20b = 0;
    }

    int i = 0;
    if (ebp > 0) {
        short bx = *(short*)((char*)&arr + 0x4c);
        do {
            if (i == ebp - 1) {
                float t = *(float*)((char*)&f44 + esi * 4);
                *(float*)((char*)&f60 + esi * 4) = t;
                if (e == 0 && *(int*)((char*)&f20b + 0x24) != 0) {
                    float t2 = t - *(float*)((char*)&f3c + esi * 4);
                    t2 = t2 * g_79f348;
                    t2 = t2 * *(float*)((char*)&f1c2 + esi * 4);
                    *(float*)((char*)&f1c2 + esi * 4) = t2;
                }
            } else {
                float t = *(float*)((char*)&f3c + esi * 4);
                t = t + g_79f340;
                *(float*)((char*)&f60 + esi * 4) = t;
            }

            float f1c3 = *(float*)((char*)&f1c2 + esi * 4);
            float f20c = *(float*)((char*)&f20b + esi * 4);
            float f3c2 = *(float*)((char*)&f3c + esi * 4);
            float f40b = *(float*)((char*)&f40 + esi * 4);
            float f44b = *(float*)((char*)&f44 + esi * 4);
            float f48b = *(float*)((char*)&f48 + esi * 4);
            float f4cb = *(float*)((char*)&f4c + esi * 4);
            sub_4e0180(&f1c3, &f20c, &f3c2, &f40b, &f44b, &f48b);
            float f60b = *(float*)((char*)&f60 + esi * 4);
            sub_4dfdc0(&f60b, &f4cb);
            *(float*)((char*)&f3c + esi * 4) = f60b;
            i++;
        } while (i < ebp);
    }
}
