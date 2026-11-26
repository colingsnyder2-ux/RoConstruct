// from server: 100% by Xemicl
// roc 2012-06 0052ece0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0052ece0
//
// 0052ece0  6aff                 push -1
// 0052ece2  6831b9aa00           push 0xaab931
// 0052ece7  64a100000000         mov eax, dword ptr fs:[0]
// 0052eced  50                   push eax
// 0052ecee  64892500000000       mov dword ptr fs:[0], esp
// 0052ecf5  83ec0c               sub esp, 0xc
// 0052ecf8  56                   push esi
// 0052ecf9  57                   push edi
// 0052ecfa  c744240800000000     mov dword ptr [esp + 8], 0
// 0052ed02  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0052ed06  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0052ed0a  8b542430             mov edx, dword ptr [esp + 0x30]
// 0052ed0e  50                   push eax
// 0052ed0f  51                   push ecx
// 0052ed10  83ec08               sub esp, 8
// 0052ed13  8bc4                 mov eax, esp
// 0052ed15  8964241c             mov dword ptr [esp + 0x1c], esp
// 0052ed19  8910                 mov dword ptr [eax], edx
// 0052ed1b  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0052ed1f  894804               mov dword ptr [eax + 4], ecx
// 0052ed22  8b442444             mov eax, dword ptr [esp + 0x44]
// 0052ed26  be01000000           mov esi, 1
// 0052ed2b  8974242c             mov dword ptr [esp + 0x2c], esi
// 0052ed2f  85c0                 test eax, eax
// 0052ed31  7409                 je 0x52ed3c
// 0052ed33  83c004               add eax, 4
// 0052ed36  8bd6                 mov edx, esi
// 0052ed38  f00fc110             lock xadd dword ptr [eax], edx
// 0052ed3c  8d4c241c             lea ecx, [esp + 0x1c]
// 0052ed40  e8bbe5ffff           call 0x52d300
// 0052ed45  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0052ed49  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0052ed4d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0052ed51  890f                 mov dword ptr [edi], ecx
// 0052ed53  895704               mov dword ptr [edi + 4], edx
// 0052ed56  8b08                 mov ecx, dword ptr [eax]
// 0052ed58  894f08               mov dword ptr [edi + 8], ecx
// 0052ed5b  8b4004               mov eax, dword ptr [eax + 4]
// 0052ed5e  89470c               mov dword ptr [edi + 0xc], eax
// 0052ed61  85c0                 test eax, eax
// 0052ed63  7409                 je 0x52ed6e
// 0052ed65  83c004               add eax, 4
// 0052ed68  8bd6                 mov edx, esi
// 0052ed6a  f00fc110             lock xadd dword ptr [eax], edx
// 0052ed6e  89742408             mov dword ptr [esp + 8], esi
// 0052ed72  8b742410             mov esi, dword ptr [esp + 0x10]
// 0052ed76  85f6                 test esi, esi
// 0052ed78  742a                 je 0x52eda4
// 0052ed7a  8d4604               lea eax, [esi + 4]
// 0052ed7d  83c9ff               or ecx, 0xffffffff
// 0052ed80  f00fc108             lock xadd dword ptr [eax], ecx
// 0052ed84  751e                 jne 0x52eda4
// 0052ed86  8b16                 mov edx, dword ptr [esi]
// 0052ed88  8b4204               mov eax, dword ptr [edx + 4]
// 0052ed8b  8bce                 mov ecx, esi
// 0052ed8d  ffd0                 call eax
// 0052ed8f  8d4e08               lea ecx, [esi + 8]
// 0052ed92  83caff               or edx, 0xffffffff
// 0052ed95  f00fc111             lock xadd dword ptr [ecx], edx
// 0052ed99  7509                 jne 0x52eda4
// 0052ed9b  8b06                 mov eax, dword ptr [esi]
// 0052ed9d  8b5008               mov edx, dword ptr [eax + 8]
// 0052eda0  8bce                 mov ecx, esi
// 0052eda2  ffd2                 call edx
// 0052eda4  8b742434             mov esi, dword ptr [esp + 0x34]
// 0052eda8  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0052edad  85f6                 test esi, esi
// 0052edaf  742a                 je 0x52eddb
// 0052edb1  8d4604               lea eax, [esi + 4]
// 0052edb4  83c9ff               or ecx, 0xffffffff
// 0052edb7  f00fc108             lock xadd dword ptr [eax], ecx
// 0052edbb  751e                 jne 0x52eddb
// 0052edbd  8b16                 mov edx, dword ptr [esi]
// 0052edbf  8b4204               mov eax, dword ptr [edx + 4]
// 0052edc2  8bce                 mov ecx, esi
// 0052edc4  ffd0                 call eax
// 0052edc6  8d4e08               lea ecx, [esi + 8]
// 0052edc9  83caff               or edx, 0xffffffff
// 0052edcc  f00fc111             lock xadd dword ptr [ecx], edx
// 0052edd0  7509                 jne 0x52eddb
// 0052edd2  8b06                 mov eax, dword ptr [esi]
// 0052edd4  8b5008               mov edx, dword ptr [eax + 8]
// 0052edd7  8bce                 mov ecx, esi
// 0052edd9  ffd2                 call edx
// 0052eddb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0052eddf  8bc7                 mov eax, edi
// 0052ede1  5f                   pop edi
// 0052ede2  64890d00000000       mov dword ptr fs:[0], ecx
// 0052ede9  5e                   pop esi
// 0052edea  83c418               add esp, 0x18
// 0052eded  c3                   ret 
// copied from an identical function in another client (function ?make@@YA?AUR@@HHV?$shared_ptr@UX@@@boost@@U?$arg@$00@@U?$arg@$01@@@Z)

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
struct X;
template<int I> struct arg {};
struct Local {
    boost::shared_ptr<X> sp;
    Local(boost::shared_ptr<X> sp, arg<1> c, arg<2> d);
};
struct R {
    int a;
    int b;
    Local l;
    R(int a_, int b_, const Local& l_) : a(a_), b(b_), l(l_) {}
};
R make(int a, int b, boost::shared_ptr<X> sp, arg<1> c, arg<2> d)
{
    return R(a, b, Local(sp, c, d));
}