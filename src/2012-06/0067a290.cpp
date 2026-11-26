// from server: 100% by Xemicl
// roc 2012-06 0067a290  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067a290
//
// 0067a290  6aff                 push -1
// 0067a292  6808c8ac00           push 0xacc808
// 0067a297  64a100000000         mov eax, dword ptr fs:[0]
// 0067a29d  50                   push eax
// 0067a29e  64892500000000       mov dword ptr fs:[0], esp
// 0067a2a5  83ec0c               sub esp, 0xc
// 0067a2a8  8d442404             lea eax, [esp + 4]
// 0067a2ac  56                   push esi
// 0067a2ad  50                   push eax
// 0067a2ae  e82d1cdcff           call 0x43bee0
// 0067a2b3  8b00                 mov eax, dword ptr [eax]
// 0067a2b5  8b5040               mov edx, dword ptr [eax + 0x40]
// 0067a2b8  8d4c2408             lea ecx, [esp + 8]
// 0067a2bc  51                   push ecx
// 0067a2bd  52                   push edx
// 0067a2be  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0067a2c6  e8d5a32f00           call 0x9746a0
// 0067a2cb  8b742418             mov esi, dword ptr [esp + 0x18]
// 0067a2cf  83c40c               add esp, 0xc
// 0067a2d2  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0067a2da  85f6                 test esi, esi
// 0067a2dc  742a                 je 0x67a308
// 0067a2de  8d4604               lea eax, [esi + 4]
// 0067a2e1  83c9ff               or ecx, 0xffffffff
// 0067a2e4  f00fc108             lock xadd dword ptr [eax], ecx
// 0067a2e8  751e                 jne 0x67a308
// 0067a2ea  8b16                 mov edx, dword ptr [esi]
// 0067a2ec  8b4204               mov eax, dword ptr [edx + 4]
// 0067a2ef  8bce                 mov ecx, esi
// 0067a2f1  ffd0                 call eax
// 0067a2f3  8d4e08               lea ecx, [esi + 8]
// 0067a2f6  83caff               or edx, 0xffffffff
// 0067a2f9  f00fc111             lock xadd dword ptr [ecx], edx
// 0067a2fd  7509                 jne 0x67a308
// 0067a2ff  8b06                 mov eax, dword ptr [esi]
// 0067a301  8b5008               mov edx, dword ptr [eax + 8]
// 0067a304  8bce                 mov ecx, esi
// 0067a306  ffd2                 call edx
// 0067a308  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067a30c  8b442404             mov eax, dword ptr [esp + 4]
// 0067a310  5e                   pop esi
// 0067a311  64890d00000000       mov dword ptr fs:[0], ecx
// 0067a318  83c418               add esp, 0x18
// 0067a31b  c3                   ret 
// copied from an identical function in another client (function ?getTotalProcessorTime@Stats@RBX@@QBEJXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
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
    T* operator->() const { return px; }
    T* px;
    detail::shared_count pn;
};
}
typedef void* PDH_HCOUNTER;
namespace RBX {
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class PerfCountersImpl {
public:
    char pad[0x30];
    PDH_HCOUNTER totalProcessorTime;
    PDH_HCOUNTER processorTime;
    char pad2[0x40 - 0x38];
    PDH_HCOUNTER pageFileBytes;
    PDH_HCOUNTER virtualBytes;
    PDH_HCOUNTER privateWorkingSetBytes;
};
boost::shared_ptr<PerfCountersImpl> getPerfCounters();
void getCounterValue(PDH_HCOUNTER counter, long& value);
class Stats : public ExeBaseA, public ExeBaseB {
public:
    long getTotalProcessorTime() const;
};
long Stats::getTotalProcessorTime() const
{
    long value;
    getCounterValue(getPerfCounters()->pageFileBytes, value);
    return value;
}
}