// from server: 74% by atomic.potato
extern "C" double __cdecl modf(double, double *);

struct WedgeBuilder
{
    float f();
};

float WedgeBuilder::f()
{
    double integerPart;
    modf((double)0.0f, &integerPart);
    return (float)integerPart;
}
