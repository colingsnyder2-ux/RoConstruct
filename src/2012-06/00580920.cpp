// from server: 100% by atomic.potato
extern "C" void __cdecl ReleaseObject(void*);

struct S
{
    int pad[7];
    void* a;
    void* b;
    void* c;

    void __stdcall f();
};

void __stdcall S::f()
{
    if (a != 0)
        ReleaseObject(a);
    a = 0;
    b = 0;
    c = 0;
}
