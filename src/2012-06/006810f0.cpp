// from server: 100% by Xemicl
// roc 2012-06 006810f0  unit: VAuthoringSettings::?$FactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006810f0
//
// 006810f0  6aff                 push -1
// 006810f2  684b9baa00           push 0xaa9b4b
// 006810f7  64a100000000         mov eax, dword ptr fs:[0]
// 006810fd  50                   push eax
// 006810fe  64892500000000       mov dword ptr fs:[0], esp
// 00681105  51                   push ecx
// 00681106  56                   push esi
// 00681107  8bf1                 mov esi, ecx
// 00681109  89742404             mov dword ptr [esp + 4], esi
// 0068110d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00681110  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00681118  85c9                 test ecx, ecx
// 0068111a  7406                 je 0x681122
// 0068111c  56                   push esi
// 0068111d  e84e87efff           call 0x579870
// 00681122  8b7608               mov esi, dword ptr [esi + 8]
// 00681125  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0068112d  85f6                 test esi, esi
// 0068112f  742a                 je 0x68115b
// 00681131  8d4604               lea eax, [esi + 4]
// 00681134  83c9ff               or ecx, 0xffffffff
// 00681137  f00fc108             lock xadd dword ptr [eax], ecx
// 0068113b  751e                 jne 0x68115b
// 0068113d  8b16                 mov edx, dword ptr [esi]
// 0068113f  8b4204               mov eax, dword ptr [edx + 4]
// 00681142  8bce                 mov ecx, esi
// 00681144  ffd0                 call eax
// 00681146  8d4e08               lea ecx, [esi + 8]
// 00681149  83caff               or edx, 0xffffffff
// 0068114c  f00fc111             lock xadd dword ptr [ecx], edx
// 00681150  7509                 jne 0x68115b
// 00681152  8b06                 mov eax, dword ptr [esi]
// 00681154  8b5008               mov edx, dword ptr [eax + 8]
// 00681157  8bce                 mov ecx, esi
// 00681159  ffd2                 call edx
// 0068115b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068115f  5e                   pop esi
// 00681160  64890d00000000       mov dword ptr fs:[0], ecx
// 00681167  83c410               add esp, 0x10
// 0068116a  c3                   ret 
// copied from an identical function in another client (function ??1?$slot@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@boost@@@boost@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
namespace std { template<class T> class allocator; }
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
};
template<class Sig, class A> class function;
namespace signals { namespace detail {
class slot_base {
public:
    struct data_t { void release(const slot_base* s); };
    int pad;
    shared_ptr<data_t> data;
};
}}
template<class SlotFunction> class slot : public signals::detail::slot_base {
public:
    ~slot() { if (data.get()) data.get()->release(this); }
};
}
namespace RBX { class Instance; }
template class boost::slot<boost::function<void (boost::shared_ptr<RBX::Instance>), std::allocator<void> > >;