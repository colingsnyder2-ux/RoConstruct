// from server: 100% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
typedef unsigned char BYTE;
struct RBX_FunctionMarshaller {
    void func_00424e70();
};

void RBX_FunctionMarshaller::func_00424e70() {
    if (*(DWORD*)this) {
        *(BYTE*)(*(DWORD*)this) = *(BYTE*)(this + 4);
    }
}
