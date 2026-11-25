// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace RBX {
    class TextureId {};

    namespace Reflection {
        // INFERRED: base descriptor with a virtual destructor, 0x18 bytes (vptr + 5 ints).
        class PropDescriptorBase {
        public:
            int pad[5];
            PropDescriptorBase() {}
            virtual ~PropDescriptorBase() throw() {}
        };

        // INFERRED: owning buffer member (string/vector-like) at offset 0x18.
        struct OwnedBuffer {
            void* p;
            OwnedBuffer() : p(0) {}
            ~OwnedBuffer() throw() { if (p) ::operator delete(p); }
        };

        template<class T, int N>
        class BoundProp : public PropDescriptorBase {
        public:
            OwnedBuffer owned;
            BoundProp() {}
        };
    }

    class Sky {
    public:
        static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
    };

    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
