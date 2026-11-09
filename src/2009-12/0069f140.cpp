// from server: 82% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, void *, void *);
extern "C" void __cdecl UniversalTool2(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    void *p = *(void **)0x00b532fc;
    UniversalTool(this, (void *)1, p);
    UniversalTool2(this, (void *)0x009d2a54);
    return 1;
}
