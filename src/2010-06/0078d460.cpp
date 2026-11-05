// from server: 41% by atomic.potato
extern "C" void __cdecl sub_492840(void*);
extern "C" char __cdecl sub_7094f0(int, int, int, int);
extern "C" char __cdecl sub_78d400(int, int, int, int);
extern "C" void __cdecl sub_75ca80(int, int, int, int, void*, void*);
extern "C" void* __cdecl sub_7a79a0(unsigned int);
extern "C" void __cdecl sub_7096d0(void*, int, int, void*, void*);

struct MechToAssemblyStage {
    int __cdecl f(int, int, int, int);
};

int MechToAssemblyStage::f(int a, int b, int c, int d)
{
    if (!sub_78d400(a, b, c, d))
        return 0;
    if (!sub_7094f0(a, b, c, d))
        return 0;

    char buf1[0x30];
    char buf2[0x30];
    sub_492840(buf1);
    sub_492840(buf2);

    sub_75ca80(a, b, c, d, buf1, buf2);

    void* p = sub_7a79a0(0x98);
    if (!p)
        return 0;

    sub_7096d0(p, a, c, buf1, buf2);

    *(int*)p = 0xa3e2cc;
    *(int*)((char*)p + 0x20) = 0xa3e2ac;
    return (int)p;
}
