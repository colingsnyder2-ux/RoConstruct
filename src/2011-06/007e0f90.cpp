// from server: 100% by atomic.potato
struct HammerTool
{
    void f(void*);
};

void HammerTool::f(void* arg)
{
    void* p = *(void**)((char*)this + 0x1c);
    if (p != 0)
    {
        void* q = (char*)p + 0xac;
        void** vtable = *(void***)q;
        typedef void (__thiscall *Fn)(void*, void*, int);
        Fn fn = *(Fn*)((char*)vtable + 0x1c);
        fn(q, arg, 1);
    }
}
