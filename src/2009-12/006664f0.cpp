// from server: 17% by atomic.potato
extern "C" {
    void __stdcall G1_func_0098b6f0();
    void __stdcall G1_func_0098b6e4();
}

struct S {
    void* field0;
    char pad[0x24];
    void f();
};

void S::f()
{
    void* p = *(void**)((char*)this + 0x28);
    field0 = p;
    G1_func_0098b6f0();
    G1_func_0098b6e4();
}
