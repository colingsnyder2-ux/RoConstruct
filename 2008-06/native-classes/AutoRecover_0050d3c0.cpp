// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: color lerp, out[i] = (int)(a[i]*(1-t)) + b[i]*t per byte; signature from stack usage.
extern "C" void fn_0050d3c0(unsigned char* out, unsigned int a, unsigned int b, float t)
{
    float s = 1.0f - t;
    out[0] = (unsigned char)((float)(int)((a & 0xff) * s) + (b & 0xff) * t);
    out[1] = (unsigned char)((float)(int)(((a >> 8) & 0xff) * s) + ((b >> 8) & 0xff) * t);
    out[2] = (unsigned char)((float)(int)(((a >> 16) & 0xff) * s) + ((b >> 16) & 0xff) * t);
    out[3] = (unsigned char)((float)(int)((a >> 24) * s) + (b >> 24) * t);
}
