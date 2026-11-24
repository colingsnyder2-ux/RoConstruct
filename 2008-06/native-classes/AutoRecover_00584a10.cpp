// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were provided. The target is a compiler-generated
// vtable adjustor thunk (this -= 20; jmp ModelInstance's vector deleting
// destructor). It is modelled with a two-base layout whose second polymorphic
// base sits at offset 20, so the compiler emits
// ??_EModelInstance@RBX@@WBE@AEPAXI@Z for the secondary base's virtual destructor.
namespace RBX {

// INFERRED: primary polymorphic base, 20 bytes (vptr + 16 bytes of data)
struct PrimaryBase {
    int pad[4];
    virtual ~PrimaryBase() {}
    virtual void primaryFn() {}
};

// INFERRED: secondary polymorphic base placed at offset 20
struct SecondaryBase {
    int data;
    virtual ~SecondaryBase() {}
    virtual void secondaryFn() {}
};

class ModelInstance : public PrimaryBase, public SecondaryBase {
public:
    ModelInstance();
    virtual ~ModelInstance();
    int extra;
};

// Defining the constructor and destructor forces the vtable and the
// adjustor{20} deleting-destructor thunk to be emitted.
ModelInstance::ModelInstance() : extra(0) {}
ModelInstance::~ModelInstance() {}

}
