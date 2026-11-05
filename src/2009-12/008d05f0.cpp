// from server: 16% by atomic.potato
extern "C" long __stdcall DispatchMessageA(void *);

int f()
{
    long eax;
    long ebx;
    if (eax == ebx)
        return 0;
    DispatchMessageA((void *)((char *)&eax + 24));
    return 0;
}
