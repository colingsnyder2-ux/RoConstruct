// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl sub_007f5286(int);
extern "C" int (__thiscall *g_call)(void*, int);

struct TToolVerb
{
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    char f();
};

char TToolVerb::f()
{
    int a;
    int b;

    a = *(int *)((char *)this + 12);
    b = *(int *)((char *)a + 0xa90);
    a = *(int *)((char *)b + 0x1b4);
    if (a)
    {
        a = sub_007f5286(a);
        return g_call((void *)0xb3f46c, a);
    }
    return 0;
}