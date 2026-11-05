// from server: 100% by tajop


extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    void weak_release();
    void release();
};

inline void sp_counted_base::weak_release()
{
    if (_InterlockedDecrement(&weak_count_) == 0) {
        destroy();
    }
}

inline void sp_counted_base::release()
{
    if (_InterlockedDecrement(&use_count_) == 0) {
        dispose();
        weak_release();
    }
}

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count();
    void swap(shared_count& r);
};

inline shared_count::~shared_count()
{
    if (pi_ != 0) {
        pi_->release();
    }
}

inline void shared_count::swap(shared_count& r)
{
    sp_counted_base* tmp = r.pi_;
    r.pi_ = pi_;
    pi_ = tmp;
}

struct T;

inline void swap_ptr(T*& left, T*& right)
{
    if (&left != &right) {
        T* tmp = left;
        left = right;
        right = tmp;
    }
}

struct S {
    T* px;
    shared_count pn;
    S(T* p);
    void swap(S& other);
    void reset(T* p);
};

inline void S::swap(S& other)
{
    swap_ptr(px, other.px);
    pn.swap(other.pn);
}

void S::reset(T* p)
{
    S(p).swap(*this);
}
