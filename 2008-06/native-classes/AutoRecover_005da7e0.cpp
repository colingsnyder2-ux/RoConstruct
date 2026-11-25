// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was available, so most types here are raw ints/pointers and the argument roles are guesses.
// INFERRED: this reconstructs a PropDescriptor<FlagStand,BrickColor> constructor from the disassembly's call order only.
// NOTE: not verified against the original bytes. The EH frame and the argument layout are inferred.
extern "C" char g_0083d654[];   // INFERRED: vtable for PropDescriptor<FlagStand,BrickColor>

// INFERRED: auto_ptr-like owner. Its destructor is what forces the SEH frame.
struct Local_005da7e0_Owner {
    int* p;
    ~Local_005da7e0_Owner() {
        if (p) operator delete(p);
    }
};

struct Local_005da7e0 {
    void* vtbl;
};

extern "C" int* __fastcall fn_005d8230(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int fn_005c0860(int a, int b);
extern "C" int __fastcall fn_00445610(void* self, int unusedEdx, int desc, int ownedPtr);

extern "C" Local_005da7e0* __fastcall fn_005da7e0(Local_005da7e0* self, int unusedEdx,
    int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
    Local_005da7e0_Owner arg9)
{
    // INFERRED: arg9 is an owner passed by value (destroyed by this function on exit).
    int* r = fn_005d8230((void*)arg6, 0, (int)&arg9, arg3, arg4, arg5, arg6, arg7, arg8);
    Local_005da7e0_Owner tmp;
    tmp.p = (int*)*r;
    *r = 0;
    int desc = fn_005c0860(arg1, arg2);
    int owned = (int)tmp.p;
    tmp.p = 0;
    fn_00445610(self, 0, desc, owned);
    self->vtbl = g_0083d654;
    return self;
}
