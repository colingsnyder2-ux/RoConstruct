// from server: 38% by atomic.potato
struct S
{
    void* f();
    void* member;
};

void* S::f()
{
    void* p = member;
    void** v = *(void***)p;
    return (void*)v[5];
}
