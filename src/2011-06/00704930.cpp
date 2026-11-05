// from server: 100% by atomic.potato
extern "C" void __cdecl ReleaseObject(void *);

struct S
{
    char padding[12];
    void *value;
    void f();
};

void S::f()
{
    if (value)
        ReleaseObject(value);
}
