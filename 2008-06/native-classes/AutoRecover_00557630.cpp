// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Virtual method signatures and return type are unknown.
struct Local_00557630 {
    virtual void first();
    virtual void second();
};

extern "C" void __fastcall fn_00557630(Local_00557630* self, int unusedEdx)
{
    self->second();
}
