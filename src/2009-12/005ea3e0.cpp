// from server: 79% by atomic.potato
extern "C" void __cdecl free(void *);

void f(void *p)
{
    if (p)
        free((char *)p - 4);
}
