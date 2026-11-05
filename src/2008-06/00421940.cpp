// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_listenerownerconstructor_ad59d9063ba7db00.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Base
{
    unsigned char reserved[0x374];

    Base();
    virtual ~Base();
};

struct ListenerA
{
    unsigned char reserved[0x20];

    ListenerA();
    virtual ~ListenerA();
};

struct ListenerB
{
    unsigned char reserved[0x20];

    ListenerB();
    virtual ~ListenerB();
};

struct S : Base, ListenerA, ListenerB
{
    boost::shared_ptr<void> owner;
    bool active;

    S();
    virtual ~S();
};

S::S()
    : active(false)
{
}