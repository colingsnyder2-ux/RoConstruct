// from server: 100% by atomic.potato
extern "C" unsigned int (__cdecl *strnlen)(const char* s, unsigned int maxlen);
extern "C" int (__cdecl *_mbsnbcpy_s)(char* dest, unsigned int destSize, const char* src, unsigned int count);
extern "C" void __cdecl sub_404020(int code);

struct TeleportCallback {
    char pad0[0xa25];
    char m_name[0x801];
    char pad1[0x1a];
    int m_nameLen;
    int SetName(const char* name);
};

int TeleportCallback::SetName(const char* name)
{
    unsigned int len = strnlen(name, 0x801);
    if (len > 0x800)
        return 0;
    int err = _mbsnbcpy_s(m_name, 0x801, name, len);
    sub_404020(err);
    m_nameLen = (int)len;
    return 1;
}
