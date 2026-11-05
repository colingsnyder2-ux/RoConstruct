// from server: 100% by atomic.potato
typedef void (__thiscall *DestroyStream)(void *);
typedef void (__cdecl *DeleteObject)(void *);

extern DestroyStream g_destroy_stream;
extern "C" void __cdecl delete_stream(void *);

struct S
{
    int f(int);
};

int S::f(int a)
{
    char *p = (char *)this - 0x50;
    g_destroy_stream(p);
    if (a & 1)
        delete_stream(p);
    return (int)p;
}
