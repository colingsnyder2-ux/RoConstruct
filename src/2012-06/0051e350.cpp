// from server: 100% by Xemicl
// roc 2012-06 0051e350  unit: RBX::Network::P8Player::?$GetSetImpl  size: 230 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051e350
//
// 0051e350  64a100000000         mov eax, dword ptr fs:[0]
// 0051e356  6aff                 push -1
// 0051e358  6860b1aa00           push 0xaab160
// 0051e35d  50                   push eax
// 0051e35e  64892500000000       mov dword ptr fs:[0], esp
// 0051e365  56                   push esi
// 0051e366  57                   push edi
// 0051e367  8bf1                 mov esi, ecx
// 0051e369  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051e36d  8b542420             mov edx, dword ptr [esp + 0x20]
// 0051e371  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0051e379  8bc8                 mov ecx, eax
// 0051e37b  85c0                 test eax, eax
// 0051e37d  7410                 je 0x51e38f
// 0051e37f  83c008               add eax, 8
// 0051e382  bf01000000           mov edi, 1
// 0051e387  f00fc138             lock xadd dword ptr [eax], edi
// 0051e38b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051e38f  8916                 mov dword ptr [esi], edx
// 0051e391  894e04               mov dword ptr [esi + 4], ecx
// 0051e394  85c9                 test ecx, ecx
// 0051e396  7422                 je 0x51e3ba
// 0051e398  8d4108               lea eax, [ecx + 8]
// 0051e39b  8bd0                 mov edx, eax
// 0051e39d  bf01000000           mov edi, 1
// 0051e3a2  f00fc13a             lock xadd dword ptr [edx], edi
// 0051e3a6  83caff               or edx, 0xffffffff
// 0051e3a9  f00fc110             lock xadd dword ptr [eax], edx
// 0051e3ad  7507                 jne 0x51e3b6
// 0051e3af  8b01                 mov eax, dword ptr [ecx]
// 0051e3b1  8b5008               mov edx, dword ptr [eax + 8]
// 0051e3b4  ffd2                 call edx
// 0051e3b6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051e3ba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051e3be  894e08               mov dword ptr [esi + 8], ecx
// 0051e3c1  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051e3c5  894e0c               mov dword ptr [esi + 0xc], ecx
// 0051e3c8  85c9                 test ecx, ecx
// 0051e3ca  7414                 je 0x51e3e0
// 0051e3cc  83c108               add ecx, 8
// 0051e3cf  ba01000000           mov edx, 1
// 0051e3d4  f00fc111             lock xadd dword ptr [ecx], edx
// 0051e3d8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051e3dc  8b442424             mov eax, dword ptr [esp + 0x24]
// 0051e3e0  c644241000           mov byte ptr [esp + 0x10], 0
// 0051e3e5  85c0                 test eax, eax
// 0051e3e7  7419                 je 0x51e402
// 0051e3e9  8bc8                 mov ecx, eax
// 0051e3eb  83c008               add eax, 8
// 0051e3ee  83caff               or edx, 0xffffffff
// 0051e3f1  f00fc110             lock xadd dword ptr [eax], edx
// 0051e3f5  7507                 jne 0x51e3fe
// 0051e3f7  8b01                 mov eax, dword ptr [ecx]
// 0051e3f9  8b5008               mov edx, dword ptr [eax + 8]
// 0051e3fc  ffd2                 call edx
// 0051e3fe  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051e402  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0051e40a  85c9                 test ecx, ecx
// 0051e40c  7413                 je 0x51e421
// 0051e40e  8d4108               lea eax, [ecx + 8]
// 0051e411  83caff               or edx, 0xffffffff
// 0051e414  f00fc110             lock xadd dword ptr [eax], edx
// 0051e418  7507                 jne 0x51e421
// 0051e41a  8b01                 mov eax, dword ptr [ecx]
// 0051e41c  8b5008               mov edx, dword ptr [eax + 8]
// 0051e41f  ffd2                 call edx
// 0051e421  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051e425  5f                   pop edi
// 0051e426  8bc6                 mov eax, esi
// 0051e428  64890d00000000       mov dword ptr fs:[0], ecx
// 0051e42f  5e                   pop esi
// 0051e430  83c40c               add esp, 0xc
// 0051e433  c21800               ret 0x18
// copied from an identical function in another client (function ??0?$storage4@U?$arg@$00@@U?$arg@$01@@V?$value@V?$weak_ptr@UA@@@@@@V?$value@V?$weak_ptr@UB@@@@@@@@QAE@U?$arg@$00@@U?$arg@$01@@V?$value@V?$weak_ptr@UA@@@@@@V?$value@V?$weak_ptr@UB@@@@@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};

class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};

template<class T> class weak_ptr {
public:
    T* px;
    weak_count pn;
};

template<int I> struct arg {};

template<class T> class value {
public:
    value(T const& t) : t_(t) {}
private:
    T t_;
};

template<class A1> struct storage1 {
    explicit storage1(A1 a1) : a1_(a1) {}
    A1 a1_;
};
template<int I> struct storage1<arg<I> > {
    explicit storage1(arg<I>) {}
};
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
    A2 a2_;
};
template<class A1, int I> struct storage2<A1, arg<I> > : public storage1<A1> {
    storage2(A1 a1, arg<I>) : storage1<A1>(a1) {}
};
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
    storage3(A1 a1, A2 a2, A3 a3) : storage2<A1, A2>(a1, a2), a3_(a3) {}
    A3 a3_;
};
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> {
    storage4(A1 a1, A2 a2, A3 a3, A4 a4) : storage3<A1, A2, A3>(a1, a2, a3), a4_(a4) {}
    A4 a4_;
};
template<class A1, class A2, class A3, class A4> class list4 : private storage4<A1, A2, A3, A4> {
    typedef storage4<A1, A2, A3, A4> base_type;
public:
    list4(A1 a1, A2 a2, A3 a3, A4 a4) : base_type(a1, a2, a3, a4) {}
};

struct A; struct B;
template class list4<arg<1>, arg<2>, value<weak_ptr<A> >, value<weak_ptr<B> > >;