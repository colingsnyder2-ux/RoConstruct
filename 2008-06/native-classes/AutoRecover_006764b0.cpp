// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object layout is unknown; only the pointer at offset 4 is used.
struct Fn006764b0Inner;

struct Fn006764b0Obj {
    int field0;                 // INFERRED: unknown leading member
    Fn006764b0Inner* inner;     // [this + 4]
};

// INFERRED: the callee is a __thiscall member helper, so it is declared __fastcall with a dummy edx.
// The return type is also a guess.
extern "C" int __fastcall fn_00478cd0(Fn006764b0Inner* self, int unusedEdx);

// INFERRED: the target is really __thiscall (it uses ecx as this) and tail-calls fn_00478cd0 with this->inner.
extern "C" int __fastcall fn_006764b0(Fn006764b0Obj* self, int unusedEdx)
{
    return fn_00478cd0(self->inner, unusedEdx);
}
