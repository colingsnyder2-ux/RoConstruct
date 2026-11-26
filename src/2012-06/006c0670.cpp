// from server: 100% by Xemicl
// roc 2012-06 006c0670  unit: RBX::VSystemAddress::?$TypedPropertyDescriptor  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c0670
//
// 006c0670  8b442408             mov eax, dword ptr [esp + 8]
// 006c0674  57                   push edi
// 006c0675  8bf9                 mov edi, ecx
// 006c0677  8907                 mov dword ptr [edi], eax
// 006c0679  8b442410             mov eax, dword ptr [esp + 0x10]
// 006c067d  894704               mov dword ptr [edi + 4], eax
// 006c0680  85c0                 test eax, eax
// 006c0682  7446                 je 0x6c06ca
// 006c0684  56                   push esi
// 006c0685  83c004               add eax, 4
// 006c0688  b901000000           mov ecx, 1
// 006c068d  f00fc108             lock xadd dword ptr [eax], ecx
// 006c0691  8b742414             mov esi, dword ptr [esp + 0x14]
// 006c0695  85f6                 test esi, esi
// 006c0697  742a                 je 0x6c06c3
// 006c0699  8d5604               lea edx, [esi + 4]
// 006c069c  83c8ff               or eax, 0xffffffff
// 006c069f  f00fc102             lock xadd dword ptr [edx], eax
// 006c06a3  751e                 jne 0x6c06c3
// 006c06a5  8b16                 mov edx, dword ptr [esi]
// 006c06a7  8b4204               mov eax, dword ptr [edx + 4]
// 006c06aa  8bce                 mov ecx, esi
// 006c06ac  ffd0                 call eax
// 006c06ae  8d4e08               lea ecx, [esi + 8]
// 006c06b1  83caff               or edx, 0xffffffff
// 006c06b4  f00fc111             lock xadd dword ptr [ecx], edx
// 006c06b8  7509                 jne 0x6c06c3
// 006c06ba  8b06                 mov eax, dword ptr [esi]
// 006c06bc  8b5008               mov edx, dword ptr [eax + 8]
// 006c06bf  8bce                 mov ecx, esi
// 006c06c1  ffd2                 call edx
// 006c06c3  5e                   pop esi
// 006c06c4  8bc7                 mov eax, edi
// 006c06c6  5f                   pop edi
// 006c06c7  c20c00               ret 0xc
// 006c06ca  8bc7                 mov eax, edi
// 006c06cc  5f                   pop edi
// 006c06cd  c20c00               ret 0xc
// copied from an identical function in another client (function ??0?$storage2@U?$arg@$00@boost@@V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@@_bi@2@@_bi@boost@@QAE@U?$arg@$00@2@V?$value@V?$shared_ptr@VDHTMLWindow@@@boost@@@12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
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
template<int I> struct arg {};
namespace _bi {
template<class T> class value {
public:
    value(T const& t) : t_(t) {}
    T t_;
};
template<class A1> struct storage1 {
    explicit storage1(A1 a1) : a1_(a1) {}
    A1 a1_;
};
template<int I> struct storage1< boost::arg<I> > {
    explicit storage1(boost::arg<I>) {}
    static boost::arg<I> a1_() { return boost::arg<I>(); }
};
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
    A2 a2_;
};
}
}
class DHTMLWindow;
template struct boost::_bi::storage2< boost::arg<1>, boost::_bi::value< boost::shared_ptr<DHTMLWindow> > >;