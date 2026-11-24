// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor thunk: it subtracts 16 from `this`
// and jumps to the primary vector deleting destructor at 0x005837e0. It cannot be written
// directly, so this file arranges for the compiler to emit it.
// INFERRED: no native headers were found, so minimal local stand-in declarations are used.
// INFERRED: layout is a 16-byte polymorphic primary base (vptr + 12 bytes), followed by a
// second polymorphic base at offset 16 that has a virtual destructor.
// INFERRED: MSVC only puts the vector deleting destructor (??_E) in the vftable, instead of
// the scalar one (??_G), when delete[] is applied to the class type. A helper that does
// delete[] forces this, so the ??_E adjustor{16} thunk gets emitted.

namespace RBX {

    char* sModel; // INFERRED: non-const char* variable used as the template argument

    class Instance {
    public:
        Instance() {}
        virtual ~Instance() {}
        int instancePad[3];
    };

    class PVInstance : public Instance {
    public:
        PVInstance() {}
    };

    class ModelInstance : public PVInstance {
    public:
        ModelInstance() {}
    };

    class DtorBase {
    public:
        DtorBase() {}
        virtual ~DtorBase() {}
    };

    template<class T, class Base, char*& name>
    class FactoryProduct : public T, public DtorBase {
    public:
        FactoryProduct() {}
        // INFERRED: helper that forces vector deleting destructor generation
        static void destroyArray(FactoryProduct* p) { delete[] p; }
    protected:
        virtual ~FactoryProduct() {}
    };

    template class FactoryProduct<ModelInstance, PVInstance, sModel>;
}
