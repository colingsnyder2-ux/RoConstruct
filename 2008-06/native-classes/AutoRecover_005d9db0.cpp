// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: source/target RTTI types are unknown; polymorphic stand-ins are used
// so the compiler emits a ___RTDynamicCast(obj, 0, src, dst, 0) call.
struct FnBase005d9db0 {
    virtual ~FnBase005d9db0();
};

struct FnDerived005d9db0 : public FnBase005d9db0 {
};

// INFERRED: owner object with a polymorphic pointer at +0x104
struct FnSelf005d9db0 {
    char pad[0x104];
    FnBase005d9db0* obj;
};

extern "C" int __fastcall fn_005d8540(void* self, int unusedEdx, int a1, int a2);
extern "C" void fn_005d9d10();

extern "C" void __fastcall fn_005d9db0(FnSelf005d9db0* self, int unusedEdx, int arg)
{
    if (self) {
        FnDerived005d9db0* d = dynamic_cast<FnDerived005d9db0*>(self->obj);
        if (d) {
            // INFERRED: edx holds arg at the call in the original; pass it as the dummy.
            int fp = (int)(void*)&fn_005d9d10;
            fn_005d8540(d, arg, fp, arg);
        }
    }
}
