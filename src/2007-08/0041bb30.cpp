// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 0041bb30  unit: VDHTMLWindow::?$SignalDesc  size: 550 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041bb30
//
// 0041bb30  6aff                 push -1
// 0041bb32  68fab37300           push 0x73b3fa
// 0041bb37  64a100000000         mov eax, dword ptr fs:[0]
// 0041bb3d  50                   push eax
// 0041bb3e  83ec28               sub esp, 0x28
// 0041bb41  53                   push ebx
// 0041bb42  55                   push ebp
// 0041bb43  56                   push esi
// 0041bb44  57                   push edi
// 0041bb45  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041bb4a  33c4                 xor eax, esp
// 0041bb4c  50                   push eax
// 0041bb4d  8d44243c             lea eax, [esp + 0x3c]
// 0041bb51  64a300000000         mov dword ptr fs:[0], eax
// 0041bb57  8bd9                 mov ebx, ecx
// 0041bb59  8d44241c             lea eax, [esp + 0x1c]
// 0041bb5d  33ed                 xor ebp, ebp
// 0041bb5f  50                   push eax
// 0041bb60  896c2448             mov dword ptr [esp + 0x48], ebp
// 0041bb64  e8b7bd0000           call 0x427920
// 0041bb69  8bc8                 mov ecx, eax
// 0041bb6b  e890e20000           call 0x429e00
// 0041bb70  8b03                 mov eax, dword ptr [ebx]
// 0041bb72  83c014               add eax, 0x14
// 0041bb75  8bc8                 mov ecx, eax
// 0041bb77  c644244401           mov byte ptr [esp + 0x44], 1
// 0041bb7c  89442430             mov dword ptr [esp + 0x30], eax
// 0041bb80  e8cb9b3000           call 0x725750
// 0041bb85  c644243401           mov byte ptr [esp + 0x34], 1
// 0041bb8a  8b03                 mov eax, dword ptr [ebx]
// 0041bb8c  8d4c244c             lea ecx, [esp + 0x4c]
// 0041bb90  51                   push ecx
// 0041bb91  8d481c               lea ecx, [eax + 0x1c]
// 0041bb94  c644244802           mov byte ptr [esp + 0x48], 2
// 0041bb99  ff1590e67700         call dword ptr [0x77e690]
// 0041bb9f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041bba3  3bfd                 cmp edi, ebp
// 0041bba5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041bba9  7504                 jne 0x41bbaf
// 0041bbab  33c0                 xor eax, eax
// 0041bbad  eb17                 jmp 0x41bbc6
// 0041bbaf  8bf1                 mov esi, ecx
// 0041bbb1  2bf7                 sub esi, edi
// 0041bbb3  b893244992           mov eax, 0x92492493
// 0041bbb8  f7ee                 imul esi
// 0041bbba  03d6                 add edx, esi
// 0041bbbc  c1fa04               sar edx, 4
// 0041bbbf  8bc2                 mov eax, edx
// 0041bbc1  c1e81f               shr eax, 0x1f
// 0041bbc4  03c2                 add eax, edx
// 0041bbc6  83c0f4               add eax, -0xc
// 0041bbc9  89442414             mov dword ptr [esp + 0x14], eax
// 0041bbcd  3bc5                 cmp eax, ebp
// 0041bbcf  896c2418             mov dword ptr [esp + 0x18], ebp
// 0041bbd3  8d442414             lea eax, [esp + 0x14]
// 0041bbd7  7f04                 jg 0x41bbdd
// 0041bbd9  8d442418             lea eax, [esp + 0x18]
// 0041bbdd  8b28                 mov ebp, dword ptr [eax]
// 0041bbdf  8d04ed00000000       lea eax, [ebp*8]
// 0041bbe6  2bc5                 sub eax, ebp
// 0041bbe8  03c0                 add eax, eax
// 0041bbea  03c0                 add eax, eax
// 0041bbec  89442414             mov dword ptr [esp + 0x14], eax
// 0041bbf0  85ff                 test edi, edi
// 0041bbf2  0f84a5000000         je 0x41bc9d
// 0041bbf8  2bcf                 sub ecx, edi
// 0041bbfa  b893244992           mov eax, 0x92492493
// 0041bbff  f7e9                 imul ecx
// 0041bc01  03d1                 add edx, ecx
// 0041bc03  c1fa04               sar edx, 4
// 0041bc06  8bc2                 mov eax, edx
// 0041bc08  c1e81f               shr eax, 0x1f
// 0041bc0b  03c2                 add eax, edx
// 0041bc0d  3be8                 cmp ebp, eax
// 0041bc0f  0f8388000000         jae 0x41bc9d
// 0041bc15  8b33                 mov esi, dword ptr [ebx]
// 0041bc17  8b4610               mov eax, dword ptr [esi + 0x10]
// 0041bc1a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041bc1e  03d7                 add edx, edi
// 0041bc20  83c001               add eax, 1
// 0041bc23  394608               cmp dword ptr [esi + 8], eax
// 0041bc26  89542418             mov dword ptr [esp + 0x18], edx
// 0041bc2a  7709                 ja 0x41bc35
// 0041bc2c  6a01                 push 1
// 0041bc2e  8bce                 mov ecx, esi
// 0041bc30  e89bfaffff           call 0x41b6d0
// 0041bc35  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0041bc38  037e10               add edi, dword ptr [esi + 0x10]
// 0041bc3b  8b4608               mov eax, dword ptr [esi + 8]
// 0041bc3e  3bc7                 cmp eax, edi
// 0041bc40  7702                 ja 0x41bc44
// 0041bc42  2bf8                 sub edi, eax
// 0041bc44  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041bc47  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0041bc4b  7510                 jne 0x41bc5d
// 0041bc4d  6a1c                 push 0x1c
// 0041bc4f  e8a2422100           call 0x62fef6
// 0041bc54  8b5604               mov edx, dword ptr [esi + 4]
// 0041bc57  83c404               add esp, 4
// 0041bc5a  8904ba               mov dword ptr [edx + edi*4], eax
// 0041bc5d  8b4604               mov eax, dword ptr [esi + 4]
// 0041bc60  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0041bc63  894c2438             mov dword ptr [esp + 0x38], ecx
// 0041bc67  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0041bc6b  85c9                 test ecx, ecx
// 0041bc6d  c644244403           mov byte ptr [esp + 0x44], 3
// 0041bc72  740b                 je 0x41bc7f
// 0041bc74  8b542418             mov edx, dword ptr [esp + 0x18]
// 0041bc78  52                   push edx
// 0041bc79  ff159ce67700         call dword ptr [0x77e69c]
// 0041bc7f  83461001             add dword ptr [esi + 0x10], 1
// 0041bc83  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041bc87  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041bc8b  83c501               add ebp, 1
// 0041bc8e  834424141c           add dword ptr [esp + 0x14], 0x1c
// 0041bc93  c644244402           mov byte ptr [esp + 0x44], 2
// 0041bc98  e953ffffff           jmp 0x41bbf0
// 0041bc9d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0041bca1  c644244401           mov byte ptr [esp + 0x44], 1
// 0041bca6  e8c59a3000           call 0x725770
// 0041bcab  807c246800           cmp byte ptr [esp + 0x68], 0
// 0041bcb0  750e                 jne 0x41bcc0
// 0041bcb2  8d4b08               lea ecx, [ebx + 8]
// 0041bcb5  e846581500           call 0x571500
// 0041bcba  eb33                 jmp 0x41bcef
// 0041bcbc  8d642400             lea esp, [esp]
// 0041bcc0  8b03                 mov eax, dword ptr [ebx]
// 0041bcc2  83ec08               sub esp, 8
// 0041bcc5  8bcc                 mov ecx, esp
// 0041bcc7  8901                 mov dword ptr [ecx], eax
// 0041bcc9  8b4304               mov eax, dword ptr [ebx + 4]
// 0041bccc  85c0                 test eax, eax
// 0041bcce  89642434             mov dword ptr [esp + 0x34], esp
// 0041bcd2  894104               mov dword ptr [ecx + 4], eax
// 0041bcd5  740c                 je 0x41bce3
// 0041bcd7  83c004               add eax, 4
// 0041bcda  b901000000           mov ecx, 1
// 0041bcdf  f00fc108             lock xadd dword ptr [eax], ecx
// 0041bce3  e848fbffff           call 0x41b830
// 0041bce8  83c408               add esp, 8
// 0041bceb  85c0                 test eax, eax
// 0041bced  75d1                 jne 0x41bcc0
// 0041bcef  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041bcf3  33db                 xor ebx, ebx
// 0041bcf5  3bf3                 cmp esi, ebx
// 0041bcf7  c644244400           mov byte ptr [esp + 0x44], 0
// 0041bcfc  7424                 je 0x41bd22
// 0041bcfe  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0041bd02  3bf7                 cmp esi, edi
// 0041bd04  7413                 je 0x41bd19
// 0041bd06  8bce                 mov ecx, esi
// 0041bd08  ff15ace67700         call dword ptr [0x77e6ac]
// 0041bd0e  83c61c               add esi, 0x1c
// 0041bd11  3bf7                 cmp esi, edi
// 0041bd13  75f1                 jne 0x41bd06
// 0041bd15  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041bd19  56                   push esi
// 0041bd1a  e8433f2100           call 0x62fc62
// 0041bd1f  83c404               add esp, 4
// 0041bd22  8d4c244c             lea ecx, [esp + 0x4c]
// 0041bd26  895c2420             mov dword ptr [esp + 0x20], ebx
// 0041bd2a  895c2424             mov dword ptr [esp + 0x24], ebx
// 0041bd2e  895c2428             mov dword ptr [esp + 0x28], ebx
// 0041bd32  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 0041bd3a  ff15ace67700         call dword ptr [0x77e6ac]
// 0041bd40  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0041bd44  64890d00000000       mov dword ptr fs:[0], ecx
// 0041bd4b  59                   pop ecx
// 0041bd4c  5f                   pop edi
// 0041bd4d  5e                   pop esi
// 0041bd4e  5d                   pop ebp
// 0041bd4f  5b                   pop ebx
// 0041bd50  83c434               add esp, 0x34
// 0041bd53  c22000               ret 0x20

// Frame: by-value std::string (0x1c, [esp+0x4c]..) + bool ([esp+0x68]) => ret 0x20;
// EH state 0 = that by-value string; dtor via imported basic_string dtor.
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement)

namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;      // +4 (lock xadd [pi+4])
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release();
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    T* operator->() const { return px; }
};

// mutex at Q+0x14; do_lock 0x725750 / do_unlock 0x725770 (thiscall, no args);
// scoped_lock = { mutex&, bool } at [esp+0x30]/[esp+0x34].
class mutex {
    void* m_mutex;
    bool m_critical_section;
public:
    void do_lock();
    void do_unlock();
    class scoped_lock {
        mutex& m_mutex;
        bool m_locked;
    public:
        explicit scoped_lock(mutex& m) : m_mutex(m), m_locked(false) { lock(); }
        ~scoped_lock() { if (m_locked) unlock(); }
        void lock() { m_mutex.do_lock(); m_locked = true; }
        void unlock() { m_mutex.do_unlock(); m_locked = false; }
    };
};
}

// Shared queue: deque<string> at +0 (map +4, mapsize +8, off +0xc, size +0x10),
// mutex at +0x14, string at +0x1c (assigned via imported operator=).
struct SignalQueue {
    std::deque<std::string> queue;
    boost::mutex mutex;
    std::string value;
};

struct ListSource {
    static ListSource* get();                    // 0x427920 (no args, ret in eax)
    std::vector<std::string> list();             // 0x429e00 thiscall, hidden return
};

struct Other {
    void fire();                                 // 0x571500 thiscall on this+8
};

int processQueue(boost::shared_ptr<SignalQueue> q);   // 0x41b830 cdecl, 8-byte arg

struct SignalDesc {
    boost::shared_ptr<SignalQueue> queue;        // +0
    Other other;                                 // +8
    void fire(std::string value, bool async);
};

void SignalDesc::fire(std::string value, bool async)
{
    std::vector<std::string> items = ListSource::get()->list();
    {
        boost::mutex::scoped_lock lock(queue->mutex);
        queue->value = value;
        for (int i = std::max(0, (int)items.size() - 12); i < items.size(); ++i)
            queue->queue.push_back(items[i]);
    }
    if (!async)
        other.fire();
    else
        while (processQueue(queue))
            ;
}
