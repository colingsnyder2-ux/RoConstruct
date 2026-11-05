// from server: 47% by atomic.potato
struct S
{
    int f(void*, void*, void*, void*, void*, void*);
};

int S::f(void* a, void* b, void* c, void* d, void* e, void* f)
{
    struct V
    {
        int (**vtable)(void*, void*, void*, void*, void*);
    };

    V* p = *(V**)((char*)a - 204);
    p = *(V**)((char*)p + 32);
    return p->vtable[105](f, e, d, c, b);
}
