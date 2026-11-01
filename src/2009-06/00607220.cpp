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
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release();
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
template<class T> class scoped_ptr {
    T* px;
public:
    ~scoped_ptr() { delete px; }
};
}
namespace RBX {
class Instance;
template<class Base> class Creatable {
public:
    template<class T> static boost::shared_ptr<T> create();
};
class DataModel {
public:
    class LockImpl {
    public:
        ~LockImpl();
    };
    class LegacyLock {
        LockImpl* impl;
    public:
        LegacyLock(boost::shared_ptr<DataModel> dataModel, int mode);
        ~LegacyLock() { delete impl; }
    };
    char pad[0x261];
    bool initialized;
    void initializeContents(bool startHeartbeat);
    static boost::shared_ptr<DataModel> createDataModel(bool startHeartbeat);
};
boost::shared_ptr<DataModel> DataModel::createDataModel(bool startHeartbeat)
{
    boost::shared_ptr<DataModel> dataModel = Creatable<Instance>::create<DataModel>();
    LegacyLock lock(dataModel, 1);
    dataModel->initializeContents(startHeartbeat);
    dataModel->initialized = true;
    return dataModel;
}
}
