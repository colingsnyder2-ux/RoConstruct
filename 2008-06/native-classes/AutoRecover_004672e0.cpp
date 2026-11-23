// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: sign(v) is 1 / -1 / 0; the constant at 0x81c3b8 is taken as -1.0f.
// INFERRED: signature (float* out, const float* in, int n) from the cdecl stack args.
static inline float signOf(float v)
{
    return v > 0.0f ? 1.0f : (v < 0.0f ? -1.0f : 0.0f);
}

extern "C" float* fn_004672e0(float* out, const float* in, int n)
{
    out[0] = in[0];
    out[1] = in[1];
    out[0] += signOf(in[0]) * (float)n;
    out[1] += signOf(in[1]) * (float)n;
    return out;
}
