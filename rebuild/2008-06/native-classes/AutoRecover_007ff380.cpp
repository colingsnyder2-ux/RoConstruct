// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: minimal stand-ins for the RBX types so the real mangled symbol is produced.
namespace RBX {
    class TextureId {};
    namespace Reflection {
        struct PropBase {
            virtual ~PropBase() {}
        };
        // INFERRED: owning member destroyed after the BoundProp body, before the base vptr reset
        struct Owned {
            void* p;
            ~Owned() {
                if (p)
                    ::operator delete(p);
            }
        };
        template<class T, int N>
        class BoundProp : public PropBase {
        public:
            int pad[5];
            Owned owned;
        };
    }
    class Sky {
    public:
        static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
    };
    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
