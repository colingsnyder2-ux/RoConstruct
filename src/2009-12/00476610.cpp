// from server: 71% by atomic.potato
struct CWebToolbox
{
    int __thiscall f();
};

extern "C" void __stdcall func_007f3c02(void*);

int __thiscall CWebToolbox::f()
{
    void* p = *(void**)((char*)this + 0xf8);
    if (p)
        func_007f3c02(p);
    return 3;
}
