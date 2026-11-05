// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_7466319d2a89dd39.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>

namespace RBX {
    class Instance;
    class ServiceProvider;
}

struct Listener {
    unsigned char storage[4];
};

struct FirstListener : Listener {};
struct SecondListener : Listener {};

struct Event {
    void connect(Listener*);
};

struct Object {
    unsigned char storage[0x24];
    Event first;
    unsigned char storage2[0x1f];
    Event second;
};

struct Padding {
    unsigned char storage[0x168];
};

struct S : Padding, FirstListener, SecondListener {
    unsigned char padding[0x10];
    boost::shared_ptr<Object> value;

    void reset();
    void update(int, int);
};

RBX::ServiceProvider* __cdecl func_005fcc80(RBX::Instance*);
boost::shared_ptr<Object> __cdecl func_00618a40(RBX::ServiceProvider*);

static inline void attach(const boost::shared_ptr<Object>& o, Event Object::*ev, Listener* l)
{
    if (o)
        ((*o).*ev).connect(l);
}

void S::update(int a, int b)
{
    if (a)
        reset();

    if (b) {
        value = func_00618a40(
            func_005fcc80(reinterpret_cast<RBX::Instance*>(this)));

        attach(value, &Object::first, static_cast<FirstListener*>(this));
        attach(value, &Object::second, static_cast<SecondListener*>(this));
    }
}
