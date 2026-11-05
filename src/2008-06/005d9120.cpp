// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_005d8e10();

int S::f()
{
    int value = sub_005d8e10();
    if (value)
        return value + 0x228;
    return 0;
}
