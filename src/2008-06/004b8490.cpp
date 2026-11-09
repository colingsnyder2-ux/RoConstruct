// from server: 100% by EspClaude
// from server: 95% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_75b06e686af54303.cpp

// Candidate translation unit (score above; library headers required).
#include <intrin.h>
#include <deque>
#include <boost/shared_ptr.hpp>

struct Log {
    void __cdecl report(int, const char*, ...);
};

typedef boost::shared_ptr<Log> Shared;

struct Settings {
    char padding[0x131];
    unsigned char logging;
};

extern void __cdecl readMarker(void*, int*);
extern Settings* __cdecl settings();
extern Shared __cdecl logger();
extern const char markerFormat[];

struct Address {
    const char* text(int);
};

struct Item;
struct Signal {
    void notify(void**);
};

struct Entry {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    Entry* find(void*);
};

extern Registry registry;

struct S {
    char padding[0x2cdc];
    std::deque<boost::shared_ptr<Item> > queue;
    char gap[0x58];
    Address address;
    void f(void*);
};

void S::f(void* argument)
{
    int marker;
    readMarker(argument, &marker);

    if (settings()->logging)
        logger()->report(1, markerFormat, marker, address.text(1));

    Entry* entry = registry.find(queue.front().get());
    if (entry)
        entry->signal.notify(&argument);

    queue.pop_front();
}
