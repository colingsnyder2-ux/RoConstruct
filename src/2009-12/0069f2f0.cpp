// from server: 74% by atomic.potato
extern "C" void *__cdecl UniversalTool(void *, int, void *);

struct S
{
};

int __cdecl f(void *p)
{
    void *q = UniversalTool(p, 1, *((void **)0x00b62b40));
    void (**vtable)(void *, int) = *(void (***)(void *, int))q;
    vtable[0](q, 0);
    return 0;
}
