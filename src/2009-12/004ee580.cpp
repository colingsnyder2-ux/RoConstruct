// from server: 37% by atomic.potato
extern "C" double __cdecl fabs(double);

double f(double *p)
{
    double x = *p;
    return fabs(x);
}
