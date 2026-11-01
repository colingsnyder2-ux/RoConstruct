// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
};
}

namespace RBX {
class IDataState { public: virtual void setDirty(bool) = 0; };
class DataModelPad { public: virtual ~DataModelPad(); char pad[0x100 - 4]; };
class DataModel : public DataModelPad, public IDataState {};

struct Time { double sec; Time(double s = 0) : sec(s) {} };
class CEvent {
public:
    void* handle;
    CEvent(bool manualReset, bool initialState);
    ~CEvent();
};

class DataModelJob {
public:
    DataModelJob(const char* name, int type, int flags, IDataState* dm);
    virtual ~DataModelJob();
    char pad[0x1d0 - 4];
};
}

class CRobloxWnd {
public:
    class RenderJob : public RBX::DataModelJob {
    public:
        volatile bool busy;
        RBX::CEvent renderEvent;
        RBX::CEvent doneEvent;
        CRobloxWnd* wnd;
        RBX::Time lastTime;
        RenderJob(CRobloxWnd* wnd, boost::shared_ptr<RBX::DataModel> dm);
        ~RenderJob();
    };
};

CRobloxWnd::RenderJob::RenderJob(CRobloxWnd* wnd, boost::shared_ptr<RBX::DataModel> dm)
    : RBX::DataModelJob("Render", 2, 0, dm.get())
    , busy(false)
    , renderEvent(false, false)
    , doneEvent(false, false)
    , wnd(wnd)
{
}
