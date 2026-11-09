// from server: 100% by colin
struct Scintilla_CScintillaFindReplaceDlg {
    char pad0[0x19c];
    unsigned int hwnd;
    unsigned int method1();
    unsigned int method2(unsigned int);
    unsigned int run();
};

extern "C" unsigned int (__stdcall *SendMessageA)(unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int Scintilla_CScintillaFindReplaceDlg::run() {
    unsigned int a = method1();
    unsigned int b = method2(0x412);
    unsigned int c = *(unsigned int*)((char*)this + 0x19c);
    unsigned int d = *(unsigned int*)((char*)b + 0x20);
    SendMessageA(d, 0xf1, c, 0);
    return a;
}
