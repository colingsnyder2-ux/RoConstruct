// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl sub_7f5286(int);
extern "C" int (__thiscall *sub_98b768)(void*, int);

struct S
{
    char f();
};

char S::f()
{
    int value = *(int *)((char *)this + 12);
    void *object = *(void **)((char *)value + 0xa90);
    int argument = *(int *)((char *)object + 0x1b4);
    if (argument)
    {
        int converted = sub_7f5286(argument);
        return sub_98b768((void *)0xb3fbf4, converted);
    }
    return 0;
}