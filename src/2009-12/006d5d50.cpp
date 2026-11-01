// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl Function_007f5286(int);
extern "C" int (__thiscall *Global_0098b768)(void*, int);

struct S
{
    char f();
};

char S::f()
{
    int value = *(int *)(*(int *)((char *)this + 12) + 0xa90);
    value = *(int *)(value + 0x1b4);
    if (value)
    {
        value = Function_007f5286(value);
        return Global_0098b768((void *)0xb3f8a0, value);
    }
    return 0;
}