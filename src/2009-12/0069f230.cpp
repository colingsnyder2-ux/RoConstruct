// from server: 100% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, void *, void *);

void *g_value;

void f(void *a, void *b)
{
    UniversalTool(a, b, g_value);
}
