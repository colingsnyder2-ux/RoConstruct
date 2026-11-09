// from server: 32% by atomic.potato
extern "C" void *__cdecl Function71a010(void *);

struct TypedPropertyDescriptor
{
    void __stdcall f(void *, void *);
};

void __stdcall TypedPropertyDescriptor::f(void *a, void *b)
{
    void **p = *(void ***)((char *)this + 0x1c);
    void *value = Function71a010(b);
    typedef void (__thiscall *Call)(void *, void *, void *);
    ((Call)*(void **)((char *)p[0] + 0xc))(p, a, value);
}
