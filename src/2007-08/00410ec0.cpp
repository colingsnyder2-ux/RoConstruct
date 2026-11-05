// from server: 2% by colin
struct PasteVerb {
    char pad0[0xc];
    void* field_c;
    char pad10[0x4];
    bool field_10;
    char pad15[0x173];
    void* field_188;
    void doIt(void* dataState);
};

extern "C" {
    void* __stdcall GlobalLock(void* hMem);
    int __stdcall GlobalUnlock(void* hMem);
    void* __stdcall OpenClipboard(void* hwnd);
    int __stdcall CloseClipboard();
    void* __stdcall GetClipboardData(unsigned int uFormat);
    unsigned int __stdcall RegisterClipboardFormatA(const char* lpString);
}

void PasteVerb::doIt(void* dataState) {
    void* hMem;
    void* pData;
    unsigned int fmt;
    void* clip;
    char buf[0x100];
    int flag;
    void* local;

    clip = OpenClipboard(0);
    if (!clip) return;

    fmt = RegisterClipboardFormatA("Roblox");
    hMem = GetClipboardData(fmt);
    if (!hMem) { CloseClipboard(); return; }

    pData = GlobalLock(hMem);
    if (!pData) { CloseClipboard(); return; }

    GlobalUnlock(hMem);
    CloseClipboard();
}
