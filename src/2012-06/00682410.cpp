// from server: 100% by Xemicl
// roc 2012-06 00682410  unit: RBX::Network::VPlayer::?$BoundFuncDesc  size: 287 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00682410
//
// 00682410  6aff                 push -1
// 00682412  6828d4aa00           push 0xaad428
// 00682417  64a100000000         mov eax, dword ptr fs:[0]
// 0068241d  50                   push eax
// 0068241e  64892500000000       mov dword ptr fs:[0], esp
// 00682425  83ec2c               sub esp, 0x2c
// 00682428  56                   push esi
// 00682429  833900               cmp dword ptr [ecx], 0
// 0068242c  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00682434  7514                 jne 0x68244a
// 00682436  8d4c2408             lea ecx, [esp + 8]
// 0068243a  e8a19ed8ff           call 0x40c2e0
// 0068243f  50                   push eax
// 00682440  c644243c02           mov byte ptr [esp + 0x3c], 2
// 00682445  e876d0d8ff           call 0x40f4c0
// 0068244a  8b542448             mov edx, dword ptr [esp + 0x48]
// 0068244e  83ec08               sub esp, 8
// 00682451  8bc4                 mov eax, esp
// 00682453  8910                 mov dword ptr [eax], edx
// 00682455  8b542454             mov edx, dword ptr [esp + 0x54]
// 00682459  895004               mov dword ptr [eax + 4], edx
// 0068245c  8b442454             mov eax, dword ptr [esp + 0x54]
// 00682460  8964240c             mov dword ptr [esp + 0xc], esp
// 00682464  85c0                 test eax, eax
// 00682466  740c                 je 0x682474
// 00682468  83c004               add eax, 4
// 0068246b  ba01000000           mov edx, 1
// 00682470  f00fc110             lock xadd dword ptr [eax], edx
// 00682474  8b542448             mov edx, dword ptr [esp + 0x48]
// 00682478  83ec08               sub esp, 8
// 0068247b  8bc4                 mov eax, esp
// 0068247d  8910                 mov dword ptr [eax], edx
// 0068247f  8b542454             mov edx, dword ptr [esp + 0x54]
// 00682483  895004               mov dword ptr [eax + 4], edx
// 00682486  8b442454             mov eax, dword ptr [esp + 0x54]
// 0068248a  89642414             mov dword ptr [esp + 0x14], esp
// 0068248e  85c0                 test eax, eax
// 00682490  740c                 je 0x68249e
// 00682492  83c004               add eax, 4
// 00682495  ba01000000           mov edx, 1
// 0068249a  f00fc110             lock xadd dword ptr [eax], edx
// 0068249e  8b01                 mov eax, dword ptr [ecx]
// 006824a0  83c108               add ecx, 8
// 006824a3  51                   push ecx
// 006824a4  8b4804               mov ecx, dword ptr [eax + 4]
// 006824a7  ffd1                 call ecx
// 006824a9  8b742458             mov esi, dword ptr [esp + 0x58]
// 006824ad  83c414               add esp, 0x14
// 006824b0  c644243800           mov byte ptr [esp + 0x38], 0
// 006824b5  85f6                 test esi, esi
// 006824b7  742a                 je 0x6824e3
// 006824b9  8d5604               lea edx, [esi + 4]
// 006824bc  83c8ff               or eax, 0xffffffff
// 006824bf  f00fc102             lock xadd dword ptr [edx], eax
// 006824c3  751e                 jne 0x6824e3
// 006824c5  8b16                 mov edx, dword ptr [esi]
// 006824c7  8b4204               mov eax, dword ptr [edx + 4]
// 006824ca  8bce                 mov ecx, esi
// 006824cc  ffd0                 call eax
// 006824ce  8d4e08               lea ecx, [esi + 8]
// 006824d1  83caff               or edx, 0xffffffff
// 006824d4  f00fc111             lock xadd dword ptr [ecx], edx
// 006824d8  7509                 jne 0x6824e3
// 006824da  8b06                 mov eax, dword ptr [esi]
// 006824dc  8b5008               mov edx, dword ptr [eax + 8]
// 006824df  8bce                 mov ecx, esi
// 006824e1  ffd2                 call edx
// 006824e3  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 006824e7  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 006824ef  85f6                 test esi, esi
// 006824f1  742a                 je 0x68251d
// 006824f3  8d4604               lea eax, [esi + 4]
// 006824f6  83c9ff               or ecx, 0xffffffff
// 006824f9  f00fc108             lock xadd dword ptr [eax], ecx
// 006824fd  751e                 jne 0x68251d
// 006824ff  8b16                 mov edx, dword ptr [esi]
// 00682501  8b4204               mov eax, dword ptr [edx + 4]
// 00682504  8bce                 mov ecx, esi
// 00682506  ffd0                 call eax
// 00682508  8d4e08               lea ecx, [esi + 8]
// 0068250b  83caff               or edx, 0xffffffff
// 0068250e  f00fc111             lock xadd dword ptr [ecx], edx
// 00682512  7509                 jne 0x68251d
// 00682514  8b06                 mov eax, dword ptr [esi]
// 00682516  8b5008               mov edx, dword ptr [eax + 8]
// 00682519  8bce                 mov ecx, esi
// 0068251b  ffd2                 call edx
// 0068251d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00682521  64890d00000000       mov dword ptr fs:[0], ecx
// 00682528  5e                   pop esi
// 00682529  83c438               add esp, 0x38
// 0068252c  c21000               ret 0x10
// copied from an identical function in another client (function ??R?$function2@XV?$shared_ptr@VInstance@RBX@@@boost@@V12@@boost@@QBEXV?$shared_ptr@VInstance@RBX@@@1@0@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <stdexcept>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
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
class bad_function_call : public std::runtime_error {
public:
    bad_function_call();
};
template<class E> __declspec(noreturn) void throw_exception(const E& e);
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[16]; };
} }
template<class R, class T0, class T1>
class function2 {
public:
    struct vtable_type {
        void* manager;
        R (*invoker)(detail::function::function_buffer&, T0, T1);
    };
    vtable_type* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
    R operator()(T0 a0, T1 a1) const;
};
template<class R, class T0, class T1>
R function2<R, T0, T1>::operator()(T0 a0, T1 a1) const
{
    if (this->empty())
        boost::throw_exception(bad_function_call());
    return vtable->invoker(this->functor, a0, a1);
}
}
namespace RBX { class Instance; }
template class boost::function2<void, boost::shared_ptr<RBX::Instance>, boost::shared_ptr<RBX::Instance> >;