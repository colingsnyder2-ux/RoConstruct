// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: thiscall thunk; loads the member at +4 into ecx and tail-calls 0x00478450.
// INFERRED: the callee takes no stack arguments and the return type is int.
extern "C" int __fastcall fn_00478450(void* self, int unusedEdx);

struct Fn006764a0Obj {
    void* unknown0;
    void* inner; // +4
};

extern "C" int __fastcall fn_006764a0(Fn006764a0Obj* self, int unusedEdx)
{
    return fn_00478450(self->inner, unusedEdx);
}
