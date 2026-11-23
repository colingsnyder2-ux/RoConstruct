// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Fn541090Self {
    int field0;
    int field4; // INFERRED: only member touched, cleared at +4
};

extern "C" void __fastcall fn_00541090(Fn541090Self* self, int unusedEdx)
{
    // INFERRED: the original has a never-taken `xor eax,eax; jne self` loop
    // (likely an assert/debug stub). Not reproduced here.
    self->field4 = 0;
}
