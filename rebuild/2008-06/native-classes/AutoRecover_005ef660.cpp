// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The target is a compiler-generated adjustor thunk: it subtracts 0x14 from
// `this` and jumps to FaceInstance's vector deleting destructor. No class headers were
// provided, so the thunk cannot be written directly. Instead this file declares a
// minimal layout in which FaceInstance has a primary base followed by a secondary
// polymorphic base at offset 20. With that layout MSVC emits
// `??_EFaceInstance@RBX@@WBE@AEPAXI@Z` itself.
// The bases, field sizes and names are guesses.

namespace RBX {

struct PrimaryBase {           // INFERRED: vptr + 16 bytes of data = 20 bytes
    int pad[4];
    virtual ~PrimaryBase() {}
};

struct SecondaryBase {         // INFERRED: sits at offset 20 in FaceInstance
    virtual ~SecondaryBase() {}
};

class FaceInstance : public PrimaryBase, public SecondaryBase {
public:
    FaceInstance();
    virtual ~FaceInstance() {}
};

// Out-of-line constructor: forces the vtable to be emitted, and with it the
// adjustor{20} deleting-destructor thunk.
FaceInstance::FaceInstance() {}

} // namespace RBX
