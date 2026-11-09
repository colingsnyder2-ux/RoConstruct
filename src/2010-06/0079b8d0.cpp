// from server: 62% by atomic.potato
extern "C" void __cdecl f_42a800(double*);

double f_0079b8d0()
{
    double value;
    f_42a800(&value);
    if (value > 0.0)
        return 1.0 / value;
    return 0.0;
}
