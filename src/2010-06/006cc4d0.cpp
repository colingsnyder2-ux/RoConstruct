// from server: 57% by atomic.potato
extern "C" void __stdcall sub_6cbff0(void*, void*);

struct S
{
    void f(void*);
};

void S::f(void* value)
{
    void* p = *(void**)this;
    if (p)
        sub_6cbff0(p, value);
}
