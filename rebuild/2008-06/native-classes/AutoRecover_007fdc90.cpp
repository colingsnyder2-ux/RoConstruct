// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace RBX {
class TextureId {};

namespace Reflection {
// INFERRED: minimal layout; real header unavailable.
class PropDescriptorBase {
public:
    virtual ~PropDescriptorBase() {}
    char pad[0x18 - sizeof(void*)];
};

// INFERRED: member at offset 0x18 owns a heap pointer, freed in its destructor without nulling.
struct OwnedPtr {
    void* p;
    OwnedPtr() : p(0) {}
    ~OwnedPtr() {
        if (p)
            operator delete(p);
    }
};

template<class T, int N>
class BoundProp : public PropDescriptorBase {
public:
    OwnedPtr owned;
};
}

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
