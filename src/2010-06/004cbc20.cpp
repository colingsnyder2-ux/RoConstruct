// from server: 32% by atomic.potato
extern "C" void __cdecl G1_func_004cb6c0();

struct BoundFuncDesc {
    int field_15c;
    void f();
};

void BoundFuncDesc::f()
{
    if (!field_15c)
        G1_func_004cb6c0();
}
