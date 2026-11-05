// from server: 87% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_42cba0(unsigned char);

void S::f()
{
    sub_42cba0(*(unsigned char *)((char *)this + 0xfc) == 0);
}
