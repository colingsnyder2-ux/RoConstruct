// from server: 97% by sophus
struct S_func_0091d720
{
    char pad0[64];
    void* m_p;
    void f(int value);
};

void S_func_0091d720::f(int value)
{
    void* p = *(void**)((char*)m_p + 0x1c);
    void** vtable = *(void***)p;
    typedef void (__thiscall *Fn)(void*, int);
    ((Fn)vtable[0xc4])(p, 1);
    vtable = *(void***)p;
    ((Fn)vtable[0xc1])(p, value);
}
