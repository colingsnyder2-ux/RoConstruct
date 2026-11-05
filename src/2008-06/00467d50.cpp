// from server: 100% by EspClaude
// from server: 93% by EspClaude
// roc 2008-06 00467d50  unit: DxUserInput
#include <string>
#include <intrin.h>

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
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}

template<class T>
class shared_ptr {
    typedef shared_ptr<T> this_type;
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0) {}
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* this_type::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &this_type::px; }
};
}

namespace RBX {
class DataModel {
public:
    char pad[0x1c8];
    struct VerbContainer { class Verb* getVerb(std::string name); } verbs;
    class scoped_write_request {
        void* a; void* b; void* c;
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
    };
};
}


namespace RBX {
class Game : public DataModel {};
class Verb {
public:
    virtual ~Verb();
    virtual void a();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
};
}

struct AFX_MODULE_STATE { void* reserved; struct CWinApp* m_pCurrentWinApp; };
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
struct CWinApp { char pad[0x20]; struct CWnd* m_pMainWnd; };
struct CWnd { char pad[0x104]; bool flag; bool isFlag() const { return flag; } };
inline CWinApp* __stdcall AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }

boost::shared_ptr<RBX::Game> getDataModel() throw();

class DxUserInput {
public:
    static bool isToolboxEnabled();
};

bool DxUserInput::isToolboxEnabled()
{
    CWnd* w = AfxGetApp()->m_pMainWnd;
    if (w->isFlag()) {
        if (!!getDataModel()) {
            RBX::DataModel::scoped_write_request request(getDataModel());
            RBX::Verb* verb = getDataModel()->verbs.getVerb("ToggleToolbox");
            if (verb)
                return verb->isChecked();
        }
    }
    return true;
}
