// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class String {
public:
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~String();
    char storage[0x1c];
};

namespace RBX {
class ServiceProvider {
public:
    template<class Class> Class* create() const;
    template<class Class>
    static Class* create(const ServiceProvider* serviceProvider)
    {
        if (serviceProvider)
            return serviceProvider->create<Class>();
        return 0;
    }
};

class DataModel : public ServiceProvider {
public:
    class scoped_lock {
    public:
        scoped_lock(shared_ptr<const DataModel> dm);
        ~scoped_lock();
        int a, b, c;
    };
};

class LuaAllocator {
public:
    void getHeapStats(unsigned int& bytes, unsigned int& blocks) const;
};

template<class T> class scoped_ptr {
public:
    T* ptr;
    typedef T* scoped_ptr::*unspecified_bool_type;
    T* operator->() const { return ptr; }
    operator unspecified_bool_type() const { return ptr == 0 ? 0 : &scoped_ptr::ptr; }
};

class ScriptContext {
public:
    char pad[0x1f0];
    scoped_ptr<LuaAllocator> allocator;
    void gc();
    unsigned int getThreadCount() const;
};

String memoryString(unsigned int bytes);

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO };
class StandardOut {
public:
    static shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
}

class RobloxDocument {
public:
    shared_ptr<RBX::DataModel> getDataModel() const;
};

class CRobloxDoc {
public:
    char pad[0x94];
    RobloxDocument* document;
    shared_ptr<RBX::DataModel> getDataModel() const;
    void OnScriptHeap();
};

void CRobloxDoc::OnScriptHeap()
{
    RBX::DataModel::scoped_lock lock(document->getDataModel());
    RBX::ScriptContext* sc = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    if (sc && sc->allocator)
    {
        sc->gc();
        unsigned int bytes, blocks;
        sc->allocator->getHeapStats(bytes, blocks);
        String heap = RBX::memoryString(bytes);
        unsigned int threads = sc->getThreadCount();
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "Script heap %s (%d blocks), %d threads", heap.c_str(), blocks, threads);
    }
}
