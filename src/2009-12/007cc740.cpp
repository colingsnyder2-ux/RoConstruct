// from server: 100% by atomic.potato
struct GroupDropTool
{
    void f(void *);
};

extern "C" void __stdcall G1_func_007dbd60(void *);

void GroupDropTool::f(void *arg)
{
    int value = *(int *)((char *)arg + 8);
    if (value != 8 && value != 0x1b && value != 0x7f)
    {
        G1_func_007dbd60(arg);
        return;
    }

    void **table = *(void ***)((char *)this + 0x38);
    ((void (__thiscall *)(void *))table[0])((char *)this + 0x38);
}
