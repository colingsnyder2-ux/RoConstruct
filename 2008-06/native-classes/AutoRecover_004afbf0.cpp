// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no header for RBX::JointsService exists. The target is the compiler-generated
// adjustor{16} thunk for the vector deleting destructor (sub ecx,16 ; jmp primary deleting dtor).
// INFERRED: the real class hierarchy is unknown; only the 16-byte offset of the second
// polymorphic base is taken from the thunk.

namespace RBX {

struct JointsServicePrimaryBase {
    virtual ~JointsServicePrimaryBase() {}
    int pad[3]; // INFERRED: fills the first 16 bytes (vptr + 12 bytes)
};

struct JointsServiceSecondaryBase {
    virtual ~JointsServiceSecondaryBase() {}
};

class JointsService : public JointsServicePrimaryBase, public JointsServiceSecondaryBase {
public:
    JointsService();
    virtual ~JointsService();
};

// Defining the constructor forces emission of the vtable, and with it the
// `vector deleting destructor'`adjustor{16}' thunk for the secondary base.
JointsService::JointsService() {}

JointsService::~JointsService() {}

} // namespace RBX
