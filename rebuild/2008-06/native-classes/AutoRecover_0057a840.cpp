// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjustor thunk: "sub ecx,0x150; jmp 0x568d40".
// The receiver is a secondary-base subobject, so the real object pointer is
// this - 0x150. The callee is unnamed, so it is declared __fastcall
// (ecx = this, edx dummy).
// INFERRED: the target must be defined __cdecl to match the required ABI, so
// the receiver is taken as a plain parameter. This cannot reproduce the
// register-only thunk exactly, because plain C++ cannot read ecx.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void fn_0057a840(void* self)
{
    fn_00568d40(reinterpret_cast<char*>(self) - 0x150, 0);
}
