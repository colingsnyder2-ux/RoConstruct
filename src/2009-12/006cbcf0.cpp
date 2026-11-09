// from server: 91% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void __stdcall G1_func_006edd70(void *, void *);
extern "C" void __stdcall G1_func_006cbc70(S *, void *);

void S::f(void *arg)
{
    G1_func_006edd70(*(void **)((char *)this + 0x168), (char *)arg + 0x30);
    G1_func_006cbc70(this, arg);
}
