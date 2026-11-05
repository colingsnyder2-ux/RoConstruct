// from server: 27% by colin
struct PBBBuilder {
    char pad0[4];
    int field4;
    int method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_5B99F0(int, int);
extern "C" int __stdcall sub_62FF32(int);
extern "C" int __stdcall sub_501570();
extern "C" int __stdcall sub_4F5360(int, int, int, int);
extern "C" int __stdcall sub_4F54E0(int);
extern "C" int __stdcall sub_62FF26(int);
extern "C" int __stdcall sub_62FC62(int);
extern "C" int __stdcall sub_4EEE30(int, int, int, int, int);
extern "C" int __stdcall InterlockedDecrement(int*);

int PBBBuilder::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
    int v[40];
    int i, j;
    int n1, n2;
    int count;
    int* arr;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
    float step1, step2, step3, step4;
    float base1, base2, base3, base4;
    int total;
    int* ptr;
    int* ptr2;
    int k;

    sub_5B99F0((int)&this->field4, (int)&v[0]);

    n1 = (short)a17;
    n2 = (short)a18;

    f1 = *(float*)&a13;
    f2 = *(float*)&a11;
    f3 = f1 - f2;
    step1 = f3 / (float)(n1 + 1);

    f4 = *(float*)&a14;
    f5 = *(float*)&a12;
    f6 = f4 - f5;
    step2 = f6 / (float)(n2 + 1);

    f7 = *(float*)&a15;
    f8 = *(float*)&a9;
    f9 = f7 - f8;
    step3 = f9 / (float)(n1 + 1);

    f10 = *(float*)&a16;
    f11 = *(float*)&a10;
    f12 = f10 - f11;
    step4 = f12 / (float)(n2 + 1);

    total = (n2 + 1) * (n1 + 1);
    arr = (int*)sub_62FF32(total * 4);

    base1 = *(float*)&a11;
    base2 = *(float*)&a12;
    base3 = *(float*)&a9;
    base4 = *(float*)&a10;

    if (n1 >= 0) {
        float cur1 = base1;
        float cur2 = base2;
        float cur3 = base3;
        float cur4 = base4;
        int* out = arr;
        for (i = 0; i <= n1; i++) {
            float r1 = cur1;
            float r2 = cur2;
            float r3 = cur3;
            float r4 = cur4;
            if (n2 >= 0) {
                int* p = out;
                for (j = 0; j <= n2; j++) {
                    float x1 = r1;
                    float x2 = r2;
                    float x3 = r3;
                    float x4 = r4;
                    float t1, t2, t3, t4;
                    float tmp[4];
                    float tmp2[4];
                    int* res;

                    tmp[0] = x1;
                    tmp[1] = x2;
                    tmp[2] = x3;
                    tmp[3] = 1.0f;

                    if (x1 < 0.0f) x1 = x1 - 0.5f; else x1 = x1 + 0.5f;
                    if (x2 < 0.0f) x2 = x2 - 0.5f; else x2 = x2 + 0.5f;

                    t1 = x1;
                    t2 = x2;

                    res = (int*)sub_501570();
                    if (*(float*)&a17 == *(float*)res && *(float*)&a18 == *(float*)(res + 4)) {
                        t1 = *(float*)&a13;
                        t2 = *(float*)&a14;
                    }

                    tmp2[0] = t1 * 0.5f;
                    tmp2[1] = t2 * 0.5f;
                    tmp2[2] = 0.0f;
                    tmp2[3] = 0.0f;

                    sub_5B99F0((int)tmp, (int)&v[0]);
                    sub_5B99F0((int)tmp2, (int)&v[0]);

                    *p = sub_4F5360((int)&v[0], (int)&v[0], (int)&v[0], 1);

                    r1 = r1 + step1;
                    r2 = r2 + step2;
                    r3 = r3 + step3;
                    r4 = r4 + step4;
                    p++;
                }
            }
            cur1 = cur1 + step3;
            cur2 = cur2 + step4;
            cur3 = cur3 + step1;
            cur4 = cur4 + step2;
            out += (n2 + 1);
        }
    }

    if (n1 > 0) {
        int* p1 = arr;
        int* p2 = arr + (n2 + 1);
        for (i = 0; i < n1; i++) {
            if (n2 > 0) {
                int* q1 = p1;
                int* q2 = p2;
                for (j = 0; j < n2; j++) {
                    sub_4EEE30(this->field4, q1[0], q1[1], q2[0], q2[1]);
                    q1++;
                    q2++;
                }
            }
            p1 += (n2 + 1);
            p2 += (n2 + 1);
        }
    }

    for (i = 0; i < (unsigned)n1; i++) {
        sub_4F54E0(arr[i]);
    }

    sub_62FF26((int)arr);

    if (a20) {
        if (InterlockedDecrement((int*)(a20 + 4)) == 0) {
            int* p = *(int**)(a20 + 8);
            while (p) {
                (*(void(**)(int))*p)(*p);
                int* next = (int*)p[1];
                sub_62FC62((int)p);
                p = next;
            }
            (*(void(**)(int, int))**(int**)a20)(a20, 1);
        }
    }

    return 0;
}
