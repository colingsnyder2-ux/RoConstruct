// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unnamed class; callee takes 3 stack args per the convention note,
// but the target pushes only one (field at +0x18), so the others are unused here.
struct Fn54cec0Obj {
    char pad[0x18];
    int field18;
};

extern "C" char *fn_00541da0(char* self);

extern "C" int __fastcall fn_0054cec0(Fn54cec0Obj* self, int unusedEdx)
{
    // INFERRED: the callee is a plain cdecl-style call with one pushed arg and
    // caller-cleanup (add esp, 4), so it is declared separately here.
    return ((int (__cdecl*)(int))fn_00541da0)(self->field18);
}
