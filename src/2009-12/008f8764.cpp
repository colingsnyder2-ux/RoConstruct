// from server: 58% by atomic.potato
extern "C" void __cdecl func_007f5292();

void __stdcall func_008f8764(int* src, int* dst1, float* dst2)
{
    if (dst1)
    {
        dst1[0] = src[0];
        dst1[1] = src[1];
        dst1[2] = src[2];
    }
    if (dst2)
    {
        float v = *(float*)((char*)src + 12);
        func_007f5292();
        *dst2 = v + v;
    }
}
