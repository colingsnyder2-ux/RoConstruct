// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee returns a 2-float vector through a local buffer (first arg); args are (out, int, double, int).
extern "C" void* g_00962dac;
extern "C" int __fastcall fn_00684640(void* self, int unusedEdx, float* out, int a2, double a3, int a5);

extern "C" void __stdcall fn_0066fe30(float* result, int a2, double a3, int a5)
{
    float v[2];
    fn_00684640(g_00962dac, 0, v, a2, a3, a5);
    result[0] = v[0];
    result[1] = v[1];
}
