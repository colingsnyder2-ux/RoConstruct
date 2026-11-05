// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectiontree_70d84558fbd832d7.cpp

// Candidate translation unit (score above; library headers required).
// from server: 97% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

struct OwnedObject {
    virtual void unused();
    virtual ~OwnedObject();
};

struct Owned {
    OwnedObject* object;
    ~Owned();
};

__forceinline Owned::~Owned()
{
    if (object)
        delete object;
}

struct PrimaryBase {
    virtual ~PrimaryBase();
    char data[0x50];
};

struct SecondaryBase {
    virtual ~SecondaryBase();
    char data[0x78];
};

struct Base : PrimaryBase, SecondaryBase {
    virtual ~Base();
};

struct RegistrationPrimary {
    virtual ~RegistrationPrimary();
};

struct RegistrationSecondary {
    virtual ~RegistrationSecondary();
};

struct Registration : RegistrationPrimary, RegistrationSecondary {
    virtual ~Registration();
};

struct MemberBase {
    virtual ~MemberBase();
    unsigned long data[2];
};

struct Member : MemberBase {
    virtual ~Member();
};

__forceinline Member::~Member()
{
}

struct Collection {
    char data[0x20];
    ~Collection();
};

struct Connection {
    char data[0x20];
    ~Connection();
};

struct S : Base, Registration {
    Member member;
    Collection collection;
    Connection connection;
    Shared shared;
    Owned owned;

    void reset(Shared value);
    virtual ~S();
};

S::~S()
{
    reset(Shared());
}
