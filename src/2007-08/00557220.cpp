// from server: 100% by colin
struct ChatEnter {
    char pad[0x1b8];
    void SetProgress();
};

extern "C" void* (__thiscall *g_stringAssign)(void*, const char*);
extern char g_progressString[];

void ChatEnter::SetProgress() {
    g_stringAssign((char*)this + 0x1b8, g_progressString);
}
