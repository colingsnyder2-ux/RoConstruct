// from server: 100% by king_originala
extern double __cdecl getNumber(void *, int);

extern const double *infinity;
extern const float *floatInfinity;
extern const double upperLimit;
extern const double lowerLimit;
extern const float upperResult;
extern const float lowerResult;

double __cdecl convertNumber(void *state, int index)
{
    double value = getNumber(state, index);

    if (value == *infinity)
        return *floatInfinity;
    if (value == -*infinity)
        return -*floatInfinity;

    if (!(value < 0.0) && !(value >= 0.0))
        return value;

    if (value > upperLimit)
        return upperResult;
    if (value < lowerLimit)
        return lowerResult;

    return value;
}
