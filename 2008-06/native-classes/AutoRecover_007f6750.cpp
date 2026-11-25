// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the two 12-byte by-value arguments are member-function-pointer-like
// descriptors (code pointer, adjustor, 0). Their real types are unknown.
struct FnDesc {
    void* fn;
    int   adj;
    int   zero;
};

extern "C" int __fastcall fn_005da980(void* self, int unusedEdx,
                                      const char* name, const char* category,
                                      FnDesc a, FnDesc b, int flags);

// INFERRED: the code addresses stored in the descriptors (unknown accessor thunks)
extern "C" void fn_005dbf10(void);
extern "C" void fn_005d74c0(void);

namespace RBX {

// INFERRED: property descriptor type; its constructor is the callee fn_005da980.
// The compiler-generated `dynamic initializer for 'propMaxHealth'' is the target.
struct PropMaxHealthT {
    char storage[64];
    PropMaxHealthT()
    {
        FnDesc getter = { (void*)&fn_005dbf10, (int)0xfffffeb4, 0 };
        FnDesc setter = { (void*)&fn_005d74c0, (int)0xfffffeb4, 0 };
        fn_005da980(this, 0, "MaxHealth", "Game", setter, getter, 5);
    }
    // INFERRED: non-trivial destructor defined elsewhere; the compiler-generated
    // atexit stub (0x7ff360) calls it.
    ~PropMaxHealthT();
};

PropMaxHealthT propMaxHealth;

}
