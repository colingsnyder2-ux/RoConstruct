// from server: 96% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) pn->add_ref_copy(); }
    ~shared_ptr() { if (pn) pn->release(); }
    shared_ptr& operator=(const shared_ptr& r);
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
}
namespace RBX {
template<class T> boost::shared_ptr<T> shared_from(T* r);
namespace Lua { class ThreadNode { public: void eraseAllRefs(); }; }
class Script {
public:
    char pad[0xdc];
    boost::shared_ptr<Lua::ThreadNode> threadNode;
};
template<> boost::shared_ptr<Script> shared_from<Script>(Script* r);
class ScriptSet { public: size_t erase(Script* const& s); char pad[0x28]; };
class ScriptContext {
public:
    char pad[0xb0];
    ScriptSet scripts;
    std::vector<boost::shared_ptr<Script> > pendingScripts;
    void disassociateState(Script* script);
    void removeScript(Script* script);
};
}
template<> std::vector<boost::shared_ptr<RBX::Script> >::iterator std::vector<boost::shared_ptr<RBX::Script> >::erase(const_iterator);
namespace RBX {
inline void ScriptContext::disassociateState(Script* script)
{
    if (script->threadNode) {
        script->threadNode->eraseAllRefs();
        script->threadNode.reset();
    }
}
void ScriptContext::removeScript(Script* script)
{
    Script* s = script;
    scripts.erase(script);
    disassociateState(s);
    std::vector<boost::shared_ptr<Script> >::iterator it = std::find(pendingScripts.begin(), pendingScripts.end(), shared_from(s));
    if (it != pendingScripts.end())
        pendingScripts.erase(it);
}
}
