// from server: 100% by atomic.potato
typedef int (__cdecl *Fn)(int);
typedef int (__thiscall *TypeInfoEqual)(void *, const void *);

extern "C" int __cdecl sub_7a93c6(int);
extern "C" TypeInfoEqual g_typeInfoEqual;

struct TToolVerb
{
    char f();
    int pad0[3];
};

char TToolVerb::f()
{
    int a = *(int *)((char *)this + 12);
    int b = *(int *)((char *)a + 0xaa0);
    int v = *(int *)((char *)b + 0x1b4);
    if (v)
    {
        v = sub_7a93c6(v);
        return g_typeInfoEqual((void *)0xbb7534, (const void *)v);
    }
    return 0;
}
