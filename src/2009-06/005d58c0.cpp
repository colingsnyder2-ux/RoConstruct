// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_increment(long* pw) { return _InterlockedIncrement(pw); }
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> weak_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
class Arbiter { public: virtual ~Arbiter(); };
class DataModelPad { public: virtual ~DataModelPad(); char pad[0xfc]; };
class DataModel : public DataModelPad, public Arbiter {};
class DataModelJob {
public:
    DataModelJob(const char* name, int type, bool b, Arbiter* arbiter);
    virtual ~DataModelJob();
    char pad[0x1cc - 4];
};
class PhysicsJob : public DataModelJob {
public:
    double fps;
    boost::weak_ptr<DataModel> dataModel;
    PhysicsJob(boost::shared_ptr<DataModel> dataModel);
    virtual ~PhysicsJob();
};
PhysicsJob::PhysicsJob(boost::shared_ptr<DataModel> dataModel)
    : DataModelJob("Physics", 3, false, dataModel.get()), fps(30.0), dataModel(dataModel)
{
}
}
