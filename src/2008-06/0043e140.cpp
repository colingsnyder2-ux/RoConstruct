// from server: 100% by coldek
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <map>
#include <intrin.h>

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
template <class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr() { if (pn) pn->release(); }
    T* get() const { return px; }
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class Script : public Instance {
};
template <class T> boost::shared_ptr<T> shared_from(T* p);
}

class AFX_MODULE_STATE {
public:
    void* pad;
    class CWinApp* m_pCurrentWinApp;
};
AFX_MODULE_STATE* __stdcall AfxGetModuleState();

class CWinApp {
};
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }
class CRobloxApp : public CWinApp {
public:
    void apply(boost::shared_ptr<RBX::Script> script);
};

struct KeyBase { int x; };
struct KeyDerived : KeyBase {};
typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;
typedef std::map<KeyBase*, Instances> InstanceMap;

struct OwnerPrefix { char pad[0x218]; };
struct MapHolder {
    InstanceMap instances;
    InstanceMap::iterator findB(KeyBase* key) { return instances.find(key); }
};
struct Owner : OwnerPrefix, MapHolder {};

class ScriptItem {
public:
    char pad[0x110];
    std::vector<KeyDerived*> keys;
    Owner* owner;
    void open(int);
};

void ScriptItem::open(int)
{
    InstanceMap::iterator mapEnd = owner->instances.end();
    for (std::vector<KeyDerived*>::const_iterator it = keys.begin(), end = keys.end(); it != end; ++it) {
        InstanceMap::iterator found = owner->findB(*it);
        if (found != mapEnd) {
            for (Instances::iterator j = found->second.begin(), jEnd = found->second.end(); j != jEnd; ++j) {
                if (RBX::Script* script = dynamic_cast<RBX::Script*>(j->get()))
                    static_cast<CRobloxApp*>(AfxGetApp())->apply(RBX::shared_from(script));
            }
        }
    }
}
