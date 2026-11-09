// from server: 65% by atomic.potato
typedef int (__thiscall *Callback)(int, int, int, float, float);

struct ArcHandles
{
    int enabled;
    int pad;
    Callback *callback;
    int __cdecl f(int, int, int, float, float);
};

int ArcHandles::f(int a, int b, int c, float d, float e)
{
    if (enabled)
        return (*callback)(a, b, c, d, e);
    return 0;
}
