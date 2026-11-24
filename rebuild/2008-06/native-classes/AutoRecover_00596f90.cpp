// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object being built is a small polymorphic holder (vtable at +0, pointer at +8).
// INFERRED: arg3 onward is a boost signals slot passed by value on the stack; its destructor is
// called on &arg3 at the end. Exact argument types are unknown, so every argument is a dword.

struct FnObject {
    void* vtable;   // +0
    int   pad4;     // +4
    void* payload;  // +8
};

// INFERRED: vtable of the bound-call object stored into the holder on success.
extern "C" char g_00832350[];

extern "C" int  fn_006a0920(int size);   // INFERRED: operator new, only one argument is actually pushed
extern "C" char fn_0060a2f0(int* str);   // StringConverter<CoordinateFrame>::convertToValue
extern "C" void __fastcall fn_00595f90(void* self, int unusedEdx, void* args); // bind storage2 ctor
extern "C" void __fastcall fn_0049f710(void* self, int unusedEdx);             // slot dtor

extern "C" FnObject* __fastcall fn_00596f90(FnObject* self, int unusedEdx,
    int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
    int arg8, int arg9, int arg10, int arg11, int arg12, int arg13)
{
    self->vtable = 0;
    if (!fn_0060a2f0(&arg1)) {
        int* p = (int*)fn_006a0920(0x30);
        if (p) {
            p[0] = arg1;
            fn_00595f90(p + 2, 0, &arg3);
        }
        self->payload = p;
        self->vtable = (void*)g_00832350;
    } else {
        self->vtable = 0;
    }
    fn_0049f710(&arg3, 0);
    return self;
}
