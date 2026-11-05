// from server: 100% by atomic.potato
struct BoundFuncDesc
{
    void f(unsigned char value);
};

extern "C" void __stdcall G1_func_00414da0(unsigned long);

void BoundFuncDesc::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)this + 0x86))
    {
        *(unsigned char*)((char*)this + 0x86) = value;
        G1_func_00414da0(0xE51BFC);
    }
}
