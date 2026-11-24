// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so this is a minimal local reconstruction of the class layout.
// The adjustor{16} thunk (sub ecx,0x10 ; jmp real vector-deleting-dtor) is emitted by the compiler
// for the secondary-base vtable at offset 16 when the template's vftable is emitted.

namespace RBX {

extern const char* const sTeam;

class Team;

// INFERRED: primary base occupying 16 bytes (vptr + 12 bytes of data); dtor defined elsewhere
struct InstancePrimaryBase {
    virtual ~InstancePrimaryBase();
    int pad[3];
};

// INFERRED: secondary polymorphic base placed at offset 16; dtor defined elsewhere
struct InstanceSecondaryBase {
    virtual ~InstanceSecondaryBase();
};

class Instance : public InstancePrimaryBase, public InstanceSecondaryBase {
public:
    virtual ~Instance();
};

template<class T, class B, const char* const* Name>
class DescribedCreatable : public B {
public:
    virtual ~DescribedCreatable() {}
};

// Explicit instantiation emits the vftables, the vector deleting destructor
// and its adjustor{16} thunk.
template class DescribedCreatable<Team, Instance, &sTeam>;

} // namespace RBX
