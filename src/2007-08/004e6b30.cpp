// from server: 30% by colin
// roc 2007-08 004e6b30  unit: WedgeBuilder  size: 802 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e6b30

extern "C" __declspec(dllimport) double __stdcall ceil(double);
extern "C" float __cdecl fabsf(float);

struct Vec3 {
    float x, y, z;
};

struct Mat3 {
    float m[9];
};

struct WedgeBuilder {
    char pad[0x10];
    unsigned int flags;
    void buildSide(unsigned int, unsigned int, unsigned int, unsigned int);
};

extern "C" void __cdecl func_5b9a10(void*, void*);
extern "C" void __cdecl func_50b010(void*, void*);
extern "C" float __cdecl func_4de980(float, unsigned int);
extern "C" void __cdecl func_4e0180(void*, void*, void*, void*, void*);
extern "C" void __cdecl func_4e5b40(void*, void*, void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void WedgeBuilder::buildSide(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int v = (this->flags >> 15) & 7;
    float f0, f1, f2;
    float local0, local1, local2, local3;
    float arr[4];
    unsigned short s0, s1;
    int i, n;
    float tmp;

    func_5b9a10(&this->pad[4], &local0);

    f0 = fabsf(*(float*)&a);
    f1 = fabsf(local0);
    f2 = fabsf(local1);

    arr[0] = f1;
    arr[1] = f0;
    arr[2] = f2;
    arr[3] = 0.0f;

    if (b == 0) {
        if (f2 == f0) {
            i = 1;
        } else {
            i = 0;
        }
    } else {
        i = 0;
    }

    if (b == 0 && v != 0) {
        tmp = arr[i] * (float)g_795b48;
        tmp = (float)ceil((double)tmp);
        n = (int)tmp;
    } else {
        n = 1;
    }

    s0 = 0;
    s1 = 0;

    {
        unsigned short val = *(unsigned short*)((char*)&arr[0] + (i * 2));
        int q = (int)(short)val;
        int r = q / n;
        unsigned short rv = (unsigned short)r;
        if ((short)rv > 1) {
            s0 = rv;
        } else {
            s0 = 1;
        }
    }

    s1 = *(unsigned short*)((char*)&arr[0] + (i * 2));

    {
        float u0, u1, u2, u3;

        func_50b010(&local2, &arr[0]);

        u0 = 0.0f;
        u1 = 0.0f;
        u2 = 0.0f;
        u3 = 0.0f;

        switch (c) {
        case 0:
            if (v == 0) {
                u0 = g_787050;
                u1 = g_797e9c;
                u2 = u0;
            } else {
                u2 = 0.0f;
                u1 = func_4de980(0.0f, v);
                u0 = u1 * 2.0f;
                u2 = g_797e9c;
                if (i == 1) {
                    u2 = -u2;
                }
            }
            break;
        case 1:
            u0 = 0.0f;
            u1 = *(float*)((char*)this + 0x1c);
            u2 = *(float*)((char*)this + 0x18);
            u3 = -*(float*)((char*)this + 0x1c);
            break;
        case 2:
            u0 = 0.0f;
            u1 = 0.0f;
            u2 = 0.0f;
            u3 = 0.0f;
            break;
        default:
            break;
        }

        for (i = 0; i < n; i++) {
            if (i == n - 1) {
                float fv = arr[0];
                float fw = fv;
                if (d == 0 && *(int*)&u0 != 0) {
                    fw = (fw - u1) * (float)g_79f348 * u2;
                }
                u2 = fw;
            } else {
                u2 = u1 + (float)g_79f340;
            }

            {
                float p0 = u2;
                float p1 = u0;
                float p2 = u1;
                float p3 = u3;
                func_4e0180(&p0, &p1, &p2, &p3, &local0);
            }

            func_4e5b40(&local0, &s0, &s1);
            u1 = u2;
        }
    }
}
