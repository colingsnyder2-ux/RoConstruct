// from server: 35% by atomic.potato
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct MeshFileKey {
    char pad0[0x30];
    char field30[0x1c];
    char pad4c[0x4c];
    char field4c[0x1c];
    char pad68[0x44];
    unsigned int field44;
    unsigned int Append(const void* src, unsigned int len);
};

unsigned int MeshFileKey::Append(const void* src, unsigned int len) {
    char* base;
    if (field44 < 0x10)
        base = field30;
    else
        base = *(char**)field30;

    unsigned int pos = 0x2c;
    unsigned int written = 0;

    if (len > 0) {
        unsigned int chunk;
        if (len <= 0x2c)
            chunk = len;
        else
            chunk = 0x2c;
        memcpy(base, src, chunk);
        written = chunk;
    }

    unsigned int chunk2;
    if (written >= len) {
        chunk2 = 0;
    } else {
        unsigned int remain = len - written;
        if (remain <= 4)
            chunk2 = remain;
        else
            chunk2 = 4;
        memcpy(field4c, (char*)src + written, chunk2);
        written += chunk2;
    }

    unsigned int slen = 0;
    {
        const char* p = (const char*)src;
        const char* q = p + 1;
        while (*p) p++;
        slen = (unsigned int)(p - q);
    }

    if (written >= len)
        return len;

    unsigned int remain2 = len - written;
    unsigned int chunk3;
    if (slen < remain2)
        chunk3 = slen;
    else
        chunk3 = remain2;
    memcpy(base + written, src, chunk3);
    written += chunk3;
    return written;
}
