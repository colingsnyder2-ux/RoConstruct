// from server: 34% by colin
// roc 2007-08 004e0ee0  unit: RBX::Render::Mesh::Level  size: 816 bytes

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct Level {
    char pad0[0x10];
    unsigned int flags;
    void method(float a, float b, float c, int d, int e);
};

extern "C" void __cdecl sub_5b9a10(void*, void*);
extern "C" void* __cdecl sub_50b010(void*, void*);
extern "C" float __cdecl sub_4de980(int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4dfa00(void*, void*, void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void Level::method(float a, float b, float c, int d, int e)
{
    float local3c, local38;
    sub_5b9a10(&local3c, &this->pad0[0]);
    float fa = a < 0 ? -a : a;
    float fb = b < 0 ? -b : b;
    float fc = c < 0 ? -c : c;
    float f3c = local3c < 0 ? -local3c : local3c;
    float f38 = local38 < 0 ? -local38 : local38;

    unsigned int ebx = (this->flags >> 0xf) & 7;

    float arr[2];
    arr[0] = f3c;
    arr[1] = f38;

    int ebp;
    bool cond = (e == 0) && (f38 == fc);
    int esi = cond ? 0 : 1;

    if (e == 0 && ebx != 0) {
        float v = arr[esi];
        v = (float)(v * g_795b48);
        v = (float)ceil((double)v);
        ebp = (int)v;
    } else {
        ebp = 1;
    }

    short s10 = 0, s12 = 0;
    short* p = (short*)((char*)&s10 + 2 - esi * 2);
    short val = *p;
    int q = (int)val / ebp;
    int one = 1;
    unsigned short qq = (unsigned short)q;
    int cmpv = (int)qq;
    int* sel = (cmpv > 1) ? &cmpv : &one;
    short selv = *(short*)sel;
    *(short*)((char*)&s10 + esi * 2) = selv;
    *(short*)((char*)&s12 - esi * 2) = val;

    float f4c = arr[1];
    float tmp1 = f4c;
    float tmp2 = arr[0];

    Vec3 v1, v2;
    sub_50b010(&v1, &local3c);
    v1.x = -v1.x;
    v1.y = -v1.y;
    v1.z = -v1.z;
    sub_50b010(&v2, &local3c);
    v2.x = -v2.x;
    v2.y = -v2.y;
    v2.z = -v2.z;

    float r28 = 0, r2c = 0, r1c = 0, r20 = 0;

    int mode = d;
    if (mode == 0) {
        if (ebx == 0) {
            r28 = g_787050;
            r2c = g_797e9c;
            r1c = g_797e9c;
        } else {
            r2c = sub_4de980(ebx);
            r1c = arr[esi] * 2.0f;
            r20 = g_797e9c;
            if (esi == 1) r1c = -r1c;
        }
    } else if (mode == 1) {
        r28 = 0;
        r2c = this->pad0[0x1c];
        r1c = this->pad0[0x18];
        r20 = -this->pad0[0x1c];
    } else if (mode == 2) {
        r28 = 0;
        r2c = 0;
        r1c = 0;
        r20 = 0;
    }

    short bx = *(short*)((char*)&s10 + 0x4c);

    for (int i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            float v = arr[esi];
            float* p30 = (float*)((char*)&r28 + esi * 4);
            *p30 = v;
            if (d == 0 && *(int*)&r1c != 0) {
                float t = v - *(float*)((char*)&r1c + esi * 4);
                t = (float)(t * g_79f348);
                t = t * *(float*)((char*)&r1c + esi * 4);
                *(float*)((char*)&r1c + esi * 4) = t;
            }
        } else {
            float* p30 = (float*)((char*)&r28 + esi * 4);
            *p30 = *(float*)((char*)&r1c + esi * 4) + (float)g_79f340;
        }

        float f1c = *(float*)((char*)&r1c + esi * 4);
        float f38 = *(float*)((char*)&r28 + esi * 4);
        float f44 = arr[esi];

        sub_4e0180(&v1, &v2, &f1c, &f38, &f44, &r28, &r2c, &r1c);
        sub_4dfa00(&v1, &v2, &f1c, &f38);
        *(float*)((char*)&r1c + esi * 4) = *(float*)((char*)&r28 + esi * 4);
    }
}
