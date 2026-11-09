// from server: 21% by atomic.potato
extern float g_a63b14;
extern float g_a75cec;

float ClampRange(float lo, float hi)
{
    float zero = 0.0f;
    float maxv = g_a75cec;

    if (!(zero < lo))
        lo = zero;
    else if (!(lo < maxv))
        lo = maxv;

    if (zero < hi)
    {
        if (!(hi < maxv))
            zero = maxv;
        else
            zero = hi;
    }

    float mid = g_a63b14;

    if (!(mid < lo) && !(mid < zero))
    {
        if (lo > zero)
            return zero;
        return lo;
    }

    if (lo < mid && zero < mid)
        return lo + zero - mid;

    if (lo > zero)
        return zero;
    return lo;
}
