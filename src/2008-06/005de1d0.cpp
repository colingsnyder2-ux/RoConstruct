// from server: 100% by king_originala
extern "C" double __cdecl fabs(double);

bool __cdecl compare(const float* a, const float* b, float epsilon)
{
    for (int i = 0; i < 3; ++i)
    {
        const double av = a[i];
        const double bv = b[i];
        if (!(av == bv ||
              fabs(av - bv) <= (fabs(av) + 1.0) * epsilon))
            return false;
    }
    return true;
}
