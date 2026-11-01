// from server: 100% by colin
struct CScintillaFindReplaceDlg {
    char pad[0x19c];
    int field_19c;
    void InitDialog();
};

extern "C" void* __stdcall sub_6a1418(int);
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

void CScintillaFindReplaceDlg::InitDialog()
{
    void* p = sub_6a1418(0x412);
    int h = *(int*)((char*)p + 0x20);
    long r = SendMessageA((void*)h, 0xf0, 0, 0);
    field_19c = (r != 1) ? 0 : 1;
}
