// from server: 100% by atomic.potato
struct S
{
};

extern "C" int __cdecl sub_007fe4e0(int);
extern "C" void __cdecl sub_007fd7e0(int);

struct Global
{
    char padding[0x144];
    int value;
};

extern Global *g_00b9ada4;

void __cdecl f(int value)
{
    sub_007fd7e0(sub_007fe4e0(value));
    g_00b9ada4->value = value;
}
