// from server: 50% by tajop
extern "C" int __sse2_available;
extern "C" long __cdecl _ftol2(double x);

extern "C" long __cdecl _ftol2_sse(double x)
{
    if (__sse2_available != 0)
        return (long)x;
    return _ftol2(x);
}
