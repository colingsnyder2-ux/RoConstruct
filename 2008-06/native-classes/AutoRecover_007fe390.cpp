// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

namespace RBX {
    class TextureId {};
    namespace Reflection {
        // INFERRED: base descriptor with a vtable and padding up to offset 0x18.
        class PropDescriptor {
        public:
            int pad[5];
            virtual ~PropDescriptor() {}
        };
        // INFERRED: derived vtable store absent in original destructor.
        template<class T, int B>
        class __declspec(novtable) BoundProp : public PropDescriptor {
        public:
            // INFERRED: heap pointer owned by the property object.
            void* owned;
            BoundProp() : owned(0) {}
            ~BoundProp() { if (owned) operator delete(owned); }
        };
    }
    class Sky {
    public:
        static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
    };
    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
