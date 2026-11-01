// from server: 100% by colin
struct ChatEnter {
    char pad[0x1b8];
    void* str;
    void SetError();
};

extern "C" void* (__thiscall *g_stringAssign)(void*, const char*);
extern char g_errorString[];

void ChatEnter::SetError() {
    g_stringAssign((char*)this + 0x1b8, g_errorString);
}
