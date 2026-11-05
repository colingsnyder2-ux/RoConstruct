// from server: 85% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void __stdcall call_7d9f70(S *, void *);
extern "C" void __stdcall call_7b2f40(void *, S *);

void S::f(void *p)
{
    call_7d9f70(this, p);
    call_7b2f40(p, this);
}
