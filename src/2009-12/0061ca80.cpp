// from server: 100% by atomic.potato
extern "C" void (__cdecl *free)(void *);

extern "C" void __cdecl function_0061ca80(void *unused, void *p)
{
    free(p);
}
