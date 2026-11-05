// from server: 67% by atomic.potato
struct S_func_007e7e90 {
    char pad0[92];
    void* f(void* p);
};

extern "C" void* __stdcall func_006a2ce0(void*, void*, int);

void* S_func_007e7e90::f(void* p)
{
    func_006a2ce0((char*)this + 92, p, 0);
    return p;
}
