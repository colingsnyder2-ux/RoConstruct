// from server: 58% by atomic.potato
extern "C" void sub_6e0990(void *);
extern "C" void __cdecl ios_base_dtor(void *);

extern void *g_98b494;
extern void *g_98b4a0;
extern void *g_98b4a4;

struct DxUserInput
{
    void *field_5c;
    void f();
};

void DxUserInput::f()
{
    void *p = (char *)this + 0x5c;
    sub_6e0990(p);
    *(void **)p = g_98b4a4;
    *(void **)p = g_98b4a0;
    ((void (__cdecl *)(void *))g_98b494)(p);
}
