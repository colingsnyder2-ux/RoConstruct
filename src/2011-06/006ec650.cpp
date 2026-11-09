// from server: 49% by atomic.potato
extern "C" int __stdcall CloseHandle(void *);

struct S
{
    int f();
    int vtable;
    char pad[0x2c];
    void *handle;
};

int S::f()
{
    vtable = 0xaa8b38;
    void *h = handle;
    handle = 0;
    if (h)
        CloseHandle(h);
    return 0;
}
