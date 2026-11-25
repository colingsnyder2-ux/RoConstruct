// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <cstddef>

namespace RBX {

class TextureId {};

namespace Reflection {

// INFERRED: base descriptor class; its inline virtual dtor resets the vptr to the base vtable
class PropertyDescriptor {
public:
    PropertyDescriptor() {}
    virtual ~PropertyDescriptor() {}
    int pad[5];
};

// INFERRED: BoundProp<TextureId,1> owns a buffer pointer at offset 0x18
template<class T, int N>
class BoundProp : public PropertyDescriptor {
public:
    void* owned;
    BoundProp() : owned(0) {}
    virtual ~BoundProp()
    {
        if (owned)
            ::operator delete(owned);
    }
};

} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

} // namespace RBX
