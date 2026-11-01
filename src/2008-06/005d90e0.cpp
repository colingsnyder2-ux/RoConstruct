// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_5d8d10();

int S::f()
{
    int v = sub_5d8d10();
    if (v)
        return v + 0x228;
    return 0;
}
