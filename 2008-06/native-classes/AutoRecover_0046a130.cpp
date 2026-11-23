// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: args are 4 float-vector pointers (cdecl, 4 stack args); only the y/[+4] slot is used.
// INFERRED: real callee takes 6 stack dwords (a,b,c,d,6,0.0f); the 9-arg convention hint is wrong.
extern "C" void fn_0046a010(float* a, float* b, float* c, float* d, int n, float z);
// INFERRED: constants at 0x819bac and 0x81c434 are read-only floats.
extern "C" const float g_00819bac;
extern "C" const float g_0081c434;

extern "C" void fn_0046a130(float* a, float* b, float* c, float* d)
{
    float t = a[1] + c[1];
    fn_0046a010(a, b, c, d, 6, 0.0f);
    b[1] = 0.0f;
    c[1] = t;
    float v = -(d[1] * g_00819bac - g_0081c434);
    if (v > c[1])
        c[1] = v;
}
