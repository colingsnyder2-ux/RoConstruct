// from server: 84% by atomic.potato
extern "C" double *__cdecl sub_009776b0(double);
extern "C" int sub_0097b3b0(double *);

struct S_func_006cfa30 {
    int f(double);
};

int S_func_006cfa30::f(double value)
{
    double *p = sub_009776b0(value);
    return sub_0097b3b0(p);
}
