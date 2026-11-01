// from server: 100% by EspClaude
// roc 2009-06 0044ef40  size: 243 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
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
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
}
namespace RBX {
class IDataState {
public:
    virtual void setDirty(bool);
    virtual bool isDirty() const;
};
class DataModelPad { public: virtual ~DataModelPad(); char p[0xf4]; };
class DataModel : public DataModelPad, public IDataState {};
}
class CRobloxDoc {
public:
    boost::shared_ptr<RBX::DataModel> getDataModel();
    int isDirty();
};
int CRobloxDoc::isDirty()
{
    bool has = getDataModel();
    if (has)
        return getDataModel()->isDirty();
    return 0;
}
