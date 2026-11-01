// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_5d8a10();

int S::f()
{
    int value = sub_5d8a10();
    if (value)
        return value + 0x228;
    return 0;
}
