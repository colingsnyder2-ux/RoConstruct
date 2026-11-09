// from server: 17% by atomic.potato
struct S
{
    void* f(void*);
    void* g(void*);
    void* h(void*);
};

void* S::f(void* p)
{
    return 0;
}

void* S::g(void* p)
{
    return 0;
}

void* S::h(void* p)
{
    return g((char*)f((char*)p + 4));
}
