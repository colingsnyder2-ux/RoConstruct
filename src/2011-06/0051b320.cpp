// from server: 57% by atomic.potato
extern "C" void __stdcall Call721520(void*, void*);
extern "C" void Call51AE40(void*);

struct S
{
    void f(void*);
};

void S::f(void* arg)
{
    void* local;
    Call721520(&local, arg);
    Call51AE40(this);
}
