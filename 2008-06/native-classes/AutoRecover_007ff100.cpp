// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: BoundProp<BrickColor,1> modelled minimally; member at +0x18 is a heap pointer, vtable at +0.
struct PropBase {
    virtual ~PropBase() {}
};

struct HeapHolder {
    char* p;
    ~HeapHolder() throw() {
        if (p)
            ::operator delete(p);
    }
};

struct BoundPropModel : PropBase {
    int pad[5];
    HeapHolder heapMember;
    virtual ~BoundPropModel() throw() {}
};

extern BoundPropModel g_prop_RightArmColor;

extern "C" void __cdecl fn_007ff100(void)
{
    g_prop_RightArmColor.~BoundPropModel();
}
