// from server: 88% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall sub_53bf90(int, int);

void S::f()
{
    sub_53bf90(0, *(unsigned char *)((char *)this + 0x266d));
}
