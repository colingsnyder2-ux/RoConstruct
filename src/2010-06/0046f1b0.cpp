// from server: 89% by atomic.potato
struct Scintilla_CScintillaFindReplaceDlg {
    char pad[0x19c];
    unsigned int field_19c;
    unsigned int method_0046f1b0();
};

extern "C" unsigned int __stdcall sub_007a82c4();
extern "C" unsigned int __stdcall sub_007a886a(unsigned int);
extern "C" unsigned int __stdcall SendMessageA(unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int Scintilla_CScintillaFindReplaceDlg::method_0046f1b0()
{
    unsigned int v = sub_007a82c4();
    unsigned int w = sub_007a886a(0x412);
    SendMessageA(*(unsigned int*)(w + 0x20), 0xf1, this->field_19c, 0);
    return v;
}
