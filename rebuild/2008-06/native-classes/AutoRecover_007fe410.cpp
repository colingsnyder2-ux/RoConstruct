// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace RBX {
class TextureId {};
namespace Reflection {

// INFERRED: minimal model of the descriptor base with a virtual destructor.
class Descriptor {
public:
    Descriptor() {}
    virtual ~Descriptor() {}
};

// INFERRED: intermediate property descriptor layer (fields up to +0x18)
class PropDescriptorBase : public Descriptor {
public:
    PropDescriptorBase() {}
    ~PropDescriptorBase() {}
    char pad[0x14];
};

template<class T, int N>
class BoundProp : public PropDescriptorBase {
public:
    BoundProp() : p(0) {}
    ~BoundProp()
    {
        if (p)
            ::operator delete(p);
    }
    void* p;   // +0x18
};

}

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

}
