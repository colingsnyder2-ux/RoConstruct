// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
namespace tbb {
class queuing_rw_mutex {
public:
    class scoped_lock {
        queuing_rw_mutex* mutex;
        scoped_lock* prev;
        scoped_lock* next;
        unsigned char state;
        unsigned char going;
        unsigned char internal_lock;
    public:
        scoped_lock(queuing_rw_mutex& m, bool write = true) : mutex(0) { acquire(m, write); }
        ~scoped_lock() { if (mutex) release(); }
        void acquire(queuing_rw_mutex& m, bool write = true);
        void release();
    };
    scoped_lock* q_tail;
};
}
namespace RBX {
class Name;
class Guid {
public:
    const Name* scope;
    unsigned int index;
    bool operator<(const Guid&) const;
    class Registry;
};
const Name& getLocalScope();
class Guid::Registry {
    int pad[2];
    std::map<Guid, unsigned int> map;
    tbb::queuing_rw_mutex mutex;
public:
    bool lookup(const Guid& key, unsigned int* result);
};
bool Guid::Registry::lookup(const Guid& key, unsigned int* result)
{
    const Name* scope = key.scope;
    if (&getLocalScope() == scope) {
        *result = 0;
        return true;
    }
    tbb::queuing_rw_mutex::scoped_lock lock(mutex, false);
    std::map<Guid, unsigned int>::const_iterator it = map.find(key);
    if (it != map.end()) {
        *result = it->second;
        return true;
    }
    *result = 0;
    return false;
}
}
