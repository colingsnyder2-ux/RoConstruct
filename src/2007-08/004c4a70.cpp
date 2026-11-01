// from server: 100% by colin
extern "C" double (__cdecl *g_ceil)(double);

double func_004c4a70(double value)
{
    return g_ceil(value);
}
