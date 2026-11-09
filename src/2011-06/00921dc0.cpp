// from server: 63% by atomic.potato
extern "C" void __cdecl sub_6500B0(int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int local = 0;
    local = *(int*)0xD1F018;
    ++*(int*)0xD1F018;
    sub_6500B0(value, (int)&local);
    return value;
}
