// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: headers not shown; minimal local layout. Member at +0x1c is a heap pointer freed in the dtor, then the base vtable is restored.
namespace RBX {
class TextureId {};
namespace Reflection {
class PropDescriptorBase {
public:
    int pad[6]; // INFERRED: fills offsets 4..0x1b
    virtual ~PropDescriptorBase() {}
    virtual void anchor();
};
void PropDescriptorBase::anchor() {}
template <class T, int N>
class BoundProp : public PropDescriptorBase {
public:
    char* owned; // INFERRED: offset 0x1c, freed in dtor
    ~BoundProp() { delete owned; }
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
