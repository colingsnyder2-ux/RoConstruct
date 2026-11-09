// from server: 75% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_495f40(int);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int (__thiscall *g_call)(int, int);

int S::f()
{
    int a = *(int *)((char *)this + 0x0c);
    int b = *(int *)((char *)a + 0x0ac4);
    int c = sub_495f40(b);
    if (c)
    {
        c = sub_983b6a(c);
        return g_call(0xdec0b4, c);
    }
    return 0;
}
