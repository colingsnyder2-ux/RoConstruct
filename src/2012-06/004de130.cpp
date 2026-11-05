// from server: 85% by atomic.potato
struct VertexStreamer {
};

extern "C" void __stdcall TexturePtr_assign(void* dst, const void* src);

void __cdecl assign_range(void* first, void* last, const void* src)
{
    char* dst = (char*)first;
    const char* s = (const char*)src;
    if (dst == last)
        return;
    do {
        *(float*)dst = *(const float*)s;
        *(float*)(dst + 4) = *(const float*)(s + 4);
        TexturePtr_assign(dst + 8, s + 8);
        dst += 0x18;
    } while (dst != last);
}
