// from server: 100% by atomic.potato
struct CDataModelPropGrid
{
    void f();
};

extern "C" void __stdcall func_0042b280(int);

extern "C" void __cdecl func_0042a8a0();

void CDataModelPropGrid::f()
{
    if (*((unsigned char*)this + 0x108))
        func_0042b280(0);
    else
        func_0042a8a0();
}
