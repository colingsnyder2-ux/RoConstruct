// from server: 11% by colin
struct MeshLevel {
    int pad0;
    int pad4;
    void func(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_5B99B0(void*, void*);
extern "C" void* __stdcall sub_62FF32(int);
extern "C" void* __stdcall sub_501570();
extern "C" void __stdcall sub_4F5360(void*, void*, void*, int);
extern "C" void __stdcall sub_4EEE30(void*, int, int, int, int);
extern "C" void __stdcall sub_4F54E0(void*);
extern "C" void __stdcall sub_62FF26(void*);

extern float g_79f2b8;
extern double g_795b48;

float my_fabs(float x) { return x < 0.0f ? -x : x; }

void MeshLevel::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
    float f18, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44;
    float f50, f54, f58, f5c, f60, f64, f68, f6c, f70;
    float f84, f88, f8c;
    double d90, d98, da0, da8, db0, db8, dc0;
    int i10, i14, i18, i1c, i40, i48, i4c, i50, i5c, i60, i64;
    int* pi;
    int i, k;
    float* pf;
    void* p;

    sub_5B99B0(&this->pad4, &f38);
    f18 = my_fabs(f38);
    i50 = a13;
    f84 = f18;
    f18 = my_fabs(f3c);
    i4c = a14;
    f88 = f18;
    i60 = a13 + 1;
    f18 = my_fabs(f40);
    i64 = a14 + 1;
    f8c = f18;
    i64 = i64 * i60;
    f18 = my_fabs(f44);
    f8c = f18;
    f18 = (float)a13;
    f18 = (float)(a6 - a4) / f18;
    f58 = f18;
    f18 = (float)a13;
    f18 = (float)(a7 - a5) / f18;
    f5c = f18;
    f60 = a11 / f18;
    f64 = a12 / f18;
    p = sub_62FF32(i64 * 4);
    f2c = (float)a4;
    i10 = (int)p;
    f18 = (float)a8;
    i14 = i10;
    if (a13 >= 0) {
        da8 = (double)i4c;
        dc0 = (double)f54;
        f30 = (float)a5;
        f2c = (float)a6;
        da0 = (double)f20;
        d90 = (double)a9;
        d98 = (double)a10;
        db8 = (double)f58;
        i1c = a13 + 1;
        i40 = a14 + 1;
        while (1) {
            f38 = f30;
            f24 = f20;
            f28 = f20;
            *(float*)&f68 = f20;
            *(float*)&f6c = f20;
            f70 = 1.0f;
            if (f20 < f20) {
                f34 = f20 - g_79f2b8;
            } else {
                f34 = f20 + g_79f2b8;
            }
            f3c = f34 - (float)d90;
            for (i = 0; i < 2; i++) {
                if (*(char*)((char*)&a1 + i) != 0) {
                    f68 = f34 * *(float*)((char*)&a1 + i * 4 + 8) / *(float*)((char*)&f68 + i * 4 + 0x14);
                } else {
                    f68 = *(float*)((char*)&a1 + i * 4 + 8);
                }
            }
            p = sub_501570();
            if (*(float*)p == (float)da0 && *(float*)((char*)p + 4) == (float)db0) {
                f24 = (float)a9;
                f28 = (float)a10;
            }
            f24 = f24 * (float)g_795b48;
            f28 = f28 * f30;
            sub_5B99B0(&f68, &dc0);
            sub_5B99B0(&f3c, &dc0);
            sub_4F5360(&dc0, &dc0, &f68, 1);
            *(int*)i14 = (int)p;
            f30 = f30 + (float)da8;
            i14 += 4;
            i40--;
            f2c = f2c + (float)db8;
            if (i40 != 0) {
                continue;
            }
            break;
        }
    }
    i14 = i10;
    if (i48 > 0) {
        i14 = i10;
        i18 = i10 + i4c * 4 + 8;
        i1c = i48;
        while (1) {
            if (i4c > 0) {
                pi = (int*)i14;
                pf = (float*)i18;
                for (k = i4c; k != 0; k--) {
                    sub_4EEE30((void*)i60, *(int*)pi, *(int*)((char*)pi + 4), *(int*)((char*)pf - 4), *(int*)pf);
                    pf++;
                    pi++;
                }
            }
            i14 += i4c * 4 + 4;
            i18 += i4c * 4 + 4;
            i1c--;
            if (i1c == 0) break;
        }
    }
    i4c = i5c;
    for (i = 0; (unsigned)i < (unsigned)i4c; i++) {
        sub_4F54E0(*(void**)(i10 + i * 4));
    }
    sub_62FF26((void*)i10);
}
