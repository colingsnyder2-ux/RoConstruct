// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 00459270  unit: CRobloxView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459270
//
// 00459270  51                   push ecx
// 00459271  8b9170010000         mov edx, dword ptr [ecx + 0x170]
// 00459277  8b442408             mov eax, dword ptr [esp + 8]
// 0045927b  8910                 mov dword ptr [eax], edx
// 0045927d  8b8974010000         mov ecx, dword ptr [ecx + 0x174]
// 00459283  c7042400000000       mov dword ptr [esp], 0
// 0045928a  894804               mov dword ptr [eax + 4], ecx
// 0045928d  85c9                 test ecx, ecx
// 0045928f  740c                 je 0x45929d
// 00459291  83c104               add ecx, 4
// 00459294  ba01000000           mov edx, 1
// 00459299  f00fc111             lock xadd dword ptr [ecx], edx
// 0045929d  59                   pop ecx
// 0045929e  c20400               ret 4

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
    char padding[0x1a4];
    boost::shared_ptr<Item> item;
    boost::shared_ptr<Item> get() const;
};

boost::shared_ptr<Item> Owner::get() const
{
    volatile int state = 0;
    return item;
}
