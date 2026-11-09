// from server: 65% by atomic.potato
extern "C" void __cdecl G1_func_0080b1d8(void *, int, int, const char *);

struct S
{
    void value();
};

void S::value()
{
    G1_func_0080b1d8((char *)this + 0xd4, 0x14, 2, "QVRP");
}
