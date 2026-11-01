// from server: 100% by colin
struct Scintilla_CScintillaFindReplaceDlg {
    char m_pad[0x19c];
    int m_field19c;
    void func_0045de70();
};

extern "C" void * __stdcall sub_0063096A(int);
extern "C" long (__stdcall *SendMessageA)(void *, unsigned int, unsigned int, long);

void Scintilla_CScintillaFindReplaceDlg::func_0045de70()
{
    void *p = sub_0063096A(0x412);
    int v = (int)SendMessageA(*(void **)((char *)p + 0x20), 0xf0, 0, 0);
    this->m_field19c = (v - 1 == 0) ? 1 : 0;
}
