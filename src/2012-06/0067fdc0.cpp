// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedDecrement, _InterlockedExchangeAdd)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
};
struct shared_count {
    sp_counted_base* pi;
    ~shared_count() { if (pi) pi->release(); }
};
struct sp { void* px; shared_count pn; };

void f(sp p, int* n)
{
    ++*n;
}
