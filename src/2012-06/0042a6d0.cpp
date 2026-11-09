// from server: 62% by 41k
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned char BYTE;
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct CSelectionTreeCtrl {
    void someFunction(DWORD param);
};

void CSelectionTreeCtrl::someFunction(DWORD param) {
    if (param != 0xe2a45c) {
        return;
    }
    DWORD thisPtr = (DWORD)this;
    DWORD field30 = *(DWORD*)((DWORD)thisPtr + 0x30);
    BYTE* field2c = (BYTE*)((DWORD)thisPtr + 0x2c);
    *field2c |= 1;
    DWORD vTable = *(DWORD*)field30;
    DWORD funcAddress = *(DWORD*)(vTable + 0x15c);
    ((void(__stdcall*)(DWORD))funcAddress)(param);
}
