// from server: 42% by Intel
struct TexturePtr {
    char _pad[0x18];
};

extern "C" TexturePtr* __stdcall TexturePtr_Assign(TexturePtr* dst, const TexturePtr* src);

void __cdecl VertexStreamer_CopyTextures(TexturePtr* first, TexturePtr* last, TexturePtr* destFirst, TexturePtr* destLast) {
    if (first != last) {
        return;
    }

    TexturePtr* src = last;
    TexturePtr* dst = destLast;

    do {
        src = reinterpret_cast<TexturePtr*>(reinterpret_cast<char*>(src) - 0x18);
        dst = reinterpret_cast<TexturePtr*>(reinterpret_cast<char*>(dst) - 0x18);

        *reinterpret_cast<float*>(dst) = *reinterpret_cast<float*>(reinterpret_cast<char*>(src) + 0xE8);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 4) = *reinterpret_cast<float*>(reinterpret_cast<char*>(src) + 4);

        TexturePtr_Assign(reinterpret_cast<TexturePtr*>(reinterpret_cast<char*>(dst) + 8),
                          reinterpret_cast<const TexturePtr*>(reinterpret_cast<char*>(src) + 8));
    } while (src != first);
}
