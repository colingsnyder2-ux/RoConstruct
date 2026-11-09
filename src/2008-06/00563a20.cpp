// from server: 100% by colin
extern const double limit;
extern double result;

void __stdcall setValue(double value)
{
    const double bound = limit;
    const double* selected = bound > value ? &bound : &value;
    result = *selected;
}
