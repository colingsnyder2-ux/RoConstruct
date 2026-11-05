// from server: 100% by atomic.potato
struct TToolVerb
{
    char f();
};

extern "C" int __cdecl sub_7a93c6(int);
extern "C" int (__thiscall *g_call)(int, int);

char TToolVerb::f()
{
    int a;
    int b;

    a = *(int *)((char *)this + 12);
    b = *(int *)((char *)a + 2720);
    a = *(int *)((char *)b + 436);
    if (a)
    {
        a = sub_7a93c6(a);
        return g_call(0xBB6F00, a);
    }
    return 0;
}
