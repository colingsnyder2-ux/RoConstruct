// from server: 53% by atomic.potato
typedef double (*FunctionType)(double *);

extern "C" double __cdecl CallFunction(FunctionType, double *);

double Function(double value)
{
    double result;
    CallFunction((FunctionType)0x42a2d0, &result);
    if (result < 0.0)
        return 1.0 / value;
    return value;
}
