// from server: 87% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __stdcall timeGetTime();

struct S
{
    void __cdecl f(double *);
};

void __cdecl S::f(double *p)
{
    long t = (long)timeGetTime();
    double v = (double)t;
    if (t < 0)
        v += *(const double *)0x00a66290;
    v *= *(const double *)0x00a7eda0;
    *p = v;
}
