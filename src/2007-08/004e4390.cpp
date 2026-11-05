// from server: 23% by colin
// roc 2007-08 004e4390  unit: WedgeMesh.cpp  size: 1098 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e4390

extern "C" {
    int __stdcall InterlockedDecrement(int volatile*);
    int __stdcall InterlockedIncrement(int volatile*);
    double __cdecl ceil(double);
}

struct Vec3 {
    float x, y, z;
};

struct Mat3 {
    float m[9];
};

struct WedgeBuilder {
    char pad0[0x10];
    unsigned int flags;
    char pad14[0x08];
    float f18;
    float f1c;
    char pad20[0x2c];
    int build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
};

extern "C" void __stdcall sub_5b99f0(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" void __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*);
extern "C" void __stdcall sub_4e3a00(void*);
extern "C" void __stdcall sub_62fc62(void*);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

int WedgeBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    int result = 0;
    unsigned int ebp = (this->flags >> 12) & 7;
    float v50, v54, v58;
    float v10, v14, v1c, v20, v2c, v30, v34, v3c;
    int v24, v28;
    int edi;
    int ebx;
    int count;
    int idx;
    int tmp;

    sub_5b99f0(&this->pad0[4], &v50);

    v1c = v50;
    if (v50 < 0) v1c = -v50;
    v14 = v54;
    if (v54 < 0) v14 = -v54;
    v10 = v14;
    v14 = v58;
    if (v58 < 0) v14 = -v58;
    v50 = v14;

    v54 = v10;
    v58 = v1c;

    if (a == 0) {
        if (v50 == v10) {
            edi = 0;
        } else {
            edi = 1;
        }
    } else {
        edi = 1;
    }

    if (a == 0 && ebp != 0) {
        v1c = (float)ceil((double)v50 * g_795b48);
        ebx = (int)v1c;
    } else {
        ebx = 1;
    }

    v10 = 0;
    v14 = 0;
    tmp = *(short*)((char*)&v14 + 2 - edi * 2);
    tmp = tmp / ebx;
    v1c = 1;
    if ((unsigned short)tmp > 1) {
        v24 = (unsigned short)tmp;
    } else {
        v24 = 1;
    }
    *(short*)((char*)&v10 + edi * 2) = (short)tmp;

    v28 = v58;

    sub_50b010(&v50, &v54);
    v2c = -v54;
    v30 = -v58;
    v1c = v2c;
    v20 = v30;

    sub_50b010(&v50, &v54);
    v2c = 0;
    v30 = 0;
    v1c = 0;
    v20 = 0;

    switch (a) {
    case 0:
        if (ebp == 0) {
            v2c = g_787050;
            v30 = g_797e9c;
            v1c = v30;
        } else {
            v30 = v1c;
            sub_4de980(ebp);
            v30 = v1c;
            v1c = v2c * 2;
            v20 = g_797e9c;
            if (edi == 1) {
                v1c = -v1c;
            }
        }
        break;
    case 1:
        v2c = 0;
        v30 = this->f1c;
        v1c = this->f18;
        v20 = -this->f1c;
        break;
    case 2:
        v2c = 0;
        v30 = 0;
        v1c = 0;
        v20 = 0;
        break;
    }

    ebp = 0;
    ebx = *(int*)((char*)&v50 + 0x30);

    if (ebx > 0) {
        do {
            if (ebp == ebx - 1) {
                v34 = v50;
                if (a != 0) {
                    if (v24 != 0) {
                        v1c = (v1c - v3c) * g_79f348 * v1c;
                    }
                }
            } else {
                v34 = v3c + g_79f340;
            }

            sub_4e0180(&v1c, &v2c, &v30);
            sub_4e3a00(&v1c);
            v3c = v34;
            ebp++;
        } while (ebp < ebx);
    }

    if (ebx != 0) {
        if (InterlockedDecrement((int*)((char*)&v50 + 4)) == 0) {
            void* p = *(void**)((char*)&v50 + 8);
            while (p != 0) {
                void* next = *(void**)((char*)p + 4);
                (*(void (***)(void*))p)[1](p);
                sub_62fc62(p);
                p = next;
            }
            (*(void (***)(void*, int))&v50)[0](&v50, 1);
        }
    }

    return result;
}
