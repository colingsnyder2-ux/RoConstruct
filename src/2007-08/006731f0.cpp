// from server: 100% by colin
struct CXTPControlColorSelector {
    void* f(int);
};

extern void* g_00673180();

void* CXTPControlColorSelector::f(int a)
{
    void* p = g_00673180();
    (*(void (__thiscall**)(void*, void*, int))(*(int*)p + 0xe0))(p, this, a);
    return p;
}
