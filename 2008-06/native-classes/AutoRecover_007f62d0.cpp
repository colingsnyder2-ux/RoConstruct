// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 12-byte pointer-to-member representation (fn, this-adjust, vbtable index)
// passed by value for the getter and the setter.
struct MemFnRep {
    void* fn;
    int adj;
    int vbIndex;
};

// INFERRED: accessor code addresses in the original exe (never called here, only referenced).
extern "C" void fn_005d8b10(void);
extern "C" void fn_005dc600(void);

extern "C" int __fastcall fn_005da4e0(void* self, int unusedEdx, const char* name, const char* category,
                                      MemFnRep getter, MemFnRep setter, int flag);

namespace RBX {

// INFERRED: property descriptor object constructed in place; layout unknown.
struct PropTorsoDesc {
    char storage[64];
    __forceinline PropTorsoDesc() {
        MemFnRep getter = { (void*)&fn_005d8b10, (int)0xfffffeb4, 0 };
        MemFnRep setter = { (void*)&fn_005dc600, (int)0xfffffeb4, 0 };
        fn_005da4e0(this, (int)0xfffffeb4, "Torso", "Data", getter, setter, 1);
    }
    ~PropTorsoDesc() {}
};

PropTorsoDesc propTorso;

} // namespace RBX
