// from server: 100% by colin
extern "C" int (__cdecl *memcpy_s)(void*, unsigned int, const void*, unsigned int);

struct CXTPToolTipContext_CRichEditToolTip
{
    char pad[0x3c];
    int field_3c;
    void* construct(void* src);
};

void* CXTPToolTipContext_CRichEditToolTip::construct(void* src)
{
    field_3c = 0;
    memcpy_s(this, 0x3c, src, 0x3c);
    return this;
}
