// from server: 100% by colin
extern "C" void __cdecl sub_4E68B0();
extern "C" void __cdecl sub_4E6740();

struct S {
    void f(void* type);
};

void S::f(void* type)
{
    unsigned int t = (unsigned int)type;
    if (t == 0x97b57c)
        goto call_6740;
    if (t == 0x975f14)
        goto call_68b0;
    if (t == 0x975ef8)
        goto call_68b0;
    if (t == 0x975f30)
        goto call_68b0;
    if (t == 0x975f68)
        goto call_6740;
    if (t == 0x975f4c)
        goto call_6740;
    return;

call_68b0:
    sub_4E68B0();
    return;

call_6740:
    sub_4E6740();
    return;
}
