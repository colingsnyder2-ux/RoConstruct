// from server: 98% by EspClaude
// boost 1.34 shared_ptr (w32 sp_counted_base); virtual Creator::create returns
// shared_ptr<Base> converted from the static creator's shared_ptr<Derived>.
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};

class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    shared_ptr() : px(0) {}
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
};

class Instance {};
class RenderSettings : public Instance {};

struct ICreator {
    virtual shared_ptr<Instance> create() const = 0;
};

template<class T> struct Creator : ICreator {
    static shared_ptr<T> createStatic();
    virtual shared_ptr<Instance> create() const { return createStatic(); }
};

template struct Creator<RenderSettings>;
