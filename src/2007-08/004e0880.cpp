// from server: 29% by colin
// roc 2007-08 004e0880  unit: RBX::Render::Mesh::Level  size: 816 bytes

extern "C" double __stdcall ceil(double);
extern "C" float __stdcall fabsf(float);

struct Vec3 { float x, y, z; };

struct Level {
    char pad0[0x10];
    unsigned int flags;
    void method(float a, float b, float c, int d, int e);
};

extern "C" void __stdcall sub_5b99d0(void*, void*);
extern "C" void* __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4df280(void*, float, float, short);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, int, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void Level::method(float a, float b, float c, int d, int e)
{
    unsigned int v = flags;
    unsigned int idx = (v >> 9) & 7;

    float local38;
    float local3c;
    sub_5b99d0(&local3c, &flags);

    float fabsA = fabsf(a);
    float fabsB = fabsf(b);
    float fabsC = fabsf(c);

    float t1 = fabsA;
    float t2 = fabsB;
    float t3 = fabsC;

    bool cond;
    if (e == 0) {
        cond = (t3 == t2);
    } else {
        cond = false;
    }
    int esi = cond ? 0 : 1;

    int ebp;
    if (e == 0 && idx != 0) {
        float arr[2];
        arr[0] = t1;
        arr[1] = t2;
        float val = arr[esi];
        float scaled = val * (float)g_795b48;
        float ceiled = (float)ceil((double)scaled);
        ebp = (int)ceiled;
    } else {
        ebp = 1;
    }

    short buf[2];
    buf[0] = 0;
    buf[1] = 0;

    short* p = (short*)((char*)buf + 2 - esi * 2);
    short sval = *p;
    int s = (int)sval;
    int q = s / ebp;
    int one = 1;
    unsigned short qq = (unsigned short)q;
    unsigned int cmpv = qq;
    int* sel = (cmpv > 1) ? (int*)&cmpv : &one;
    short chosen = *(short*)sel;
    buf[esi] = chosen;
    *p = sval;

    float local18 = t3;

    Vec3 v1;
    sub_50b010(&v1, &local38);
    float n1x = -v1.x;
    float n1y = -v1.y;
    float n1z = -v1.z;

    Vec3 v2;
    sub_50b010(&v2, &local38);

    float f0 = 0.0f;
    float r28 = f0, r2c = f0, r1c = f0, r20 = f0;

    int mode = d;
    if (mode == 0) {
        if (idx == 0) {
            r28 = g_787050;
            r2c = g_797e9c;
            r1c = g_797e9c;
            r20 = g_797e9c;
        } else {
            r2c = n1z;
            float tmp = sub_4de980(idx);
            r2c = tmp;
            r1c = n1x * 2.0f;
            r20 = g_797e9c;
            if (esi == 1) {
                r1c = -r1c;
            }
        }
    } else if (mode == 1) {
        r28 = f0;
        r2c = n1z;
        r1c = n1x;
        r20 = -n1z;
    } else if (mode == 2) {
        r28 = f0;
        r2c = f0;
        r1c = f0;
        r20 = f0;
    }

    int i = 0;
    if (ebp > 0) {
        short bx = *(short*)((char*)&local38 + 0x24);
        do {
            if (i == ebp - 1) {
                float val = t1;
                if (d == 0 && *(int*)&r28 != 0) {
                    val = (val - r1c) * (float)g_79f348 * r20;
                }
                r1c = val;
            } else {
                r2c = r1c + (float)g_79f340;
            }

            float args[2];
            args[0] = r1c;
            args[1] = r2c;

            float args2[2];
            args2[0] = r28;
            args2[1] = r2c;

            sub_4e0180(&v1, &v2, args2, args, d, esi);
            sub_4df280(&v2, r1c, r2c, bx);
            r1c = r2c;
            i++;
        } while (i < ebp);
    }
}
