// from server: 77% by atomic.potato
extern "C" void __cdecl ios_base_dtor(void *);

struct S
{
    int pad[24];
    void f();
};

extern "C" void destroy_stream(void *);

void S::f()
{
    void *p = (void *)((char *)this + 0x60);
    destroy_stream(p);
    *(void **)p = *(void **)0x98b4a4;
    *(void **)p = *(void **)0x98b4a0;
    ((void (__cdecl *)(void *))*(void **)0x98b494)(p);
}
