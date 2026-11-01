// from server: 100% by atomic.potato
typedef int (__cdecl *Fn)(int);
typedef int (__thiscall *Cmp)(void *, const void *);

extern "C" int __cdecl sub_006a1de2(int);
extern "C" int (__thiscall *g_call_00802878)(void *, int);

struct TToolVerb
{
    int pad0[3];
    void *owner;
    unsigned char f();
};

unsigned char TToolVerb::f()
{
    int a = *(int *)((char *)owner + 0x204);
    int b = *(int *)((char *)a + 0x3b0);
    if (b)
    {
        b = sub_006a1de2(b);
        return g_call_00802878((void *)0x95017c, b);
    }
    return 0;
}
