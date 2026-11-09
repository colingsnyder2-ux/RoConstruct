// from server: 30% by colin
// roc 2007-08 004deeb0  unit: RBX::Render::Mesh::Level  size: 965 bytes

struct Vec3 {
    float x, y, z;
};

struct MeshLevel {
    int field0;
    int field4;
    void method(
        int a0, int a1, int a2, int a3,
        int a4, int a5, int a6, int a7,
        int a8, int a9, int a10, int a11,
        int a12, int a13);
};

extern "C" void __cdecl sub_5B99F0(void* dst, void* src);
extern "C" void* __cdecl sub_62FF32(unsigned int size);
extern "C" void __cdecl sub_62FF26(void* p);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4F54E0(void* p);
extern "C" void* __cdecl sub_4F5360(void* a, void* b, void* c, int d);
extern "C" void __cdecl sub_4EEE30(void* self, int a, int b, int c, int d);

extern float g_79f2b8;
extern double g_795b48;

void MeshLevel::method(
    int a0, int a1, int a2, int a3,
    int a4, int a5, int a6, int a7,
    int a8, int a9, int a10, int a11,
    int a12, int a13)
{
    float local34[3];
    sub_5B99F0(local34, &this->field4);

    float f8c = local34[0];
    if (f8c < 0.0f) f8c = -f8c;

    float f90 = local34[1];
    if (f90 < 0.0f) f90 = -f90;

    float f94 = local34[2];
    if (f94 < 0.0f) f94 = -f94;

    int esi = a12;
    int ebx = a13;

    int edi = (ebx + 1) * (esi + 1);
    int allocSize = edi * 4;

    float fdiv1 = (float)(a4 - a2) / (float)esi;
    float fdiv2 = (float)(a5 - a3) / (float)ebx;
    float fdiv3 = (float)a8 / fdiv1;
    float fdiv4 = (float)a9 / fdiv2;

    void* mem = sub_62FF32(allocSize);
    int* arr = (int*)mem;

    float f2c = (float)a2;
    float f18b = (float)a6;
    float f2cb = (float)a7;

    if (esi < 0) goto end;

    {
        double d60 = (double)f8c;
        double d68 = (double)f90;
        double d20 = (double)f94;
        double d48 = (double)a3;
        double d2c = (double)a7;

        int outerCount = esi + 1;
        int* p14 = arr;

        if (ebx < 0) goto afterInner;

        {
            int eax = a10 * 4;
            int* p74 = (int*)((char*)&local34[0] + eax);
            int* p28 = (int*)((char*)&local34[0] - eax);
            int innerCount = ebx + 1;

            do {
                float f5c = (float)a7;
                float f24 = f18b;
                float f28 = f2cb;
                *p28 = (int)f18b;
                *p74 = (int)f2cb;
                float f30 = f18b;
                float f34 = f2cb;
                float f38 = 1.0f;

                float f54;
                if (f38 > f18b) {
                    f54 = f38 - g_79f2b8;
                } else {
                    f54 = f38 + g_79f2b8;
                }

                float f48 = f18b;
                float f58;
                if (f48 < f54) {
                    f58 = f54 - f48;
                } else {
                    f58 = f48 + f54;
                }

                int i;
                for (i = 0; i < 2; i++) {
                    float v;
                    if (((char*)&a0)[i] != 0) {
                        v = ((float*)&f54)[i] * ((float*)&a0)[i] / ((float*)&f8c)[i];
                    } else {
                        v = ((float*)&a0)[i];
                    }
                    ((float*)&f30)[i] = v;
                }

                void* r = sub_501570();
                float* rf = (float*)r;
                if (rf[0] == (float)d20 && rf[1] == (float)d48) {
                    f24 = (float)a6;
                    f28 = (float)a7;
                }

                float f84 = f24 * (float)g_795b48;
                float f88 = f28 * (float)g_795b48;

                float tmp1[3];
                sub_5B99F0(tmp1, &f30);
                float tmp2[3];
                sub_5B99F0(tmp2, &f5c);

                void* res = sub_4F5360(tmp2, tmp1, &f84, 1);
                *p14 = (int)res;
                p14++;

                f48 = f48 + (float)d60;
                f2c = f2c + (float)d68;

                innerCount--;
            } while (innerCount != 0);
        }

afterInner:
        p14 += ebx + 1;
        f18b = f18b + (float)d60;
        f2cb = f2cb + (float)d68;
        outerCount--;
        if (outerCount != 0) goto afterInner;
    }

    if (esi > 0) {
        int* p14 = arr;
        int* p18 = arr + ebx + 2;
        int cnt = esi;
        do {
            if (ebx > 0) {
                int* s = p14;
                int* d = p18;
                int n = ebx;
                do {
                    int v0 = d[0];
                    int v1 = d[-1];
                    int v2 = s[0];
                    int v3 = s[1];
                    sub_4EEE30((void*)a11, v3, v2, v1, v0);
                    d++;
                    s++;
                    n--;
                } while (n != 0);
            }
            p14 += ebx + 1;
            p18 += ebx + 1;
            cnt--;
        } while (cnt != 0);
    }

end:
    {
        unsigned int n = (unsigned int)edi;
        unsigned int i = 0;
        if (n > 0) {
            do {
                sub_4F54E0((void*)arr[i]);
                i++;
            } while (i < n);
        }
    }
    sub_62FF26(arr);
}
