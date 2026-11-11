// from server: 100% by EspClaude
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct counted_base {
    void* vtbl;
    long use_count;
    void add_ref_copy() { _InterlockedIncrement(&use_count); }
    void release();
};

struct shared_count {
    counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) {
        if (pi_ != 0) pi_->add_ref_copy();
    }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

struct shared_ref {
    int px;
    shared_count pn;
};

struct placeholder {
    char pad[0xe8];
    shared_ref field_e8;
    shared_ref get();
};

shared_ref placeholder::get() {
    return field_e8;
}
