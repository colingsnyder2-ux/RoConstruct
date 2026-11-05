// from server: 100% by atomic.potato
extern "C" double __declspec(dllimport) __cdecl ceil(double);

double __cdecl f(double value)
{
    return ceil(value);
}
