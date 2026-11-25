// from server: 100% by Xemicl
// from server: 100% by EspClaude
// roc 2009-06 004d6790  unit: RBX::Network::Server  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d6790
//
// 004d6790  6aff                 push -1
// 004d6792  683bbb8600           push 0x86bb3b
// 004d6797  64a100000000         mov eax, dword ptr fs:[0]
// 004d679d  50                   push eax
// 004d679e  64892500000000       mov dword ptr fs:[0], esp
// 004d67a5  51                   push ecx
// 004d67a6  53                   push ebx
// 004d67a7  55                   push ebp
// 004d67a8  8bd9                 mov ebx, ecx
// 004d67aa  56                   push esi
// 004d67ab  8b742420             mov esi, dword ptr [esp + 0x20]
// 004d67af  8d6b04               lea ebp, [ebx + 4]
// 004d67b2  56                   push esi
// 004d67b3  8bcd                 mov ecx, ebp
// 004d67b5  895c2410             mov dword ptr [esp + 0x10], ebx
// 004d67b9  8933                 mov dword ptr [ebx], esi
// 004d67bb  e8d0fcffff           call 0x4d6490
// 004d67c0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004d67c8  85f6                 test esi, esi
// 004d67ca  7456                 je 0x4d6822
// 004d67cc  57                   push edi
// 004d67cd  8d7e08               lea edi, [esi + 8]
// 004d67d0  85ff                 test edi, edi
// 004d67d2  7437                 je 0x4d680b
// 004d67d4  8937                 mov dword ptr [edi], esi
// 004d67d6  8b7500               mov esi, dword ptr [ebp]
// 004d67d9  3b7704               cmp esi, dword ptr [edi + 4]
// 004d67dc  742d                 je 0x4d680b
// 004d67de  85f6                 test esi, esi
// 004d67e0  740c                 je 0x4d67ee
// 004d67e2  8d4608               lea eax, [esi + 8]
// 004d67e5  b901000000           mov ecx, 1
// 004d67ea  f00fc108             lock xadd dword ptr [eax], ecx
// 004d67ee  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d67f1  85c9                 test ecx, ecx
// 004d67f3  7413                 je 0x4d6808
// 004d67f5  8d5108               lea edx, [ecx + 8]
// 004d67f8  83c8ff               or eax, 0xffffffff
// 004d67fb  f00fc102             lock xadd dword ptr [edx], eax
// 004d67ff  7507                 jne 0x4d6808
// 004d6801  8b11                 mov edx, dword ptr [ecx]
// 004d6803  8b4208               mov eax, dword ptr [edx + 8]
// 004d6806  ffd0                 call eax
// 004d6808  897704               mov dword ptr [edi + 4], esi
// 004d680b  5f                   pop edi
// 004d680c  5e                   pop esi
// 004d680d  5d                   pop ebp
// 004d680e  8bc3                 mov eax, ebx
// 004d6810  5b                   pop ebx
// 004d6811  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004d6815  64890d00000000       mov dword ptr fs:[0], ecx
// 004d681c  83c410               add esp, 0x10
// 004d681f  c20400               ret 4
// 004d6822  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004d6826  5e                   pop esi
// 004d6827  5d                   pop ebp
// 004d6828  8bc3                 mov eax, ebx
// 004d682a  5b                   pop ebx
// 004d682b  64890d00000000       mov dword ptr fs:[0], ecx
// 004d6832  83c410               add esp, 0x10
// 004d6835  c20400               ret 4

// shared_ptr<ClientProxy>(p, Creatable::Deleter) ctor
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_increment(long* pw) { return _InterlockedIncrement(pw); }
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    template<class P> explicit shared_count(P p);
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count& operator=(shared_count const& r) {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) {
            if (tmp != 0) tmp->weak_add_ref();
            if (pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> void _internal_assign(Y* px2, detail::shared_count const& pn2) { px = px2; pn = pn2; }
};
template<class T> class enable_shared_from_this {
public:
    mutable weak_ptr<T> _internal_weak_this;
};
template<class T, class Y> inline void sp_enable_shared_from_this(detail::shared_count const& pn, enable_shared_from_this<T> const* pe, Y const* px) {
    if (pe != 0) pe->_internal_weak_this._internal_assign(const_cast<Y*>(px), pn);
}
inline void sp_enable_shared_from_this(detail::shared_count const&, ...) {}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y> explicit shared_ptr(Y* p) : px(p), pn(p) { sp_enable_shared_from_this(pn, p, p); }
};
}
namespace RBX {
class Instance;
template<class T> class Creatable { public: struct Deleter { void operator()(Instance*) const; }; };
namespace Network { namespace Server {
struct Base0 { virtual ~Base0(); int pad; };
class ClientProxy : public Base0, public boost::enable_shared_from_this<ClientProxy> {};
} }
}
template boost::shared_ptr<RBX::Network::Server::ClientProxy>::shared_ptr(RBX::Network::Server::ClientProxy*);
