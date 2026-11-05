// from server: 93% by atomic.potato
struct S
{
    S& __cdecl f(void* value);
};

extern "C" void* __cdecl G1_func_004ed680(void* value);

S& S::f(void* value)
{
    void* p = G1_func_004ed680(value);
    *(void**)this = *(void**)p;
    *((void**)this + 1) = *((void**)p + 1);
    return *this;
}
