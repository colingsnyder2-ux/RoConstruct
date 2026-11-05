// from server: 86% by atomic.potato
struct S;

extern "C" void __stdcall sub_7b5be0(void *, void *);
extern "C" void __stdcall sub_7a1d00(void *, void *);

struct S {
    void f(void *);
};

void S::f(void *p)
{
    sub_7b5be0(*(void **)((char *)this + 8), p);
    sub_7a1d00(p, this);
}
