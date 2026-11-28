// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local BoundProp layout. Binary shows the dtor deleting a pointer at +0x18, then resetting the vptr to the base vtable.
namespace RBX {
namespace Reflection {
struct PropDescriptorBase {
    virtual ~PropDescriptorBase() {}
    int pad[5];  // INFERRED: fills +0x04..+0x17
};
template<typename T, int N>
struct BoundProp : PropDescriptorBase {
    void* owned;  // INFERRED: +0x18, deleted in dtor
    virtual ~BoundProp() { if (owned) operator delete(owned); }
};
}
struct Rocket {
    static Reflection::BoundProp<float, 1> prop_TurnP;
};
Reflection::BoundProp<float, 1> Rocket::prop_TurnP;
}
