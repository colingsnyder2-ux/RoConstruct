// from server: 32% by atomic.potato
struct S_func_0049b030
{
    char pad0[268];
    void *m_callback;
    void f();
};

void S_func_0049b030::f()
{
    void **vtable = *(void ***)m_callback;
    void (__thiscall *method)(void *) =
        (void (__thiscall *)(void *))vtable[3];
    method(m_callback);
}

struct ToggleFullscreenVerb
{
    char pad0[12];
    S_func_0049b030 *callback;
    unsigned char f();
};

unsigned char ToggleFullscreenVerb::f()
{
    callback->f();
    return 1;
}
