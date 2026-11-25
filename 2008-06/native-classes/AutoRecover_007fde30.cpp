// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local stand-ins for the real headers; the compiler generates the
// dynamic atexit destructor for the static below.

namespace RBX {
    class TextureId {};
    namespace Reflection {
        // INFERRED: base descriptor with a vtable (its pointer is reset in the destructor)
        class PropDescriptorBase {
        public:
            PropDescriptorBase() {}
            virtual __forceinline ~PropDescriptorBase() {}
            int pad[5];
        };

        // INFERRED: owned heap buffer at offset 0x18
        struct OwnedBuffer {
            char* p;
            OwnedBuffer() : p(0) {}
            __forceinline ~OwnedBuffer() { if (p) delete p; }
        };

        template<class T, int B>
        class BoundProp : public PropDescriptorBase {
        public:
            OwnedBuffer heapData;
            BoundProp() {}
            virtual __forceinline ~BoundProp() {}
        };
    }
    class Sky {
    public:
        static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
    };
    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
