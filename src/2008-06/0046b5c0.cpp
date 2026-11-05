// from server: 100% by EspClaude
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_c1e239fce8d361d0.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Listener {
    unsigned long value;
};
struct FirstListener : Listener {};
struct SecondListener : Listener {};

struct Signal {
    void connect(Listener *);
};

struct FirstSource {
    char padding[0x344];
    Signal signal;
};

struct SecondSource {
    char padding[0x130];
    Signal signal;
};

struct Main {
    char padding[0x204];
    FirstSource *source;
    void *getValue();
    SecondSource *getSource();
};

typedef boost::shared_ptr<Main> Shared;

struct Guard {
    char storage[12];
    Guard(Shared);
    ~Guard();
};

extern Shared __cdecl makeFirst(int);
extern Shared __cdecl makeSecond(void *);

struct ObjectBase {
    char padding[0x18];
};

struct Object : ObjectBase, SecondListener, FirstListener {
    unsigned long reserved;
    Shared first;
    Shared second;
    long initialize();
};

long Object::initialize()
{
    first = makeFirst(1);
    Guard guard(first);
    second = makeSecond(first->getValue());

    Listener *listener = static_cast<FirstListener *>(this);
    FirstSource *source = first->source;
    if (source)
        source->signal.connect(listener);

    listener = static_cast<SecondListener *>(this);
    SecondSource *other = first->getSource();
    if (other)
        other->signal.connect(listener);

    return 0;
}

