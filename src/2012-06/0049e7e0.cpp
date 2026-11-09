// from server: 90% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CScintillaFindReplaceDlg
{
    char pad[0x19c];
    void* field_19c;
    void* method_982a02();
    void* method_982ff0(unsigned int);
    void* func_0049e7e0();
};

void* CScintillaFindReplaceDlg::func_0049e7e0()
{
    void* edi = method_982a02();
    void* eax = method_982ff0(0x412);
    SendMessageA(field_19c, 0xf1, *(unsigned int*)((char*)eax + 0x20), 0);
    return edi;
}
