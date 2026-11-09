// from server: 29% by colin
struct S {
    char pad0[4];
    int f(int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_5B99B0(int, int);
extern "C" int __stdcall sub_62FF32(int);
extern "C" int __stdcall sub_4EB600(int, int, int, int, int);
extern "C" int __stdcall sub_501570();
extern "C" int __stdcall sub_4F5360(int, int, int, int);
extern "C" int __stdcall sub_4EEE30(int, int, int, int, int);
extern "C" int __stdcall sub_4F54E0(int);
extern "C" int __stdcall sub_62FF26(int);

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    int v[40];
    int i, j, k;
    int n1, n2;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16;
    int *arr;
    int total;

    sub_5B99B0((int)&v[0], (int)(this + 1));
    f1 = *(float*)&v[1];
    if (f1 < 0) f1 = -f1;
    f2 = f1;
    n1 = a13;
    f3 = f2;
    f4 = *(float*)&v[2];
    if (f4 < 0) f4 = -f4;
    f5 = f4;
    n2 = a12;
    f6 = f5;
    f7 = *(float*)&v[3];
    if (f7 < 0) f7 = -f7;
    f8 = f7;
    total = (n2 + 1) * (n1 + 1);
    f9 = (float)n1;
    f10 = *(float*)&a2 - *(float*)&a1;
    f11 = f10 / f9;
    f12 = (float)n2;
    f13 = *(float*)&a4 - *(float*)&a3;
    f14 = f13 / f12;
    f15 = *(float*)&a6 / f9;
    f16 = *(float*)&a7 / f12;

    arr = (int*)sub_62FF32(total * 4);
    f1 = *(float*)&a1;
    f2 = *(float*)&a5;
    if (n1 >= 0) {
        f3 = 0.0f;
        f4 = *(float*)&a3;
        for (i = 0; i <= n1; i++) {
            f5 = f3;
            f6 = f4;
            for (j = 0; j <= n2; j++) {
                float tmp[8];
                int idx[2];
                float fv[4];
                fv[0] = f5;
                fv[1] = f6;
                fv[2] = f2;
                fv[3] = 1.0f;
                idx[0] = i;
                idx[1] = j;
                sub_4EB600((int)(this + 2), (int)fv, (int)idx, (int)tmp, (int)&f2);
                if (*(float*)&a6 == *(float*)sub_501570() && *(float*)&a7 == *(float*)(sub_501570() + 4)) {
                    f5 = *(float*)&a5;
                    f6 = *(float*)&a6;
                }
                {
                    float t1 = f5 * *(double*)0x795b48;
                    float t2 = f6 * f6;
                    sub_5B99B0((int)&v[20], (int)&t1);
                    sub_5B99B0((int)&v[24], (int)&t2);
                    arr[i * (n2 + 1) + j] = sub_4F5360((int)&v[28], (int)&v[24], (int)&v[20], 1);
                }
                f5 = f5 + f11;
                f6 = f6 + f14;
            }
            f3 = f3 + f15;
            f4 = f4 + f16;
        }
    }
    if (n1 > 0) {
        int *p1 = arr;
        int *p2 = arr + n2 + 2;
        for (i = 0; i < n1; i++) {
            if (n2 > 0) {
                for (j = 0; j < n2; j++) {
                    sub_4EEE30((int)(this + 2), p1[0], p1[1], p2[0], p2[1]);
                    p1++;
                    p2++;
                }
            }
            p1 += 1;
            p2 += 1;
        }
    }
    for (k = 0; k < total; k++) {
        sub_4F54E0(arr[k]);
    }
    sub_62FF26((int)arr);
    return 0;
}
