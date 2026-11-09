// from server: 100% by atomic.potato
typedef int (__cdecl *FunctionType)(int);
typedef int (__thiscall *MethodType)(void *, int);

extern "C" int __cdecl sub_6a1de2(int);
extern MethodType global_call;

struct TToolVerb
{
    int value;
    char f();
};

char TToolVerb::f()
{
    int object = *(int *)((char *)this + 12);
    int context = *(int *)((char *)object + 516);
    int value = *(int *)((char *)context + 944);

    if (value)
    {
        value = sub_6a1de2(value);
        return global_call((void *)0x94fefc, value);
    }

    return 0;
}
