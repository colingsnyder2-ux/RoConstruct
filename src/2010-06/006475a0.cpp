// from server: 100% by atomic.potato
typedef int (__cdecl *FunctionType)(int);
typedef int (__thiscall *MethodType)(void *, int);

extern "C" int __cdecl sub_7A93C6(int);
extern "C" MethodType import_9EA8D8;

struct S
{
    char f();
};

char S::f()
{
    int value = *(int *)((char *)this + 12);
    int object = *(int *)((char *)value + 2720);
    int argument = *(int *)((char *)object + 436);
    if (argument)
    {
        value = sub_7A93C6(argument);
        return import_9EA8D8((void *)0x00BB6E54, value);
    }
    return 0;
}
