// from server: 65% by atomic.potato
extern "C" void __cdecl sub_0080B1D8(void *, unsigned int, unsigned int, const char *);

struct S
{
    int value;
    void f();
};

void S::f()
{
    sub_0080B1D8((char *)this + 0x1560, 0x20, 7, "l$ VWUP");
}
