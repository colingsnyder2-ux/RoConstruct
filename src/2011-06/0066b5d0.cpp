// from server: 61% by atomic.potato
extern "C" unsigned long __stdcall TlsSetValue(unsigned long, void*);

extern void* g_00ccdf00;
extern void* g_00a402b0;

struct Profiler
{
    void* value;
};

Profiler* __stdcall sub_0066b5d0(Profiler* p, void* a, void* b)
{
    p->value = g_00a402b0;
    TlsSetValue((unsigned long)g_00ccdf00, p);
    return p;
}
