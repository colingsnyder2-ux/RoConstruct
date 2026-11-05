// from server: 100% by EspClaude
// from server: 93% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_768b9e348dd2905f.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
struct Object;
typedef boost::shared_ptr<Object> Shared;

struct Connection {
    char data[16];
    Connection(const Connection&);
    ~Connection();
    void disconnect();
};

struct Signal {
    void set(int);
};

struct Entry {
    Signal* signal;
    unsigned int padding;
    Connection first;
    Connection second;
    bool active;
};

#pragma pointers_to_members(full_generality, multiple_inheritance)
struct Object {
    template<class F> void connect(F);
};

struct S {
    char padding[0x2c38];
    std::map<Object*, Entry> joints;
    bool remove(Shared);
};

bool S::remove(Shared value) {
    if (!value)
        return false;

    std::map<Object*, Entry>::iterator it = joints.find(value.get());
    if (it == joints.end())
        return false;

    value->connect(boost::bind(&S::remove, this, _1));

    Entry& entry = it->second;
    entry.first.disconnect();
    entry.second.disconnect();
    if (entry.active)
        entry.signal->set(0);

    joints.erase(it);
    return true;
}
