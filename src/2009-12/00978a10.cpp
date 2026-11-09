// from server: 100% by sophus
struct Callee
{
    void __thiscall invoke(void *, void *, unsigned int, unsigned int, void *);
};

extern "C" void __cdecl sub_7f4929(void *);

void f()
{
    ((Callee *)0xb958e0)->invoke((void *)0x9df8d4, (void *)0x9d1fdc, 0xb4, 0xf, 0);
    sub_7f4929((void *)0x987ec0);
}
