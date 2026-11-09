// from server: 82% by atomic.potato
struct CSelectionCaption
{
    void f(void*, void*);
};

extern "C" void* func_008e1870(CSelectionCaption*);

void CSelectionCaption::f(void* a, void* b)
{
    void* p = func_008e1870(this);
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = *(Fn *)(*(unsigned long *)p + 0x10);
    fn(p, this, a);
}
