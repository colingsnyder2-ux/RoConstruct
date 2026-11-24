// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so this file declares a minimal stand-in layout.
// The target is a compiler-generated adjustor thunk: it subtracts 16 from 'this' and jumps
// to ModelInstance's vector deleting destructor. That means ModelInstance has two
// polymorphic bases, and the second one sits at offset 16.

namespace RBX {

class PrimaryBase {
public:
    virtual ~PrimaryBase() {}
    int pad[3]; // INFERRED: pads the primary base so the second base lands at offset 16
};

class SecondaryBase {
public:
    virtual ~SecondaryBase() {}
};

class ModelInstance : public PrimaryBase, public SecondaryBase {
public:
    virtual ~ModelInstance();
};

// Defining the virtual destructor out of line makes the compiler emit the vtable and the
// vector deleting destructor. That includes the `adjustor{16}' thunk for the
// SecondaryBase subobject (sub ecx,0x10 ; jmp ??_EModelInstance@RBX@@UAEPAXI@Z).
ModelInstance::~ModelInstance() {}

} // namespace RBX
