// from server: 100% by colin
struct CXTPControl {
    void* GetSomething();
    void* f(int arg);
};

void* CXTPControl::f(int arg)
{
    void* p = GetSomething();
    void* vtable = *(void**)p;
    void (__thiscall *fn)(void*, void*, int) = *(void (__thiscall **)(void*, void*, int))((char*)vtable + 0xe0);
    fn(p, this, arg);
    return p;
}
