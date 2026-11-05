// from server: 100% by atomic.potato
struct S {
    char pad[0x98];
    int count;
    char pad2[0x3c];
    void* table;
    void f(void* p);
};

void S::f(void* p)
{
    void** v = *(void***)table;
    ((void (__thiscall *)(void*, void*))v[4])(table, p);
    if (p != 0)
        ((void (__thiscall *)(void*, int))(*(void***)p)[0])(p, 1);
    --count;
}
