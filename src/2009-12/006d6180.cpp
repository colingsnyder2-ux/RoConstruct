// from server: 100% by colin
// from server: 97% by atomic.potato
typedef char BOOL;

extern "C" int __cdecl sub_007f5286(int);
extern "C" int (__thiscall *imported_0098b768)(void*, int);

struct S
{
    int pad0[3];
    void *p;
    char f();
};

char S::f()
{
    int *a = *(int **)((char *)p + 0xa90);
    int v = *(int *)((char *)a + 0x1b4);
    if (v)
    {
        v = sub_007f5286(v);
        return imported_0098b768((void *)0xb3fb4c, v);
    }
    return 0;
}