// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the two 12-byte by-value arguments are virtual-inheritance style
// member-function-pointer triples {code address, adjustment, index}.
struct RbxMemberPtr
{
    void* fn;
    int adj;
    int idx;
};

// INFERRED: getter / setter thunks referenced by address only.
extern "C" void fn_005dc480();
extern "C" void fn_005d8c10();

// INFERRED: the callee takes (name, category, setter, getter, flag) after 'this'.
extern "C" int __fastcall fn_005da4e0(void* self, int unusedEdx,
                                      const char* name, const char* category,
                                      RbxMemberPtr setter, RbxMemberPtr getter,
                                      int flag);

namespace RBX {

// INFERRED: the property descriptor type is unknown; this stand-in has a non-trivial
// destructor so the compiler emits the atexit registration.
struct PropLeftLegType
{
    char storage[0x40]; // INFERRED: size unknown
    PropLeftLegType()
    {
        RbxMemberPtr getter = { (void*)&fn_005dc480, -332, 0 };
        RbxMemberPtr setter = { (void*)&fn_005d8c10, -332, 0 };
        fn_005da4e0(this, 0, "LeftLeg", "Data", setter, getter, 1);
    }
    ~PropLeftLegType(); // INFERRED: defined elsewhere (0x7ff2e0 stub calls it)
};

PropLeftLegType propLeftLeg;

}
