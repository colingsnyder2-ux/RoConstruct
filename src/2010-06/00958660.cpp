// from server: 19% by atomic.potato
struct PBBBuilder {
    char pad0[4];
    void* field4;
    char pad8[0x38];
    void build(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_738EF0(void*, void*);
extern "C" void* __cdecl sub_7A7C82(int);
extern "C" void __cdecl sub_7A7C46(void*);
extern "C" void* __cdecl sub_54F2A0();
extern "C" void __cdecl sub_9570E0(PBBBuilder*, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

void PBBBuilder::build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
    char buf[0x48];
    float f38, f3c, f40, f44, f48, f4c;
    float f10, f14, f18, f20;
    int i, j;
    int n1, n2;
    void* arr;
    int* p;

    sub_738EF0(buf, (char*)this + 8);

    f3c = (float)(*(int*)&a1);
    f38 = (float)(*(int*)&a2);
    f48 = (float)(*(int*)&a3);
    f4c = (float)(*(int*)&a4);
    f40 = (float)(*(int*)&a5);
    f44 = (float)(*(int*)&a6);

    n1 = a7;
    n2 = a8;

    arr = sub_7A7C82((n1 + 1) * (n2 + 1) * 4);

    f10 = *(float*)&a9;
    f20 = *(float*)&a10;
    f14 = *(float*)&a11;
    f18 = *(float*)&a12;

    for (i = 0; i <= n2; i++) {
        f10 = *(float*)&a9;
        f20 = *(float*)&a10;
        for (j = 0; j <= n1; j++) {
            float* q = (float*)sub_54F2A0();
            int eq = (*(float*)&a13 == q[0]) && (*(float*)&a14 == q[1]);
            sub_9570E0(this, eq, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
            ((int*)arr)[j + i * (n1 + 1)] = (int)q;
            f10 += f38;
            f20 += f3c;
        }
        f14 += f40;
        f18 += f44;
    }

    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            int idx = j + i * (n1 + 1);
            int* vtable = *(int**)this->field4;
            void (*fn)(int, int, int, int) = (void (*)(int, int, int, int))vtable[6];
            fn(((int*)arr)[idx], ((int*)arr)[idx + 1], ((int*)arr)[idx + n1 + 1], ((int*)arr)[idx + n1 + 2]);
        }
    }

    sub_7A7C46(arr);
}
