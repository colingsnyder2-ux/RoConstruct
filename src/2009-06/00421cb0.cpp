// from server: 100% by EspClaude
// from server: 80% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_423b4549b1337dbf.cpp

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
    char data[0x7c];
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

struct Registration : RegistrationPrimary {
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

struct XBase {
    unsigned long data[2];
    ~XBase();
    void release();
};

struct X : XBase {
    ~X() { release(); }
};

struct S : Base, Registration {
    X x;
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
