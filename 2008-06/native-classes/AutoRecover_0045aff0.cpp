// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: CWnd::Default is protected, and the flag at +0xa8 is a byte member of the
// CWnd-derived class. The class is unknown, so the target is a fixed-name extern "C" helper.
extern "C" long __fastcall fn_006a0c68(void* self);

struct Fn0045aff0Self {
    char pad[0xa8];
    unsigned char flag; // INFERRED: byte tested at +0xa8
};

extern "C" int __fastcall fn_0045aff0(Fn0045aff0Self* self, int unusedEdx, int arg1)
{
    if (self->flag != 0) {
        return fn_006a0c68(self);
    }
    return 1;
}
