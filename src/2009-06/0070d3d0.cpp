// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>

struct CRITICAL_SECTION { int d[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

class Mutex {
public:
    CRITICAL_SECTION cs;
    class scoped_lock {
        Mutex& m;
    public:
        scoped_lock(Mutex& m) : m(m) { EnterCriticalSection(&m.cs); }
        ~scoped_lock() { LeaveCriticalSection(&m.cs); }
    };
};

class Owner;

class Item {
public:
    virtual bool isWaitingFor(Owner* o) = 0;
};

namespace boost {
namespace detail { class sp_counted_base; }
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr&);
    ~shared_ptr();
    T* get() const { return px; }
};
}

struct Pred {
    bool (Item::*f)(Owner*);
    Owner* o;
    bool operator()(const boost::shared_ptr<Item>& p) const { return (p.get()->*f)(o); }
};

class Owner {
public:
    char pad[0x2c];
    Mutex mutex;
    std::vector<boost::shared_ptr<Item> > items;
    bool isBusy();
};

bool Owner::isBusy()
{
    if (items.empty())
        return false;
    Mutex::scoped_lock lock(mutex);
    Pred p = { &Item::isWaitingFor, this };
    return std::find_if(items.begin(), items.end(), p) != items.end();
}
