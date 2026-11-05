// from server: 100% by tester
struct RakPeer {
    char pad0[0x438];
    char buf[0x100];
    unsigned char flag228;
    void SetBuffer(const char* data, int len);
};

extern "C" void __cdecl memcpy_impl(void* dst, const void* src, unsigned int len);

void RakPeer::SetBuffer(const char* data, int len) {
    if (len > 0xff) {
        len = 0xff;
    }
    if (data == 0) {
        flag228 = 0;
        return;
    }
    if (len > 0) {
        memcpy_impl(buf, data, len);
    }
    flag228 = (unsigned char)len;
}
