// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct ScintillaFindReplaceDlg
{
    char pad[0x19c];
    void* field_19c;

    void* func_0046b6b0();
    void* sub_7f4184();
    void* sub_7f4730(unsigned int);
};

void* ScintillaFindReplaceDlg::func_0046b6b0()
{
    void* edi = sub_7f4184();
    void* eax = sub_7f4730(0x412);
    SendMessageA(*(void**)((char*)eax + 0x20), 0xf1, (unsigned int)field_19c, 0);
    return edi;
}
