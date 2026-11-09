// from server: 78% by atomic.potato
extern "C" void __stdcall G1_func_00983270(void*, unsigned int, unsigned int, const char*);

struct S
{
    void f();
};

void S::f()
{
    G1_func_00983270((char*)this + 0xf80, 0x20, 7, "SUVW");
}
