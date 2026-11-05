// from server: 100% by tajop

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base_0069b250 {
    virtual void destruct();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void weak_release() {
        if (_InterlockedDecrement(&weak_count) == 0) {
            destroy();
        }
    }
    void release() {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct shared_count_0069b250 {
    sp_counted_base_0069b250* pi;
    ~shared_count_0069b250() {
        if (pi != 0) {
            pi->release();
        }
    }
};

struct weak_count_0069b250 {
    sp_counted_base_0069b250* pi;
    ~weak_count_0069b250() {
        if (pi != 0) {
            pi->weak_release();
        }
    }
};

struct FactoryProduct_0069b250 {
    int field_0;
    weak_count_0069b250 weak_this;
    int field_8;
    int field_c;
    shared_count_0069b250 shared;
    ~FactoryProduct_0069b250();
};

FactoryProduct_0069b250::~FactoryProduct_0069b250()
{
}
