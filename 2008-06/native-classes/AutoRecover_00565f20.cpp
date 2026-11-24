// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor thunk (this -= 20, then jump to the
// real vector deleting destructor). It cannot be written by hand, so I rebuild a class layout
// in which DescribedCreatable<Team,Instance,&sTeam> overrides a virtual destructor of a
// secondary base at offset 20. Explicit instantiation then makes the compiler emit the thunk.
// INFERRED: the layout of Instance and its bases is a guess from the adjustor offset alone.
// INFERRED: the template's third parameter is a pointer to a const char* const, which matches
// the mangled name $1?sTeam@2@3QBDB (address of RBX::sTeam). The previous draft used a
// reference parameter, which mangles differently.

namespace RBX {

extern const char* const sTeam;

// INFERRED: primary base, 20 bytes (vptr + 16 bytes of data)
class InstancePrimary {
public:
    InstancePrimary() {}
    virtual void primaryVirtual() {}
    int data[4];
};

// INFERRED: secondary base at offset 20 with a virtual destructor
class InstanceSecondary {
public:
    InstanceSecondary() {}
    virtual ~InstanceSecondary() {}
};

class Instance : public InstancePrimary, public InstanceSecondary {
public:
    Instance() {}
    virtual ~Instance() {}
};

class Team;

template<class Derived, class Base, const char* const* Name>
class DescribedCreatable : public Base {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

template class DescribedCreatable<Team, Instance, &sTeam>;

} // namespace RBX
