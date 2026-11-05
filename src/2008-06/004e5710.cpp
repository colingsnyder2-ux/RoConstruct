// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_53a1b795ab1d82f5.cpp

// Candidate translation unit (score above; library headers required).
#include <windows.h>
#include <map>
#include <boost/thread/mutex.hpp>
#include <boost/thread/once.hpp>

namespace RBX {
namespace ViewNew {

struct Object {
    virtual ~Object();
    virtual void release();
};

struct Link {
    Object* object;
    Link* next;
};

class atomic_count {
public:
    long operator--() { return InterlockedDecrement(&value_); }
    operator long() const { return static_cast<long const volatile&>(value_); }
private:
    long value_;
};

struct Control {
    virtual ~Control();
    atomic_count refs;
    Link* links;
};

class ControlPtr {
public:
    Control* p;
    operator bool() const { return p != 0; }
    Control* operator->() const { return p; }
    __forceinline void reset()
    {
        if (p)
        {
            if (--p->refs == 0)
            {
                Link* link = p->links;
                while (link)
                {
                    link->object->release();
                    Link* tmp = link;
                    link = link->next;
                    delete tmp;
                }
                delete p;
            }
            p = 0;
        }
    }
};

struct Key {
    int data[6];
    bool operator<(const Key& other) const;
};

struct Entry {
    ControlPtr levels[4];
};

struct Cache {
    std::map<Key, Entry> map;
    boost::mutex mutex;
};

Cache* cache;
static boost::once_flag cacheFlag = BOOST_ONCE_INIT;
static void initCache();

static Cache& getCache()
{
    boost::call_once(&initCache, cacheFlag);
    return *cache;
}

void purgeCache()
{
    boost::call_once(&initCache, cacheFlag);
    Cache& c = *cache;
    boost::mutex::scoped_lock lock(c.mutex);
    for (std::map<Key, Entry>::iterator it = c.map.begin(); it != c.map.end(); ++it)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (it->second.levels[i] && it->second.levels[i]->refs == 1)
                it->second.levels[i].reset();
        }
    }
}

static void initCache()
{
    cache = new Cache;
}
}
}
