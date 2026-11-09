// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <string>
namespace boost { struct once_flag { long v; }; void call_once(once_flag& f, void (*fn)()); }
namespace tbb {
class queuing_rw_mutex {
public:
    class scoped_lock {
    public:
        scoped_lock(queuing_rw_mutex& m, bool write = true) : mutex(0) { acquire(m, write); }
        ~scoped_lock() { if (mutex) release(); }
        void acquire(queuing_rw_mutex& m, bool write = true);
        bool upgrade_to_writer();
        void release();
    private:
        queuing_rw_mutex* mutex;
        scoped_lock* prev;
        scoped_lock* next;
        unsigned char state;
        unsigned char going;
        unsigned char internal_lock;
    };
};
}
namespace RBX {
class Name {
public:
    std::string name;
    Name(const char* s) : name(s) {}
    static const Name& declare(const char* sName);
};
typedef std::map<std::string, Name*> NameMap;
NameMap& getNames();
tbb::queuing_rw_mutex& getMutex();
extern Name* emptyName;
extern boost::once_flag emptyFlag;
void initEmpty();
const Name& Name::declare(const char* sName)
{
    if (sName == 0) {
        boost::call_once(emptyFlag, initEmpty);
        return *emptyName;
    }
    tbb::queuing_rw_mutex::scoped_lock lock(getMutex(), false);
    NameMap::iterator iter = getNames().find(std::string(sName));
    if (iter != getNames().end())
        return *iter->second;
    lock.upgrade_to_writer();
    Name* n = new Name(sName);
    getNames()[sName] = n;
    return *n;
}
}
