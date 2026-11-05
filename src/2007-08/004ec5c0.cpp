// from server: 17% by colin
// roc 2007-08 004ec5c0  unit: CylinderBuilder  size: 837 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ec5c0

struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    float m[16];
};

struct CylinderBuilder {
    char pad0[4];
    Vec3 field4;
    void buildRight(int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_5b9a10(void*, void*);
extern "C" void* __cdecl sub_62ff32(unsigned int);
extern "C" void __cdecl sub_62ff26(void*);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void* __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4eb600(void*, void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4eee30(void*, void*, void*, void*, void*);

extern double g_795b48;

void CylinderBuilder::buildRight(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    Vec3 v;
    sub_5b9a10(&v, &this->field4);

    float f18 = (float)(v.x < 0 ? -v.x : v.x);
    float f84 = f18;
    float f88 = (float)(v.y < 0 ? -v.y : v.y);
    float f8c = (float)(v.z < 0 ? -v.z : v.z);

    int n1 = a13 + 1;
    int n2 = a12 + 1;
    int total = n2 * n1;

    float f58 = (float)n1 / (float)(a5 - a3);
    float f5c = (float)n2 / (float)(a6 - a4);
    float f60 = (float)(a9 - a7) / (float)n1;
    float f64 = (float)(a10 - a8) / (float)n2;

    void* mem = sub_62ff32(total * 4);
    void** arr = (void**)mem;

    float f38 = (float)a3;
    float f24 = (float)a7;
    float f34 = (float)a4;
    float f30 = (float)a8;

    int i;
    for (i = 0; i <= a13; i++) {
        int j;
        for (j = 0; j <= a12; j++) {
            float f3c = f34;
            float f40 = f38;
            float f44 = (float)a5;
            float f24b = f24;
            float f28b = f30;

            float f70 = f24b;
            float f78 = f28b;
            float f80 = 1.0f;

            sub_4eb600(&this->field4, &f40, &f24b, &f70, &f78, &f80);

            void* p = sub_501570();
            float* pf = (float*)p;
            if (pf[0] == (float)a9 && pf[1] == (float)a10) {
                f24b = (float)a7;
                f28b = (float)a8;
            }

            float f7c = f24b * (float)g_795b48;
            float f80b = f28b * (float)g_795b48;

            sub_5b9a10(&f7c, &f80b);
            sub_5b9a10(&f40, &f44);

            void* q = sub_4f5360(&f7c, &f80b, &f40, 1);
            arr[i * (a12 + 1) + j] = q;

            f34 += f60;
            f30 += f64;
        }
        f38 += f58;
        f24 += f5c;
    }

    for (i = 0; i < a13; i++) {
        int j;
        for (j = 0; j < a12; j++) {
            sub_4eee30(this, arr[i * (a12 + 1) + j], arr[i * (a12 + 1) + j + 1], arr[(i + 1) * (a12 + 1) + j], arr[(i + 1) * (a12 + 1) + j + 1]);
        }
    }

    for (i = 0; i < total; i++) {
        sub_4f54e0(arr[i]);
    }
    sub_62ff26(arr);
}
