// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal stand-ins; real headers not available.
#include <new>

namespace RBX {
struct TextureId {};
namespace Reflection {
    struct DescriptorBase {
        virtual ~DescriptorBase() {}
        virtual void f1() {}
    };
    struct StringHolder : DescriptorBase {
        char pad[0x14];
        void* buffer; // INFERRED: offset 0x18
        StringHolder() : buffer(0) {}
        virtual ~StringHolder() {
            if (buffer)
                operator delete(buffer);
        }
    };
    template<class T, int N>
    struct BoundProp : StringHolder {
        BoundProp() {}
        virtual ~BoundProp() {}
    };
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
