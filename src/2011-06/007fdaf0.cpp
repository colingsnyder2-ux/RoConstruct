// from server: 62% by atomic.potato
extern "C" double __cdecl func_00432230(double*);

double func_007fdaf0()
{
    double value;
    func_00432230(&value);
    if (value > 0.0)
        return 1.0 / value;
    return 0.0;
}
