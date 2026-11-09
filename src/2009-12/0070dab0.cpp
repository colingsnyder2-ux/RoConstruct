// from server: 25% by atomic.potato
extern "C" {
    void __stdcall sub_70bcd0(int, int, int);
    void __stdcall sub_70cf40();
    void __stdcall sub_7f4aaa(int, int, int, int, int);
    void __stdcall sub_7f4878(int, int);
    void __stdcall sub_70b290();
    void __stdcall sub_98b7a4(int, int);
}

struct VInsertService {
    void func(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void VInsertService::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
    char pad1[0x18];
    char pad2[0x20];
    int v1 = 0;
    int v2 = 1;
    int* p1 = &v1;
    if (a1) {
        v1 = a1;
        int* vt = (int*)a1;
        int (*fn)(int, int*, int*) = (int (*)(int, int*, int*))vt[0];
        fn(0, (int*)((char*)p1 + 8), (int*)((char*)&pad1 + 0x8c));
    }
    char pad3[0x20];
    int v3 = 0;
    char pad4[0x28];
    char pad5[0x20];
    int v4 = 0;
    char v5 = 2;
    if (a2) {
        v4 = a2;
        int* vt2 = (int*)a2;
        int (*fn2)(int, int*, int*) = (int (*)(int, int*, int*))vt2[0];
        fn2(0, (int*)((char*)&v4 + 8), (int*)((char*)&pad3 + 0xd8));
    }
    unsigned char b = *(unsigned char*)0xb9510b;
    sub_70bcd0(b, 0x70b6a0, (int)&pad3);
    sub_70cf40();
    int v6 = 0;
    sub_7f4aaa(0, 0xb4a93c, 0xb00040, 0, a3);
    if (!v6) {
        sub_98b7a4(0x99fe9c, (int)&pad1 + 0x5c);
        sub_7f4878(0xa9d814, (int)&pad1 + 0x5c);
    }
    sub_70b290();
    int v7 = *(int*)((char*)&pad1 + 0x3c);
    if (v7) {
        int* vt3 = (int*)v7;
        if (vt3[0]) {
            int (*fn3)(int, int*, int*) = (int (*)(int, int*, int*))vt3[0];
            fn3(2, (int*)((char*)&pad1 + 0x44), (int*)((char*)&pad1 + 0x44));
        }
    }
    int v8 = *(int*)((char*)&pad1 + 0x5c);
    if (v8) {
        int* vt4 = (int*)v8;
        if (vt4[0]) {
            int (*fn4)(int, int*, int*) = (int (*)(int, int*, int*))vt4[0];
            fn4(2, (int*)((char*)&pad1 + 0x64), (int*)((char*)&pad1 + 0x64));
        }
    }
}
