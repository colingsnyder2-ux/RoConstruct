// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
float* getv();
float* __cdecl f(float* a, float* b, float* c)
{
    float* p = getv();
    b[0] = p[0];
    b[1] = p[1];
    c[0] = a[0] + c[0];
    c[1] = a[1] + c[1];
    return c;
}
