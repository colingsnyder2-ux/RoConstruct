// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout modeled from the mangled name and the disassembly; no headers available.
#include <new>

namespace RBX {
class TextureId {};
namespace Reflection {
// INFERRED: base descriptor; its vtable is the one at 0x80b730.
// The empty virtual destructor only restores the vtable pointer.
struct DescBase {
    virtual ~DescBase() {}
    int pad[5];
};
// INFERRED: 'owned' is the buffer at offset 0x18 (0x9748c8 - 0x9748b0).
template <class T, int N>
struct BoundProp : DescBase {
    void* owned;
    virtual ~BoundProp()
    {
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
