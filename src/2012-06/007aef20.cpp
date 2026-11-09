// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) {
        if (pi_ != 0) pi_->add_ref_copy();
    }
    ~shared_count() {
        if (pi_ != 0) pi_->release();
    }
};

struct shared_ptr_any {
    void* px;
    shared_count pn;
    shared_ptr_any(const shared_ptr_any& r) : px(r.px), pn(r.pn) {}
};

struct StdString {
    char storage[28];
    void destruct();
    ~StdString();
};

extern void (StdString::*g_stringDestructor)();

inline StdString::~StdString() {
    (this->*g_stringDestructor)();
}

struct TextServiceTarget {
    void invoke(const StdString& text, int a, int b, shared_ptr_any callback);
};

struct TextService {
    char pad[0x8c];
    TextServiceTarget* target;
    void forward(int a, int b, shared_ptr_any callback, StdString text);
};

void TextService::forward(int a, int b, shared_ptr_any callback, StdString text) {
    if (target != 0)
        target->invoke(text, a, b, callback);
}
