// from server: 93% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct ScintillaFindReplaceDlg
{
    char pad[0x19c];
    void* field_19c;

    void* func_0048baf0();
};

extern "C" void* __stdcall sub_0080a982();
extern "C" void* __stdcall sub_0080af5e(void*, unsigned int);

void* ScintillaFindReplaceDlg::func_0048baf0()
{
    void* edi = sub_0080a982();
    void* eax = sub_0080af5e(this, 0x412);
    SendMessageA(*(void**)((char*)eax + 0x20), 0xf1, (unsigned int)field_19c, 0);
    return edi;
}
