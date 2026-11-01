// from server: 86% by atomic.potato
extern "C" void __cdecl func_00724680(void*);

extern void* g_0098b494;
extern void* g_0098b4a0;
extern void* g_0098b4a4;

struct StreamBuffer
{
    char data[20];
    void* value;

    void func();
};

void StreamBuffer::func()
{
    func_00724680(this);
    value = g_0098b4a4;
    value = g_0098b4a0;
    ((void (__cdecl *)(void*))g_0098b494)(&value);
}
