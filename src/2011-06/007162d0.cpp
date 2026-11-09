// from server: 22% by atomic.potato
struct S_007162d0 {
    void* f_007162d0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __cdecl cb_005ce0d0();
extern "C" void* __cdecl cb_00715a40(int, int, int, int, int, int, int);
extern "C" void __cdecl cb_0080a058(void*);
extern "C" void __cdecl cb_0040b4c0();

void* S_007162d0::f_007162d0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
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

    int tmp[3];
    tmp[0] = v1;
    tmp[1] = v2;
    tmp[2] = v3;

    int tmp2[3];
    tmp2[0] = v4;
    tmp2[1] = v5;
    tmp2[2] = v6;

    int* p = (int*)cb_00715a40(tmp[0], tmp[1], tmp[2], tmp2[0], tmp2[1], tmp2[2], (int)&v7);
    int val = *p;
    *p = 0;
    v7 = 0;

    int* q = &val;
    cb_005ce0d0();
    cb_0040b4c0();

    if (v8)
        cb_0080a058((void*)v8);

    *(int*)this = 0xaafd34;

    return this;
}
