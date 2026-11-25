// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the two 12-byte by-value arguments are accessor descriptors
// (member-function-pointer-like: code ptr, this-adjust, 0).
struct FnDesc {
    int fn;
    int adj;
    int extra;
};

// INFERRED: unknown accessor functions referenced by the descriptors.
extern "C" void fn_005dc540(void);
extern "C" void fn_005d8d10(void);

extern "C" int __fastcall fn_005da4e0(void* self, int unusedEdx,
                                      const char* name, const char* category,
                                      FnDesc a, FnDesc b, int flag);

namespace RBX {

// INFERRED: property descriptor object; its constructor forwards to fn_005da4e0.
// The non-trivial destructor makes the compiler register an atexit stub.
struct PropDescriptor {
    char data[1];

    PropDescriptor(const char* name, const char* category)
    {
        FnDesc a = { (int)&fn_005d8d10, (int)0xfffffeb4, 0 };
        FnDesc b = { (int)&fn_005dc540, (int)0xfffffeb4, 0 };
        fn_005da4e0(this, 0, name, category, a, b, 1);
    }
    ~PropDescriptor() {}
};

static PropDescriptor propRightLeg("RightLeg", "Data");

}
