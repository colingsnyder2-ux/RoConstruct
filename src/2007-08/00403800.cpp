// from server: 95% by EspClaude
// roc-cl: 50727
// from server: 100% by tester
// roc 2008-06 0046a940  unit: CWebToolbox  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046a940
//
// 0046a940  51                   push ecx
// 0046a941  8b5124               mov edx, dword ptr [ecx + 0x24]
// 0046a944  8b442408             mov eax, dword ptr [esp + 8]
// 0046a948  8910                 mov dword ptr [eax], edx
// 0046a94a  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 0046a94d  c7042400000000       mov dword ptr [esp], 0
// 0046a954  894804               mov dword ptr [eax + 4], ecx
// 0046a957  85c9                 test ecx, ecx
// 0046a959  740c                 je 0x46a967
// 0046a95b  83c104               add ecx, 4
// 0046a95e  ba01000000           mov edx, 1
// 0046a963  f00fc111             lock xadd dword ptr [ecx], edx
// 0046a967  59                   pop ecx
// 0046a968  c20400               ret 4

#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
};
}

template<class T>
class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}

struct Item;

struct Owner {
    char padding[0x24];
    boost::shared_ptr<Item> item;
    boost::shared_ptr<Item> get() const;
};

boost::shared_ptr<Item> Owner::get() const
{
    volatile int state = 0;
    return item;
}
