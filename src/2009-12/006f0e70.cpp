// from server: 85% by atomic.potato
extern "C" void* __cdecl realloc(void*, unsigned int);
extern void G1_func_007e1df0(void*);

void* G2_func_007e1df0;
extern char G;
extern char G3_func_007e1df0;

void* func_006f0e70(void* p, void* q)
{
    void* r = realloc(p, (unsigned int)q);
    if (!r && q && G)
        G1_func_007e1df0(0);
    return r;
}
