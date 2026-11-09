// from server: 19% by colin
// roc 2007-08 004e7380  unit: TorsoMesh  size: 1114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e7380

extern "C" {
    int __stdcall InterlockedDecrement(int*);
    int __stdcall InterlockedIncrement(int*);
    double __cdecl ceil(double);
    float __cdecl fabsf(float);
}

struct Vec3 {
    float x, y, z;
};

struct Mat3 {
    float m[3][3];
};

struct TorsoBuilder {
    char pad0[0x10];
    unsigned int flags;
    char pad14[0x08];
    float f18;
    float f1c;
    char pad20[0x10];
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

extern "C" void __cdecl sub_5b99f0(void*, void*);
extern "C" void* __cdecl sub_50b010(void*, void*);
extern "C" float __cdecl sub_4de980(int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4e6e60(void*, void*);
extern "C" void __cdecl sub_62fc62(void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void TorsoBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    unsigned int v = (this->flags >> 12) & 7;
    int idx = 0;
    float fabs1, fabs2, fabs3;
    float v50, v54, v58;
    float v1c, v20, v2c, v30;
    int count;
    int i2;

    sub_5b99f0(&this->pad0[4], &v50);

    fabs1 = fabsf(v50);
    fabs2 = fabsf(v54);
    fabs3 = fabsf(v58);

    v1c = fabs1;
    v20 = fabs2;
    v2c = fabs3;

    if (a == 0 && v2c == v1c) {
        idx = 1;
    } else {
        idx = 0;
    }

    if (a == 0 && v != 0) {
        float t = v2c * (float)g_795b48;
        t = (float)ceil((double)t);
        count = (int)t;
    } else {
        count = 1;
    }

    {
        short s = *(short*)((char*)&v50 + idx * 2 + 0x96 - idx * 2);
        int q = (int)s / count;
        short qs = (short)q;
        if (qs <= 1) {
            qs = 1;
        }
        *(short*)((char*)&v50 + idx * 2 + 0x10) = qs;
    }

    {
        float* p1 = (float*)sub_50b010(&v50, &v54);
        float* p2 = (float*)sub_50b010(&v54, &v58);
        v1c = -p1[0];
        v20 = -p1[1];
        v2c = -p2[0];
        v30 = -p2[1];
    }

    if (a == 0) {
        if (v == 0) {
            v1c = g_787050;
            v20 = g_797e9c;
            v2c = v1c;
            v30 = v20;
        } else {
            v1c = 0.0f;
            v20 = 0.0f;
            v2c = 0.0f;
            v30 = 0.0f;
            v2c = sub_4de980(v);
            v1c = v2c * 2.0f;
            v30 = g_797e9c;
            if (idx == 1) {
                v1c = -v1c;
            }
        }
    } else if (a == 1) {
        v1c = this->f1c;
        v20 = this->f18;
        v2c = this->f1c;
        v30 = -this->f1c;
    } else if (a == 2) {
        v1c = 0.0f;
        v20 = 0.0f;
        v2c = 0.0f;
        v30 = 0.0f;
    }

    for (i2 = 0; i2 < count; i2++) {
        if (i2 == count - 1) {
            float t = v2c;
            if (a != 0 && v1c != 0.0f) {
                t = (t - v30) * (float)g_79f348 * v1c;
            }
            v1c = t;
        } else {
            v1c = v30 + (float)g_79f340;
        }

        {
            float tmp[2];
            tmp[0] = v1c;
            tmp[1] = v20;
            sub_4e0180(&v1c, &v20, tmp, &v2c, &v30);
        }

        {
            void* obj = (void*)&v1c;
            sub_4e6e60(obj, &v2c);
        }

        v30 = v1c;
    }

    if (v != 0) {
        if (InterlockedDecrement((int*)((char*)this + 4)) == 0) {
            void* p2 = *(void**)((char*)this + 8);
            while (p2) {
                void* next = *(void**)((char*)p2 + 4);
                (*(void (__stdcall**)(void*))**(void***)p2)(p2);
                sub_62fc62(p2);
                p2 = next;
            }
            (*(void (__stdcall**)(void*, int))**(void***)this)(this, 1);
        }
    }
}
