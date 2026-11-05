// from server: 70% by atomic.potato
extern "C" void G1_func_007f38c6();

struct CXTColorHex
{
    void f();
    void (*vtable[85])();
    char pad[1];
    unsigned char flag;
};

void CXTColorHex::f()
{
    G1_func_007f38c6();
    if (flag)
        vtable[83]();
}
