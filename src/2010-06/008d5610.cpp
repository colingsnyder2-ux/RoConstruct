// from server: 84% by atomic.potato
struct TexturePtr {
    void operator=(const TexturePtr&);
};

struct VertexStreamer {
};

void __cdecl copyRange(void* first, void* last, const void* src)
{
    char* dst = (char*)first;
    char* end = (char*)last;
    const char* s = (const char*)src;
    if (dst != end) {
        do {
            *(float*)dst = *(const float*)s;
            *(float*)(dst + 4) = *(const float*)(s + 4);
            *(TexturePtr*)(dst + 8) = *(const TexturePtr*)(s + 8);
            dst += 0x18;
        } while (dst != end);
    }
}
