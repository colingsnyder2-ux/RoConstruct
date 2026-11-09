// from server: 62% by atomic.potato
struct RefPropDescriptor
{
    int f(void* a, void* b, void* c);
};

int RefPropDescriptor::f(void* a, void* b, void* c)
{
    void* p1 = this ? (char*)this + 0x1c : 0;
    void* p2 = a ? (char*)a + 0x10 : 0;
    return ((int (__thiscall *)(void*, void*, void*, void*))(*(int**)c)[1])(c, p2, p1, 0);
}
