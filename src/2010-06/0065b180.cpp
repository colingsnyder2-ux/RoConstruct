// from server: 64% by atomic.potato
struct S
{
    void f();
};

extern "C" void sub_65b120(void *);
extern "C" void __stdcall ios_base_dtor(void *);
extern void *g_9ea63c;
extern void *g_9ea648;
extern void *g_9ea64c;

void S::f()
{
    void *p = (char *)this + 0x5c;
    sub_65b120(p);
    *(void **)p = g_9ea64c;
    *(void **)p = g_9ea648;
    ios_base_dtor(p);
}
