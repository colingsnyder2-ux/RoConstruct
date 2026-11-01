// from server: 100% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, void *, void *);

void f(void *a, void *b)
{
    UniversalTool(a, b, *(void **)0x00B62B58);
}
