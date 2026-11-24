// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: all type shapes below are guessed from the disassembly alone.
// The names Obj, Local, Callback and Self are invented for this file.

struct Obj {
    virtual ~Obj() {}                 // slot 0: scalar deleting dtor (push 1)
    virtual void unused1() {}         // slot 1
    virtual Obj* clone() { return 0; } // slot 2 (call [vtbl+8])
};

struct Local {
    int a;
    int b;
    Obj* c;
    ~Local() { if (c) delete c; }
};

struct Callback {
    // INFERRED: first dword of *arg4 is a thiscall function pointer,
    // invoked with ecx = self->first and one stack argument (&Local).
    void (__thiscall *fn)(void* thisPtr, Local* arg);
};

struct Self {
    void* first;
};

extern "C" void __fastcall fn_00587710(Self* self, int unusedEdx, int arg1, int arg2,
                                       Local** arg3, Callback* arg4)
{
    Local tmp;
    Local* src = *arg3;
    tmp.a = src->a;
    tmp.b = src->b;
    tmp.c = src->c ? src->c->clone() : 0;
    arg4->fn(self->first, &tmp);
}
