// from server: 86% by atomic.potato
extern "C" void __stdcall Call917430(void*, void*);
extern "C" void __stdcall Call926db0(void*, void*);

struct S
{
    void f(void*);
};

void S::f(void* arg)
{
    Call917430(arg, this);
    Call926db0(*(void**)((char*)this + 8), arg);
}
