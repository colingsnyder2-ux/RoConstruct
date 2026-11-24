// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_00541ca0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00541240(void* self, int unusedEdx);

// INFERRED: models the base-class destructor call (unwind state 0 around the body).
struct BaseDtorGuard {
    void* p;
    explicit BaseDtorGuard(void* s) : p(s) {}
    ~BaseDtorGuard() { fn_00541240(p, 0); }
};

extern "C" void __fastcall fn_00540950(void* self, int unusedEdx)
{
    BaseDtorGuard guard(self);
    fn_00541ca0(self, 0);
}
