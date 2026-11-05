// from server: 62% by atomic.potato
extern "C" void G1_func_007f4929(const char *);

void func_00651aa0()
{
    volatile int *x = reinterpret_cast<volatile int *>(0x2559e800);
    *x += reinterpret_cast<int>(x);
    G1_func_007f4929("8csm");
}
