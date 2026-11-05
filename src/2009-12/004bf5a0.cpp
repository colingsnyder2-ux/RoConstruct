// from server: 82% by atomic.potato
extern "C" void __stdcall sub_004bf380(void *);
extern "C" void __stdcall removeAllChildren(void *);

struct S_func_004bf5a0
{
    void f();
};

void S_func_004bf5a0::f()
{
    sub_004bf380(this);
    removeAllChildren(this);
}
