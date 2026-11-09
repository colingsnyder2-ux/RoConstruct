// from server: 16% by colin
struct S {
    void f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n);
};

extern "C" void __cdecl sub_5B9A10(float* dst, float* src);
extern "C" void* __cdecl sub_62FF32(int size);
extern "C" void __cdecl sub_62FF26(void* p);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4F5360(void* a, void* b, void* c, int d);
extern "C" void __cdecl sub_4F54E0(void* p);
extern "C" void __cdecl sub_4EEE30(void* self, int a, int b, int c, int d);

extern float g_79F2B8;
extern double g_795B48;

void S::f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n)
{
    float v[3];
    sub_5B9A10(v, (float*)((char*)this + 4));

    float f0 = v[0];
    if (f0 < 0) f0 = -f0;
    float f1 = v[1];
    if (f1 < 0) f1 = -f1;
    float f2 = v[2];
    if (f2 < 0) f2 = -f2;

    int si = (short)a;
    int bx = (short)b;

    int count = (si + 1) * (bx + 1);

    float d0 = (float)(*(float*)&c - *(float*)&d);
    float d1 = (float)(*(float*)&e - *(float*)&f);

    float r0 = d0 / (float)si;
    float r1 = d1 / (float)si;

    float q0 = *(float*)&g / (float)si;
    float q1 = *(float*)&h / (float)si;

    void* mem = sub_62FF32(count * 4);
    int* arr = (int*)mem;

    float base0 = *(float*)&d;
    float base1 = *(float*)&f;

    if (si >= 0) {
        float step0 = (float)bx;
        float step1 = r0;
        float step2 = r1;
        float step3 = *(float*)&i;
        float step4 = *(float*)&j;
        float step5 = *(float*)&k;
        float step6 = *(float*)&l;

        int row = 0;
        int idx = 0;
        for (int y = 0; y <= bx; y++) {
            float cur0 = base0;
            float cur1 = base1;
            int col = 0;
            for (int x = 0; x <= si; x++) {
                float p[3];
                p[0] = cur0;
                p[1] = cur1;
                p[2] = 1.0f;

                float t0 = *(float*)&m;
                float t1 = *(float*)&n;

                float u = (float)x / (float)si;
                float vv = (float)y / (float)bx;

                float uv[2];
                uv[0] = u;
                uv[1] = vv;

                float tmp[3];
                sub_5B9A10(tmp, p);
                sub_5B9A10(tmp, uv);

                void* res = 0;
                sub_4F5360(&res, tmp, uv, 1);
                arr[idx] = (int)res;
                idx++;

                cur0 += step1;
                cur1 += step2;
            }
            base0 += step3;
            base1 += step4;
        }
    }

    if (count > 0) {
        for (int i2 = 0; i2 < count; i2++) {
            sub_4F54E0((void*)arr[i2]);
        }
    }

    sub_62FF26(arr);
}
