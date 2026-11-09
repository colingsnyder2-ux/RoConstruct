// from server: 43% by atomic.potato
typedef void* (__thiscall *Callback)(void*, void*);
extern "C" void* __cdecl sub_0066FA00(void*);

struct S
{
    void* f(void*, void*);
};

void* S::f(void* a, void* b)
{
    void* p = *(void**)((char*)this + 0x1c);
    void* q = *(void**)p;
    void* v = sub_0066FA00(&b);
    Callback fn = *(Callback*)((char*)q + 0x0c);
    return fn(p, v);
}
