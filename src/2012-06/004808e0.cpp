// from server: 17% by tester
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct XVRecordToggleVerb {
    void action();
};

extern "C" bool func_00880f30();

void XVRecordToggleVerb::action() {
    DWORD result = func_00880f30();
    if (result == 0) {
        DWORD* ptr = reinterpret_cast<DWORD*>(this);
        ptr[2] = 0xd6e8b4;
    } else {
        DWORD* ptr = reinterpret_cast<DWORD*>(this);
        ptr[2] = 0;
    }
}
