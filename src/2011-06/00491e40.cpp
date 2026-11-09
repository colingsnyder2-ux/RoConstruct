// from server: 100% by atomic.potato
extern "C" void __stdcall func_0080ab98();

struct S
{
    S* f();
};

S* S::f()
{
    func_0080ab98();
    *(unsigned long*)this = 0x00a74d44;
    *((unsigned char*)this + 0xf4) = 0;
    return this;
}
