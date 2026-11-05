// from server: 100% by why2
extern "C" double (__cdecl *ceil_ptr)(double);

double __cdecl sub_004f4f60(double x)
{
    return ceil_ptr(x);
}
