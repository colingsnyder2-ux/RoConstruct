// from server: 100% by sophus
struct Callee
{
    void __thiscall invoke(void *, void *, unsigned int, unsigned int, unsigned int);
};

extern "C" void __cdecl sub_7F4929(void *);

void f()
{
    ((Callee *)0xB9727C)->invoke((void *)0x9E3E88, (void *)0x9D1B80, 0x11C, 2, 0);
    sub_7F4929((void *)0x989130);
}
