// from server: 100% by atomic.potato
struct CXTPControlSelector
{
    void* f();
    void* g(void* p);
};

void* CXTPControlSelector::g(void* p)
{
    void* v = f();
    ((void (__thiscall*)(void*, void*, void*))(*(void***)v)[56])(v, this, p);
    return v;
}
