// from server: 34% by colin
// roc 2007-08 004e5830  unit: WedgeBuilder  size: 773 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e5830

extern "C" void __stdcall sub_5b99d0(void*, void*);
extern "C" void* __cdecl sub_62ff32(unsigned int);
extern "C" void __cdecl sub_62ff26(void*);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void __cdecl sub_4eee30(void*, void*, void*, void*, void*);

struct WedgeBuilder {
    char pad0[4];
    int field4;
    void build(int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void WedgeBuilder::build(int a8, int a12, int a16, int a20, int a24, int a28, int a32, int a36, int a40, int a44, int a48, int a52, int a56)
{
    float f10 = *(float*)&a16;
    float f14 = *(float*)&a20;
    float f18 = *(float*)&a24;
    float f1c = *(float*)&a28;
    float f20 = *(float*)&a32;
    float f24 = *(float*)&a36;
    float f28 = *(float*)&a40;
    float f2c = *(float*)&a44;
    float f30 = *(float*)&a48;
    int i38 = a56;
    int i3a = a52;

    float buf[2];
    sub_5b99d0(&this->field4, buf);

    int n1 = i38 + 1;
    int n2 = i3a + 1;
    int total = n1 * n2;

    float d1 = (f18 - f10) / (float)i38;
    float d2 = (f1c - f14) / (float)i3a;
    float d3 = f2c / f28;
    float d4 = f30 / f28;

    void** arr = (void**)sub_62ff32((unsigned int)total * 4);

    float cur1 = f10;
    float cur2 = f14;
    float cur3 = f20;
    float cur4 = f24;
    float cur5 = f28;

    int i;
    for (i = 0; i <= i38; i++) {
        int j;
        for (j = 0; j <= i3a; j++) {
            float v0 = cur1;
            float v1 = cur2;
            float v2 = cur3;
            float v3 = cur4;
            float v4 = cur5;
            float v5 = 1.0f;

            float t1;
            if (v0 < v3) {
                t1 = v3 - v0;
            } else {
                t1 = v3 + v0;
            }

            float t2;
            float t3;
            if (v1 < v3) {
                t2 = v3 - v1;
                t3 = v4 - f14;
            } else {
                t2 = v3 + v1;
                t3 = v4;
            }

            float* p = (float*)sub_501570();
            if (p[0] == f2c && p[1] == f30) {
                v0 = f20;
                v1 = f24;
            }

            float q0 = v0 * 1.0f;
            float q1 = v1 * 1.0f;
            float q2 = v2;
            float q3 = v3;
            float q4 = v4;
            float q5 = v5;

            float r0 = t1;
            float r1 = t2;
            float r2 = t3;

            void* o1;
            void* o2;
            sub_5b99d0(&q0, &o1);
            sub_5b99d0(&r0, &o2);
            void* obj = sub_4f5360(&o1, &o2, &q0, 1);
            arr[i * n2 + j] = obj;

            cur3 = cur3 + t1;
            cur4 = cur4 + t2;
        }
        cur1 = cur1 + d1;
        cur2 = cur2 + d2;
    }

    if (i38 > 0) {
        int k;
        for (k = 0; k < i38; k++) {
            int m;
            for (m = 0; m < i3a; m++) {
                void* p0 = arr[k * n2 + m];
                void* p1 = arr[k * n2 + m + 1];
                void* p2 = arr[(k + 1) * n2 + m];
                void* p3 = arr[(k + 1) * n2 + m + 1];
                sub_4eee30(p0, p1, p2, p3, 0);
            }
        }
    }

    unsigned int cnt = (unsigned int)total;
    unsigned int idx;
    for (idx = 0; idx < cnt; idx++) {
        sub_4f54e0(arr[idx]);
    }
    sub_62ff26(arr);
}
