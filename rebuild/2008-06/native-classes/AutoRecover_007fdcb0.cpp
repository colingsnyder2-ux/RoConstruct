// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

namespace RBX {

// INFERRED: minimal stand-in for RBX::TextureId (only used as template argument here)
class TextureId {};

namespace Reflection {

// INFERRED: base descriptor class; its vtable (0x80b730) is restored at the end
// of the inlined destructor chain. Layout: vptr at +0, 0x18 bytes of state.
class PropertyDescriptor
{
public:
    PropertyDescriptor();                 // INFERRED: defined elsewhere
    virtual ~PropertyDescriptor() {}
    char pad[0x18];
};

// INFERRED: BoundProp owns a heap buffer at +0x1c which is freed on destruction.
template<class V, int replicate>
class BoundProp : public PropertyDescriptor
{
public:
    BoundProp();                          // INFERRED: defined elsewhere
    ~BoundProp()
    {
        if (owned)
            operator delete(owned);
    }
    void* owned;
};

} // namespace Reflection

class Sky
{
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

} // namespace RBX
