// from server: 86% by atomic.potato
typedef int (__cdecl *Fn)(int, int, int, int, int);

int __stdcall f(int a);

int __stdcall f(int a)
{
    Fn fn = (Fn)0x007a8bea;
    return !fn(a, 0, 0x00b78e40, 0x00bcd95c, 0);
}
