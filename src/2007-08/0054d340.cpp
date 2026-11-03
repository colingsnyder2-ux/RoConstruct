// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

struct Impl;
struct Sink {
    Impl* px;
    shared_count pn;
};

template<typename T>
class optional {
public:
    void reset(const T& t);
    void reset() {
        if (initialized_) {
            T* t = static_cast<T*>(address());
            t->~T();
            initialized_ = false;
        }
    }
private:
    void* address() { return &storage_; }
    union { char c[sizeof(T)]; void* a; } storage_;
    bool initialized_;
};

template<typename T>
void optional<T>::reset(const T& t)
{
    reset();
    new (address()) T(t);
    initialized_ = true;
}

inline void* operator new(unsigned int, void* p) { return p; }
template class optional<Sink>;
