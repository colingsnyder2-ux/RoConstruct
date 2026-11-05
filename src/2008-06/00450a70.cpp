// from server: 100% by EspClaude
// roc 2008-06 00450a70  unit: CRobloxDoc  size: 387 bytes
#include <stdio.h>
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
    typedef T* this_type::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &this_type::px; }
};
}

namespace RBX {
class DataModel {
public:
    double getGameTime() const;
    class scoped_write_request {
        void* a; void* b; void* c;
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
    };
};
}

class CCmdUI {
public:
    virtual void Enable(int bOn = 1);
    virtual void SetCheck(int nCheck = 1);
    virtual void SetRadio(int bOn = 1);
    virtual void SetText(const char* lpszText);
};

namespace RBX { class Game : public DataModel {}; }
class RobloxView {
public:
    boost::shared_ptr<RBX::Game> getDataModel() const;
};

class CRobloxDoc {
    unsigned char padding[0x94];
    RobloxView* view;
public:
    boost::shared_ptr<RBX::DataModel> getDataModel();
    void OnUpdateGameTime(CCmdUI* pCmdUI);
};

void CRobloxDoc::OnUpdateGameTime(CCmdUI* pCmdUI)
{
    if (getDataModel()) {
        char buf[32];
        {
            RBX::DataModel::scoped_write_request request(view->getDataModel());
            sprintf(buf, "t %.4g", getDataModel()->getGameTime());
        }
        pCmdUI->SetText(buf);
    }
}
