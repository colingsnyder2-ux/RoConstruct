// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: minimal stand-ins reproducing the mangled names and layout of
// RBX::Sky::prop_SkyRt (BoundProp<TextureId,1>). The class layout is inferred
// from the disassembly: vptr at +0, a heap pointer at +0x18 that is deleted,
// then the vptr is reset to the base vtable.

namespace RBX {

class TextureId
{
};

namespace Reflection {

// INFERRED: base descriptor class; its inline destructor only resets the vptr.
class PropertyDescriptor
{
public:
    PropertyDescriptor() {}
    virtual ~PropertyDescriptor() {}
    char pad[0x14];
};

// INFERRED: member at +0x18 whose destructor frees a heap buffer.
struct HeapHolder
{
    void* p;
    HeapHolder() : p(0) {}
    ~HeapHolder()
    {
        if (p)
            ::operator delete(p);
    }
};

template<class T, int N>
class BoundProp : public PropertyDescriptor
{
public:
    HeapHolder holder; // +0x18
    BoundProp() {}
    virtual ~BoundProp() {}
};

} // namespace Reflection

class Sky
{
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

} // namespace RBX
