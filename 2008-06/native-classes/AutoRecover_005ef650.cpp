// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided. The target is a compiler-generated
// adjustor thunk (sub ecx,16 ; jmp FaceInstance::`vector deleting destructor').
// It cannot be written by hand. This file reproduces the class layout that makes
// MSVC emit it: FaceInstance has a primary base and a second polymorphic base at
// offset 16. The thunk is generated for the second base's virtual destructor slot.
// The out-of-line constructor and destructor force the vtable and the
// adjustor{16} thunk to be emitted.

namespace RBX {

// INFERRED: primary base, 16 bytes (vptr + 12 bytes of data)
class InstancePrimaryBase {
public:
    int pad[3];
    InstancePrimaryBase() {}
    virtual ~InstancePrimaryBase() {}
};

// INFERRED: second base located at offset 16 with a virtual destructor
class InstanceSecondaryBase {
public:
    InstanceSecondaryBase() {}
    virtual ~InstanceSecondaryBase() {}
};

class FaceInstance : public InstancePrimaryBase, public InstanceSecondaryBase {
public:
    int face;
    FaceInstance();
    virtual ~FaceInstance();
};

FaceInstance::FaceInstance()
    : face(0)
{
}

FaceInstance::~FaceInstance()
{
}

} // namespace RBX
