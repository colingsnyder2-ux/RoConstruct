// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void __fastcall fn_005446b0(void* self);
extern "C" int __fastcall fn_004023f0(void* self, int unusedEdx, int a1);
extern "C" void (__stdcall *__imp__invalid_parameter_noinfo)(void);

// INFERRED: checked-iterator ctor (_SECURE_SCL): range [begin+0xc, +0x10] validates position
struct CheckedIter {
    int field0;
    unsigned pos;
    int pad8;
    unsigned lo;
    unsigned hi;
};

struct CheckedIterOwner {
    int field0;
    unsigned pos;
};

extern "C" void* __fastcall fn_005444a0(CheckedIterOwner* self, int unusedEdx, unsigned pos, CheckedIter* cont)
{
    fn_005446b0(self);
    if (!cont || cont->lo > pos || pos > cont->hi)
        __imp__invalid_parameter_noinfo();
    while (0) {}
    fn_004023f0(self, 0, (int)cont);
    self->pos = pos;
    return self;
}
