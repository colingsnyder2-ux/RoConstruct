// from server: 100% by Xemicl
// roc 2012-06 005b6ad0  unit: RBX::Network::InterpolatingPhysicsReceiver::Nugget::UHistory::?$sp_counted_impl_p  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b6ad0
//
// 005b6ad0  6aff                 push -1
// 005b6ad2  68e8e8aa00           push 0xaae8e8
// 005b6ad7  64a100000000         mov eax, dword ptr fs:[0]
// 005b6add  50                   push eax
// 005b6ade  64892500000000       mov dword ptr fs:[0], esp
// 005b6ae5  51                   push ecx
// 005b6ae6  56                   push esi
// 005b6ae7  57                   push edi
// 005b6ae8  8bf9                 mov edi, ecx
// 005b6aea  897c2408             mov dword ptr [esp + 8], edi
// 005b6aee  8b7728               mov esi, dword ptr [edi + 0x28]
// 005b6af1  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005b6af9  85f6                 test esi, esi
// 005b6afb  742a                 je 0x5b6b27
// 005b6afd  8d4604               lea eax, [esi + 4]
// 005b6b00  83c9ff               or ecx, 0xffffffff
// 005b6b03  f00fc108             lock xadd dword ptr [eax], ecx
// 005b6b07  751e                 jne 0x5b6b27
// 005b6b09  8b16                 mov edx, dword ptr [esi]
// 005b6b0b  8b4204               mov eax, dword ptr [edx + 4]
// 005b6b0e  8bce                 mov ecx, esi
// 005b6b10  ffd0                 call eax
// 005b6b12  8d4e08               lea ecx, [esi + 8]
// 005b6b15  83caff               or edx, 0xffffffff
// 005b6b18  f00fc111             lock xadd dword ptr [ecx], edx
// 005b6b1c  7509                 jne 0x5b6b27
// 005b6b1e  8b06                 mov eax, dword ptr [esi]
// 005b6b20  8b5008               mov edx, dword ptr [eax + 8]
// 005b6b23  8bce                 mov ecx, esi
// 005b6b25  ffd2                 call edx
// 005b6b27  8bcf                 mov ecx, edi
// 005b6b29  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005b6b31  e89aaffbff           call 0x571ad0
// 005b6b36  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b6b3a  5f                   pop edi
// 005b6b3b  5e                   pop esi
// 005b6b3c  64890d00000000       mov dword ptr fs:[0], ecx
// 005b6b43  83c410               add esp, 0x10
// 005b6b46  c3                   ret 
// copied from an identical function in another client (function ??1D@@UAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
struct T;
struct Base {
    Base();
    virtual ~Base();
    char pad[0x1c];
};
struct Item { int a; boost::shared_ptr<T> p; Item(int x, const boost::shared_ptr<T>& y) : a(x), p(y) {} };
struct D : Base {
    Item item;
    D(int a, boost::shared_ptr<T> p);
};
D::D(int a_, boost::shared_ptr<T> p_) : item(a_, p_) {}