// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class TextureId {};

namespace Reflection {

// INFERRED: polymorphic base descriptor; its destructor resets the vtable pointer at offset 0
class PropertyDescriptorBase {
public:
    virtual void describe() {}
    int pad[5];
    ~PropertyDescriptorBase() {}
};

// INFERRED: owns a heap pointer at offset 0x18, deleted in the destructor
template<class T, int N>
class BoundProp : public PropertyDescriptorBase {
public:
    void* owned;
    BoundProp() : owned(0) {}
    ~BoundProp() {
        if (owned)
            operator delete(owned);
    }
};

}

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

}
