// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee is a __thiscall member helper; the object is the pointer stored at this+4.
extern "C" int __fastcall fn_004777e0(void* self, int unusedEdx);

struct Func00676570Obj {
    int field0;
    void* inner; // INFERRED: member at +4 forwarded as 'this' to the callee
};

// INFERRED: the target is a __thiscall thunk (ecx = this) that tail-calls fn_004777e0 on this->inner.
extern "C" int __fastcall fn_00676570(Func00676570Obj* self, int unusedEdx)
{
    return fn_004777e0(self->inner, unusedEdx);
}
