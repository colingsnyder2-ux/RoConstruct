// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header is available. The target is a compiler-generated
// `vector deleting destructor'`adjustor{20}' thunk (sub ecx,0x14 ; jmp primary).
// C++ source cannot define it directly. Instead the class layout is modelled so
// that MSVC emits it: JointsService has a 20-byte primary base (vptr + 16 bytes)
// and a polymorphic secondary base at offset 0x14 with a virtual destructor.
// The thunk is emitted along with the vtable, and the constructor below forces
// the vtable to be emitted.

namespace RBX {

// INFERRED: primary base, 20 bytes (vptr + 4 ints)
struct JointsServicePrimaryBase {
    int pad[4];
    virtual ~JointsServicePrimaryBase() {}
};

// INFERRED: secondary base located at offset 20 with a virtual destructor
struct JointsServiceSecondaryBase {
    virtual ~JointsServiceSecondaryBase() {}
};

class JointsService : public JointsServicePrimaryBase, public JointsServiceSecondaryBase {
public:
    JointsService();
    virtual ~JointsService();
    int field;
};

JointsService::JointsService()
    : field(0)
{
}

JointsService::~JointsService()
{
}

} // namespace RBX
