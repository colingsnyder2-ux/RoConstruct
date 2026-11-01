// from server: 100% by colin
extern "C" int (__stdcall *MessageBeep)(unsigned int uType);

struct CScintillaView {
    char pad[0xd8];
    int field_d8;
    void Notify(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
};

void CScintillaView::Notify(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    field_d8 = 1;
    MessageBeep(0x10);
}
