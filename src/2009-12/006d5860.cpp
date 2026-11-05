// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl sub_007f5286(int);
extern "C" int (__thiscall *g_call)(void*, int);

struct S
{
    int pad0[3];
    int p;
    char f();
};

char S::f()
{
    int a = *(int *)((char *)p + 0xa90);
    int b = *(int *)((char *)a + 0x1b4);
    if (b)
        return g_call((void *)0xb3f518, sub_007f5286(b));
    return 0;
}