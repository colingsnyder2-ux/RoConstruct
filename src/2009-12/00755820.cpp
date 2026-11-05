// from server: 34% by atomic.potato
struct S_func_00755820 {
    char pad0[4];
    void* m_field0;
    void f(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_00754be0(int, int, int, int*);
extern "C" void* __stdcall sub_00651520(int, int);
extern "C" void __stdcall sub_00442310(void*, void*);
extern "C" void __stdcall sub_007f385a(void*);

void S_func_00755820::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int v1 = a1;
    int v2 = a2;
    int v3 = a3;
    int v4 = a4;
    int v5 = a5;
    int v6 = a6;
    int v7 = a7;
    int v8 = a8;
    int v9 = a9;
    int v10 = a10;

    int local[3];
    local[0] = v1;
    local[1] = v2;
    local[2] = v3;

    int local2[3];
    local2[0] = v4;
    local2[1] = v5;
    local2[2] = v6;

    int* p = (int*)sub_00754be0(v7, v8, v9, local2);
    int saved = *p;
    *p = 0;

    int tmp = 0;
    void* q = sub_00651520(v10, saved);
    sub_00442310(this, q);
    sub_007f385a((void*)v10);

    *(void**)this = (void*)0x9e4ddc;
}
