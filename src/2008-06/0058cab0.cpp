// from server: 100% by tester
struct StreamBuf {
    int sbumpc();
    int sgetc();
};

struct Verb {
    char pad[4];
    StreamBuf* stream;
    void skipWhitespace();
};

extern "C" int (__stdcall *sbumpc_ptr)();
extern "C" int (__stdcall *sgetc_ptr)();
extern char g_table[];

void Verb::skipWhitespace()
{
    int c = ((int (__thiscall*)(StreamBuf*))sbumpc_ptr)(stream);
    signed char idx = (signed char)c;
    if (g_table[idx] != 0) {
        do {
            ((int (__thiscall*)(StreamBuf*))sgetc_ptr)(stream);
            c = ((int (__thiscall*)(StreamBuf*))sbumpc_ptr)(stream);
            idx = (signed char)c;
        } while (g_table[idx] != 0);
    }
}
