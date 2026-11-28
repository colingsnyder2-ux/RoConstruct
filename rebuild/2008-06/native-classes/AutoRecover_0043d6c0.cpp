// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: file-local layout; offsets taken from the disassembly (multiple-inheritance vptrs at 0, 0x20, 0x10c).
struct Local_0043d6c0 {
    char pad[0x130];
    int field130;
    int field134;
    int field138;
};

extern "C" void __fastcall fn_0043c020(Local_0043d6c0* self, int unusedEdx, int a, int b);

extern "C" Local_0043d6c0* __fastcall fn_0043d6c0(Local_0043d6c0* self, int unusedEdx, int a, int b) {
    // edx passed through untouched: the original callee is plain __thiscall, so no edx setup is emitted.
    fn_0043c020(self, unusedEdx, a, b);
    self->field138 = 0;
    self->field134 = 0;
    self->field130 = 0;
    *(int*)self = 0x81497c;
    *(int*)((char*)self + 0x20) = 0x81491c;
    *(int*)((char*)self + 0x10c) = 0x814914;
    return self;
}
