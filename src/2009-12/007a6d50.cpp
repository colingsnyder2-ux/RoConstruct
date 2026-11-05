// from server: 40% by atomic.potato
struct S
{
    void* f(void*);
};

extern "C" void target();

void* S::f(void* p)
{
    if (p)
        p = (char*)p + 8;
    target();
    return p;
}
