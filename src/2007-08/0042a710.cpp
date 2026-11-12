// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0042a710  unit: CLuaHtmlView  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a710
//
// 0042a710  6aff                 push -1
// 0042a712  6833cf7300           push 0x73cf33
// 0042a717  64a100000000         mov eax, dword ptr fs:[0]
// 0042a71d  50                   push eax
// 0042a71e  51                   push ecx
// 0042a71f  56                   push esi
// 0042a720  57                   push edi
// 0042a721  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042a726  33c4                 xor eax, esp
// 0042a728  50                   push eax
// 0042a729  8d442410             lea eax, [esp + 0x10]
// 0042a72d  64a300000000         mov dword ptr fs:[0], eax
// 0042a733  8bf1                 mov esi, ecx
// 0042a735  8974240c             mov dword ptr [esp + 0xc], esi
// 0042a739  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042a73d  8b07                 mov eax, dword ptr [edi]
// 0042a73f  6a00                 push 0
// 0042a741  68a0658800           push 0x8865a0
// 0042a746  684c1f8800           push 0x881f4c
// 0042a74b  6a00                 push 0
// 0042a74d  50                   push eax
// 0042a74e  e8e3652000           call 0x630d36
// 0042a753  8906                 mov dword ptr [esi], eax
// 0042a755  8b4704               mov eax, dword ptr [edi + 4]
// 0042a758  83c414               add esp, 0x14
// 0042a75b  85c0                 test eax, eax
// 0042a75d  8d4e04               lea ecx, [esi + 4]
// 0042a760  8901                 mov dword ptr [ecx], eax
// 0042a762  740c                 je 0x42a770
// 0042a764  83c004               add eax, 4
// 0042a767  ba01000000           mov edx, 1
// 0042a76c  f00fc110             lock xadd dword ptr [eax], edx
// 0042a770  833e00               cmp dword ptr [esi], 0
// 0042a773  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0042a77b  7517                 jne 0x42a794
// 0042a77d  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0042a785  8d442420             lea eax, [esp + 0x20]
// 0042a789  50                   push eax
// 0042a78a  c644241c01           mov byte ptr [esp + 0x1c], 1
// 0042a78f  e8cc82fdff           call 0x402a60
// 0042a794  8bc6                 mov eax, esi
// 0042a796  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042a79a  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a7a1  59                   pop ecx
// 0042a7a2  5f                   pop edi
// 0042a7a3  5e                   pop esi
// 0042a7a4  83c410               add esp, 0x10
// 0042a7a7  c20800               ret 8

extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r)
    {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) {
            if (tmp != 0) tmp->add_ref_copy();
            if (pi_ != 0) pi_->release();
            pi_ = tmp;
        }
        return *this;
    }
};

struct dynamic_cast_tag {};

namespace RBX {
class Instance { public: virtual ~Instance(); };
class DataModel : public Instance { };
}

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r, dynamic_cast_tag)
        : px(dynamic_cast<T*>(r.px)), pn(r.pn)
    {
        if (px == 0)
            pn = shared_count();
    }
};

template shared_ptr<RBX::DataModel>::shared_ptr(shared_ptr<RBX::Instance> const&, dynamic_cast_tag);
