// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct ScintillaFindReplaceDlg {
    char pad[0x19c];
    void* field_19c;
    void* method_71935c();
    void* method_7198fc(unsigned int);
    void* func();
};

void* ScintillaFindReplaceDlg::func()
{
    void* edi = method_71935c();
    void* eax = method_7198fc(0x412);
    SendMessageA(*(void**)((char*)eax + 0x20), 0xf1, (unsigned int)field_19c, 0);
    return edi;
}
