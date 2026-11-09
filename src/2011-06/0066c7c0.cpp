// from server: 72% by atomic.potato
struct RBX_Assembly
{
    char pad[0x28];
    void* field_24;
    void* get();
};

void* RBX_Assembly::get()
{
    char* p = (char*)field_24;
    char* q = *(char**)(p + 0x20);
    if (q != 0)
        return q - 8;
    return 0;
}

struct S
{
    void* f();
};

void* S::f()
{
    RBX_Assembly* p = (RBX_Assembly*)this;
    void* q = p->get();
    if (q != 0)
    {
        q = *(void**)((char*)q + 0x10c);
        if (q != 0)
            return (char*)q - 0xa0;
    }
    return 0;
}
