// from server: 76% by atomic.potato
extern "C" void __stdcall sub_5f3990(void *, void *, int);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    sub_5f3990((char *)this + 0xc8, p, 1);
}
