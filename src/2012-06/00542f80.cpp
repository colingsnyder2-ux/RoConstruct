// from server: 73% by atomic.potato
extern "C" void __stdcall sub_4289e0(void *, void *);

struct S {
    void *f(void *);
};

void *S::f(void *p)
{
    void *result;
    sub_4289e0((char *)this + 0x1a4, p);
    result = p;
    return result;
}
