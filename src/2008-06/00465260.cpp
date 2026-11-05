// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

namespace boost {
struct lock_error { lock_error(); };
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
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class recursive_mutex {
public:
    void do_lock();
    void do_unlock();
    void* m_mutex;
    bool m_critical_section;
    unsigned long m_count;
};
template<class M> class scoped_lock {
public:
    explicit scoped_lock(M& mx) : m_mutex(mx), m_locked(false) { lock(); }
    ~scoped_lock() { if (m_locked) unlock(); }
    void lock() { if (m_locked) throw lock_error(); m_mutex.do_lock(); m_locked = true; }
    void unlock() { if (!m_locked) throw lock_error(); m_mutex.do_unlock(); m_locked = false; }
    M& m_mutex;
    bool m_locked;
};
}

namespace RBX {
class Instance;
template<class A, class B> class Listener { public: virtual void onEvent(const A*, B) = 0; };
template<class A, class B> class Notifier {
public:
    void addListener(Listener<A, B>* l) const;
    void removeListener(Listener<A, B>* l) const;
    char pad[0x20];
};
struct E1 {}; struct E2 {}; struct E3 {};
struct PadS { char pad0[0xa4]; };
class Script : public PadS, public Notifier<Script, E1>, public Notifier<Script, E2> {};
struct PadX { char pad0[0x190]; };
class ServiceX : public PadX, public Notifier<ServiceX, E3> {};
template<class C, class E, class P> inline void removeL(const boost::shared_ptr<P>& p, Listener<C, E>* l)
{ if (p) p->Notifier<C, E>::removeListener(l); }
template<class C, class E, class P> inline void addL(const boost::shared_ptr<P>& p, Listener<C, E>* l)
{ if (p) p->Notifier<C, E>::addListener(l); }
class DataModel : public boost::recursive_mutex {
public:
    static boost::shared_ptr<DataModel> get(Script* s);
};
template<class T> T* createService(Script* s);
template<class T> boost::shared_ptr<T> shared_from(T* p);
}
class PadA { public: virtual ~PadA(); char pad0[0x1c]; void* m_hWnd; char pad1[0xec - 0x24]; };
class PadB { public: virtual void f(); char pad[0x1c]; };

class CScriptEditor
    : public PadA
    , public RBX::Listener<RBX::Script, RBX::E1>
    , public RBX::Listener<RBX::Script, RBX::E2>
    , public PadB
    , public RBX::Listener<RBX::ServiceX, RBX::E3>
{
public:
    char pad3[0x138 - 0x118];
    boost::shared_ptr<RBX::DataModel> dataModel;
    int pad4;
    boost::shared_ptr<RBX::Script> script;
    boost::shared_ptr<RBX::ServiceX> service;
    void setScript(boost::shared_ptr<RBX::Script> s);
};

void CScriptEditor::setScript(boost::shared_ptr<RBX::Script> s)
{
    if (script) {
        boost::scoped_lock<boost::recursive_mutex> lock(*dataModel);
        RBX::removeL<RBX::Script, RBX::E1>(script, this);
        RBX::removeL<RBX::Script, RBX::E2>(script, this);
        RBX::removeL<RBX::ServiceX, RBX::E3>(service, this);
        script.reset();
        service.reset();
        dataModel.reset();
    }
    if (s) {
        dataModel = RBX::DataModel::get(s.get());
        script = s;
        boost::scoped_lock<boost::recursive_mutex> lock(*dataModel);
        service = RBX::shared_from(RBX::createService<RBX::ServiceX>(s.get()));
        RBX::addL<RBX::ServiceX, RBX::E3>(service, this);
        RBX::addL<RBX::Script, RBX::E2>(script, this);
        RBX::addL<RBX::Script, RBX::E1>(script, this);
    }
    if (m_hWnd)
        PostMessageA(m_hWnd, 0x465, 0, 0);
}
