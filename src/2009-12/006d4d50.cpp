// from server: 100% by atomic.potato
struct S
{
    bool f();
};

extern "C" int __cdecl sub_7f5286(int);

typedef bool (__thiscall *VerbFn)(void *, int);
extern VerbFn g_verbFn;

bool S::f()
{
    int v = *(int *)((char *)this + 12);
    v = *(int *)((char *)v + 0xA90);
    v = *(int *)((char *)v + 0x1B4);
    if (v)
        return g_verbFn((void *)0xB3EFC4, sub_7f5286(v));
    return false;
}
