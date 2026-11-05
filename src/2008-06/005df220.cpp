// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" double __cdecl fabs(double);

float __cdecl maxAbs(const float* v)
{
    const float a[3] = {
        (float)fabs(v[0]),
        (float)fabs(v[1]),
        (float)fabs(v[2])
    };
    const float& yz = a[1] < a[2] ? a[2] : a[1];
    const float& result = a[0] < yz ? yz : a[0];
    return result;
}
