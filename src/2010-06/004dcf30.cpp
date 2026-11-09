// from server: 79% by atomic.potato
extern "C" void __cdecl G1_func_00b94f80(void *);

struct S {
    int reserved;
    unsigned int value;
    void *handle;
    unsigned char enabled;
    void f();
};

void S::f()
{
    if (enabled != 0 && value > 0x2000)
        G1_func_00b94f80(handle);
}
