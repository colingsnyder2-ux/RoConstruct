// from server: 56% by atomic.potato
extern "C" void* __cdecl Function4ED8C0(void*);
extern "C" int __cdecl Function4E1680(void*, void*, void*, void*);

int Function4EEC90(void* a, void* b, void* c, void* d)
{
    void* v;
    v = *static_cast<void**>(Function4ED8C0(a));
    return Function4E1680(d, c, &v, b);
}
