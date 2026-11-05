// from server: 86% by atomic.potato
extern "C" int __cdecl func_007f4cf0(float);

struct Kernel
{
    int f();
    int pad0[6];
};

int Kernel::f()
{
    int *p = *(int **)((char *)this + 0x18);
    int n = *(int *)((char *)p + 4);
    int v = *(int *)((char *)p + 0x28);
    v += n * 6 + 4;
    return func_007f4cf0((float)v) + 1;
}
