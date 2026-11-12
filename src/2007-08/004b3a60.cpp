// from server: 100% by EspClaude
// from server: 43% by tester
// roc 2007-08 004b3a60  unit: RBX::Network::VMarker::?$SignalDesc  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b3a60
//
// 004b3a60  6aff                 push -1
// 004b3a62  686e887400           push 0x74886e
// 004b3a67  64a100000000         mov eax, dword ptr fs:[0]
// 004b3a6d  50                   push eax
// 004b3a6e  83ec0c               sub esp, 0xc
// 004b3a71  53                   push ebx
// 004b3a72  56                   push esi
// 004b3a73  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b3a78  33c4                 xor eax, esp
// 004b3a7a  50                   push eax
// 004b3a7b  8d442418             lea eax, [esp + 0x18]
// 004b3a7f  64a300000000         mov dword ptr fs:[0], eax
// 004b3a85  8bf1                 mov esi, ecx
// 004b3a87  89742410             mov dword ptr [esp + 0x10], esi
// 004b3a8b  33db                 xor ebx, ebx
// 004b3a8d  891e                 mov dword ptr [esi], ebx
// 004b3a8f  895e04               mov dword ptr [esi + 4], ebx
// 004b3a92  8b442428             mov eax, dword ptr [esp + 0x28]
// 004b3a96  8b10                 mov edx, dword ptr [eax]
// 004b3a98  53                   push ebx
// 004b3a99  83ec08               sub esp, 8
// 004b3a9c  8bcc                 mov ecx, esp
// 004b3a9e  8911                 mov dword ptr [ecx], edx
// 004b3aa0  8b4004               mov eax, dword ptr [eax + 4]
// 004b3aa3  3bc3                 cmp eax, ebx
// 004b3aa5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004b3aa9  89642420             mov dword ptr [esp + 0x20], esp
// 004b3aad  894104               mov dword ptr [ecx + 4], eax
// 004b3ab0  740c                 je 0x4b3abe
// 004b3ab2  83c004               add eax, 4
// 004b3ab5  b901000000           mov ecx, 1
// 004b3aba  f00fc108             lock xadd dword ptr [eax], ecx
// 004b3abe  8d4e08               lea ecx, [esi + 8]
// 004b3ac1  e86af5ffff           call 0x4b3030
// 004b3ac6  6a20                 push 0x20
// 004b3ac8  c644242401           mov byte ptr [esp + 0x24], 1
// 004b3acd  e824c41700           call 0x62fef6
// 004b3ad2  83c404               add esp, 4
// 004b3ad5  3bc3                 cmp eax, ebx
// 004b3ad7  7414                 je 0x4b3aed
// 004b3ad9  895804               mov dword ptr [eax + 4], ebx
// 004b3adc  895808               mov dword ptr [eax + 8], ebx
// 004b3adf  89580c               mov dword ptr [eax + 0xc], ebx
// 004b3ae2  895814               mov dword ptr [eax + 0x14], ebx
// 004b3ae5  895818               mov dword ptr [eax + 0x18], ebx
// 004b3ae8  88581c               mov byte ptr [eax + 0x1c], bl
// 004b3aeb  eb02                 jmp 0x4b3aef
// 004b3aed  33c0                 xor eax, eax
// 004b3aef  50                   push eax
// 004b3af0  8bce                 mov ecx, esi
// 004b3af2  c644242401           mov byte ptr [esp + 0x24], 1
// 004b3af7  e8b446f6ff           call 0x4181b0
// 004b3afc  8bce                 mov ecx, esi
// 004b3afe  e82d4d2700           call 0x728830
// 004b3b03  8bc6                 mov eax, esi
// 004b3b05  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b3b09  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3b10  59                   pop ecx
// 004b3b11  5e                   pop esi
// 004b3b12  5b                   pop ebx
// 004b3b13  83c418               add esp, 0x18

#include <vector>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

// sp_counted_base: use count at +4 (lock xadd [pn+4], 1 above).
struct sp_counted_base {
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void add_ref_copy() { _InterlockedIncrement(&use_count); }
};

struct Desc;

struct DescPtr {
    Desc* px;
    sp_counted_base* pn;
    DescPtr(const DescPtr& r) : px(r.px), pn(r.pn)
    {
        if (pn != 0)
            pn->add_ref_copy();
    }
    ~DescPtr();
};

// 0x20-byte object (operator new(0x20)); members cleared by the inline ctor.
struct Impl {
    std::vector<int> m00;   // VS2005 vector: allocator, _Myfirst +4, _Mylast +8, _Myend +0xc
    int m10;
    int m14;
    int m18;
    bool m1c;
    Impl() : m14(0), m18(0), m1c(false) {}
};

struct ImplPtr {
    Impl* px;
    sp_counted_base* pn;
    ImplPtr() : px(0), pn(0) {}
    ~ImplPtr();
    void reset(Impl* p);      // 0x4181b0
};

struct Member8 {
    Member8(DescPtr d, int flags);   // 0x4b3030
    ~Member8();
};

struct SignalDesc {
    ImplPtr impl;     // +0
    Member8 m8;       // +8
    SignalDesc(const DescPtr& d);
    void init();      // 0x728830
};

SignalDesc::SignalDesc(const DescPtr& d) : m8(d, 0)
{
    impl.reset(new Impl);
    init();
}
