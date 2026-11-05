// from server: 58% by atomic.potato
extern "C" void __cdecl helper_983bb8();

void __stdcall func_00a7e985(int* src, int* dst, float* out)
{
    if (dst)
    {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    if (out)
    {
        float v = *(float*)((char*)src + 12);
        helper_983bb8();
        v = v + v;
        *out = v;
    }
}
