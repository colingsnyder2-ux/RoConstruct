// from server: 100% by atomic.potato
extern "C" void __cdecl func_00724710();
extern "C" void (__cdecl *g_func_0098b494)(void *);

void *g_0098b4a0;
void *g_0098b4a4;

struct StreamBuffer
{
    char pad[0x18];
    void *value;

    void f();
};

void StreamBuffer::f()
{
    func_00724710();
    value = g_0098b4a4;
    value = g_0098b4a0;
    g_func_0098b494(&value);
}
