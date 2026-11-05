// from server: 84% by atomic.potato
// roc 2009-12 0048c8f0  unit: G3D::Shader  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048c8f0

struct Shader {
};

void __cdecl copyRange(void* dst, void* end, const void* src)
{
    char* d = (char*)dst;
    char* e = (char*)end;
    const char* s = (const char*)src;
    if (d == e)
        return;
    d += 8;
    do {
        d += 0x10;
        *(float*)(d - 0x18) = *(const float*)(s);
        *(float*)(d - 0x14) = *(const float*)(s + 4);
        *(float*)(d - 0x10) = *(const float*)(s + 8);
        *(int*)(d - 0xc) = *(const int*)(s + 0xc);
    } while ((char*)(d - 8) != e);
}
