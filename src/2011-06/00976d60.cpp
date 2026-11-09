// from server: 54% by atomic.potato
extern "C" void __cdecl func_00976c70(void*, void*);

struct S
{
    S* f(void*, void*);
};

S* S::f(void* a, void* b)
{
    func_00976c70(b, a);
    return this;
}
